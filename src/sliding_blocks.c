#include "global.h"
#include "gflib.h"
#include "decompress.h"
#include "task.h"
#include "coins.h"
#include "quest_log.h"
#include "overworld.h"
#include "menu.h"
#include "new_menu_helpers.h"
#include "text_window.h"
#include "random.h"
#include "trig.h"
#include "strings.h"
#include "event_data.h"
#include "constants/songs.h"

#define SLIDINGTASK_GFX_INIT        0
#define SLIDINGTASK_FADEOUT_EXIT    1
#define SLIDINGTASK_ASK_QUIT        2
#define SLIDINGTASK_DESTROY_YESNO   3
#define SLIDINGTASK_VICTORY_MESSAGE 4

#define INDEX_X 0
#define INDEX_Y 1

#define SPRITEANIM_ARROWS_CONVERGE 0

#define SLIDING_NUM_BLOCKS 16
#define ARROWS_NUM_TILES 16


enum SlidingMove {
    SLIDINGMOVE_NONE = 0,
    SLIDINGMOVE_UP,
    SLIDINGMOVE_DOWN,
    SLIDINGMOVE_LEFT,
    SLIDINGMOVE_RIGHT
};

struct SlidingBlocksState
{
    MainCallback savedCallback;
    u16 machineidx;
    u8 taskId;
    u16 blocksInitialLayout[4][4];
    u16 blocksCurrentLayout[4][4];
    u16 hollowIndex[2];
    bool32 isSliding;
    enum SlidingMove currentMove;
};

struct SlidingBlocksGfxManager
{
    struct Sprite *blocksSprites[SLIDING_NUM_BLOCKS];
    struct Sprite *arrowsSprite;
    u32 hollowSpriteIndex;
};

struct SlidingBlocksSetupTaskDataSub_0000
{
    u16 funcno;
    u8 state;
    bool8 active;
};

struct SlidingBlocksSetupTaskData
{
    struct SlidingBlocksSetupTaskDataSub_0000 tasks[8];
    u8 reelButtonToPress;
    // align 2
    s32 bg1X;
    bool32 yesNoMenuActive;
    u16 buttonPressedTiles[3][4];
    u16 buttonReleasedTiles[3][4];
    u8 bg0TilemapBuffer[0x800];
    u8 bg1TilemapBuffer[0x800];
    u8 bg2TilemapBuffer[0x800];
    u8 bg3TilemapBuffer[0x800];
}; // size: 285C

struct LineStateTileIdxList
{
    const u16 * tiles;
    u32 count;
};

static EWRAM_DATA struct SlidingBlocksState * sSlidingBlocksState = NULL;
static EWRAM_DATA struct SlidingBlocksGfxManager * sSlidingBlocksGfxManager = NULL;

static void InitSlidingBlocksState(struct SlidingBlocksState *ptr, const u16 initialLayout[4][4]);
static void CB2_InitSlidingBlocks(void);
static void CleanSupSlidingBlocksState(void);
static void CB2_RunSlidingBlocks(void);
static void MainTask_SlidingBlocksGameLoop(u8 taskId);
static void MainTask_ShowHelp(u8 taskId);
static void MainTask_ConfirmExitGame(u8 taskId);
static void MainTask_ExitSlidingBlocks(u8 taskId);
static void MainTask_VictorySequence(u8 taskId);
static void ProcessMove(enum SlidingMove move);
static bool32 IsSlidingLayoutSolved(u16 layout[4][4]);
static void MainTask_SlideBlock(u8 taskId);
static void MainTask_Bump(u8 taskId);
static void SetMainTask(TaskFunc taskFunc);
static void InitGfxManager(struct SlidingBlocksGfxManager * manager);
static bool32 CreateSlidingBlocks(void);
static void DestroySlidingBlocks(void);
static struct SlidingBlocksSetupTaskData * GetSlidingBlocksSetupTaskDataPtr(void);
static void Task_SlidingBlocks(u8 taskId);
static void SetSlidingBlocksSetupTask(u16 funcno, u8 taskId);
static void SetArrowsSpritePosition(s16 x, s16 y);
static void SetArrowsSpriteVisible(bool32 isVisible);
static bool32 IsSlidingBlocksSetupTaskActive(u8 taskId);
static bool8 SlidingTask_GraphicsInit(u8 *state, struct SlidingBlocksSetupTaskData * ptr);
static bool8 SlidingTask_FadeOut(u8 *state, struct SlidingBlocksSetupTaskData * ptr);
static bool8 SlidingTask_AskQuitPlaying(u8 *state, struct SlidingBlocksSetupTaskData * ptr);
static bool8 SlidingTask_DestroyYesNoMenu(u8 *state, struct SlidingBlocksSetupTaskData * ptr);
static bool8 SlidingTask_VictoryMessage(u8 *state, struct SlidingBlocksSetupTaskData *ptr);
static void SlidingBlocks_PrintOnWindow0(const u8 * str);
static void SlidingBlocks_ClearWindow0(void);
static void SlidingBlocks_CreateYesNoMenu(u8 cursorPos);
static void SlidingBlocks_DestroyYesNoMenu(void);

static const u8 sString_SlidingBlocksControls[] = _("{DPAD_ANY}Move {START_BUTTON}Reset {B_BUTTON}Give up");
static const u8 sString_GiveUpPuzzle[] = _("Give up on this puzzle?");
static const u8 gString_ResetPuzzle[] = _("Do you want to start over?");
static const u8 sString_PuzzleSolved[] = _("Congratulations!\nYou solved the puzzle!");

static const u16 sProtoLayout[4][4] = {
    {0x1, 0x3, 0xE, 0x6},
    {0x9, 0x0, 0x4, 0x2},
    {0x7, 0xC, 0xB, 0xF},
    {0xD, 0x5, 0xA, 0x8}
};

static const u16 sBabyDifficultyLayout[4][4] = {
    {0x1, 0x5, 0x2, 0x3},
    {0x4, 0x0, 0x6, 0x7},
    {0x8, 0x9, 0xA, 0xB},
    {0xC, 0xD, 0xE, 0xF}
};

static const u16 sSpritePal_Blocks[] = INCBIN_U16("graphics/sliding_blocks/puzzle.gbapal");
static const u32 sSpriteTiles_Blocks[] = INCBIN_U32("graphics/sliding_blocks/puzzle_ho_oh.4bpp.lz");
static const u32 sSpriteTiles_Arrows[] = INCBIN_U32("graphics/sliding_blocks/arrows.4bpp.lz");

static const struct CompressedSpriteSheet sSpriteSheets[] = {
    {(const void *)sSpriteTiles_Blocks,  0x2000, 0},
    {(const void *)sSpriteTiles_Arrows,  0x2A00, 1},
};

static const struct SpritePalette sSpritePalettes[] = {
    {sSpritePal_Blocks, 0},
    {NULL}
};

static const u8 sReelIconBldY[] = {
    0x10, 0x10, 0x10, 0x10, 0x0f, 0x0e, 0x0d, 0x0d, 0x0c, 0x0b, 0x0a, 0x0a, 0x09, 0x08, 0x07, 0x07, 0x06, 0x05, 0x04, 0x04, 0x03, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x03, 0x04, 0x05, 0x06, 0x06, 0x07, 0x08, 0x09, 0x09, 0x0a, 0x0b, 0x0c, 0x0c, 0x0d, 0x0e, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f
};

static const struct OamData sOamData_Blocks = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_Arrows = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sAnimCmd_Arrows_Converge[] = {
    ANIMCMD_FRAME(14 * ARROWS_NUM_TILES, 30),
    ANIMCMD_FRAME(13 * ARROWS_NUM_TILES,  1),
    ANIMCMD_FRAME(12 * ARROWS_NUM_TILES,  1),
    ANIMCMD_FRAME(11 * ARROWS_NUM_TILES,  1),
    ANIMCMD_FRAME(10 * ARROWS_NUM_TILES,  1),
    ANIMCMD_FRAME( 9 * ARROWS_NUM_TILES,  1),
    ANIMCMD_FRAME( 8 * ARROWS_NUM_TILES,  1),
    ANIMCMD_FRAME( 7 * ARROWS_NUM_TILES,  1),
    ANIMCMD_FRAME( 6 * ARROWS_NUM_TILES,  1),
    ANIMCMD_FRAME( 5 * ARROWS_NUM_TILES,  1),
    ANIMCMD_FRAME( 4 * ARROWS_NUM_TILES,  1),
    ANIMCMD_FRAME( 3 * ARROWS_NUM_TILES,  1),
    ANIMCMD_FRAME( 2 * ARROWS_NUM_TILES,  1),
    ANIMCMD_FRAME( 1 * ARROWS_NUM_TILES,  1),
    ANIMCMD_FRAME( 0 * ARROWS_NUM_TILES, 17),
    ANIMCMD_FRAME( 0 * ARROWS_NUM_TILES, 30),
    ANIMCMD_FRAME( 0 * ARROWS_NUM_TILES, 30),
    ANIMCMD_JUMP(0)
    // 120 frames in total
};

static const union AnimCmd *const sAnimTable_Arrows[] = {
    [SPRITEANIM_ARROWS_CONVERGE] = sAnimCmd_Arrows_Converge
};

static const struct SpriteTemplate sSpriteTemplate_Blocks = {
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &sOamData_Blocks,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_Arrows = {
    .tileTag = 1,
    .paletteTag = 0,
    .oam = &sOamData_Arrows,
    .anims = sAnimTable_Arrows,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

bool8 (*const sSlidingBlocksSetupTasks[])(u8 *, struct SlidingBlocksSetupTaskData *) = {
    [SLIDINGTASK_GFX_INIT] = SlidingTask_GraphicsInit,
    [SLIDINGTASK_FADEOUT_EXIT] = SlidingTask_FadeOut,
    [SLIDINGTASK_ASK_QUIT] = SlidingTask_AskQuitPlaying,
    [SLIDINGTASK_DESTROY_YESNO] = SlidingTask_DestroyYesNoMenu,
    [SLIDINGTASK_VICTORY_MESSAGE] = SlidingTask_VictoryMessage
};

static const u16 sBgWallPal[] = INCBIN_U16("graphics/sliding_blocks/bg.gbapal");
static const u32 sBgWallTiles[] = INCBIN_U32("graphics/sliding_blocks/bg_wall.4bpp.lz");
static const u32 sBgWallMap[] = INCBIN_U32("graphics/sliding_blocks/bg_wall_tilemap.bin.lz");
/*
#if defined(FIRERED)
static const u16 sBgPal_50[] = INCBIN_U16("graphics/slot_machine/unk_84664bc.gbapal");
#elif defined(LEAFGREEN)
static const u16 sBgPal_50[] = INCBIN_U16("graphics/slot_machine/unk_lg_8465d9c.gbapal");
#endif
//*/

//static const u16 sBgPal_70[] = INCBIN_U16("graphics/slot_machine/unk_84665c0.gbapal");
/*
#if defined(FIRERED)
static const u32 sBg1Tiles[] = INCBIN_U32("graphics/slot_machine/unk_8466620.4bpp.lz");
static const u32 sBg1Map[] = INCBIN_U32("graphics/slot_machine/unk_8466998.bin.lz");
#elif defined(LEAFGREEN)
static const u32 sBg1Tiles[] = INCBIN_U32("graphics/slot_machine/unk_lg_8465f00.4bpp.lz");
static const u32 sBg1Map[] = INCBIN_U32("graphics/slot_machine/unk_lg_8466278.bin.lz");
#endif
//*/

static const struct BgTemplate sBgTemplates[] = {
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0x000
    }, {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0x000
    }, {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0x000
    }, {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0x000
    }
};

static const struct WindowTemplate sWindowTemplates[] = {
    {
        .bg = 0,
        .tilemapLeft = 5,
        .tilemapTop = 15,
        .width = 20,
        .height = 4,
        .paletteNum = 0x0f,
        .baseBlock = 0x04f
    }, {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 2,
        .paletteNum = 0x0e,
        .baseBlock = 0x013
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sYesNoWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 19,
    .tilemapTop = 9,
    .width = 6,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x9F
};

static const u32 sSlidingBlocksXs[] = {
    0x48, 0x68, 0x88, 0xA8,
    0x48, 0x68, 0x88, 0xA8,
    0x48, 0x68, 0x88, 0xA8,
    0x48, 0x68, 0x88, 0xA8
};
static const u32 sSlidingBlocksYs[] = {
    0x28, 0x28, 0x28, 0x28,
    0x48, 0x48, 0x48, 0x48,
    0x68, 0x68, 0x68, 0x68,
    0x88, 0x88, 0x88, 0x88
};

void PlaySlidingBlocks(u16 machineIdx, MainCallback savedCallback)
{
    ResetTasks();
    sSlidingBlocksState = Alloc(sizeof(*sSlidingBlocksState));
    if (sSlidingBlocksState == NULL)
        SetMainCallback2(savedCallback);
    else
    {
        if (machineIdx > 5)
            machineIdx = 0;
        sSlidingBlocksState->machineidx = machineIdx;
        sSlidingBlocksState->savedCallback = savedCallback;
        InitSlidingBlocksState(sSlidingBlocksState, sProtoLayout);
        //InitSlidingBlocksState(sSlidingBlocksState, sBabyDifficultyLayout);
        SetMainCallback2(CB2_InitSlidingBlocks);
    }
}

static void InitSlidingBlocksState(struct SlidingBlocksState *ptr, const u16 initialLayout[4][4])
{
    u32 x;
    u32 y;

    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            ptr->blocksInitialLayout[y][x] = initialLayout[y][x];
            ptr->blocksCurrentLayout[y][x] = initialLayout[y][x];
            if (ptr->blocksCurrentLayout[y][x] == 0) {
                ptr->hollowIndex[INDEX_X] = x;
                ptr->hollowIndex[INDEX_Y] = y;
            }
        }
    }
    ptr->isSliding = FALSE;
    ptr->currentMove = SLIDINGMOVE_NONE;
}

static void CB2_InitSlidingBlocks(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();

    switch (gMain.state)
    {
    case 0:
        if (CreateSlidingBlocks())
        {
            SetMainCallback2(sSlidingBlocksState->savedCallback);
            CleanSupSlidingBlocksState();
        }
        else
        {
            SetSlidingBlocksSetupTask(SLIDINGTASK_GFX_INIT, 0);
            gMain.state++;
        }
        break;
    case 1:
        if (!IsSlidingBlocksSetupTaskActive(0))
        {
            sSlidingBlocksState->taskId = CreateTask(MainTask_SlidingBlocksGameLoop, 0);
            SetMainCallback2(CB2_RunSlidingBlocks);
        }
        break;
    }
}

static void CleanSupSlidingBlocksState(void)
{
    DestroySlidingBlocks();
    if (sSlidingBlocksState != NULL)
    {
        Free(sSlidingBlocksState);
        sSlidingBlocksState = NULL;
    }
}

static void CB2_RunSlidingBlocks(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void MainTask_SlidingBlocksGameLoop(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        // Betting Phase
        if (JOY_NEW(B_BUTTON))
        {
            SetMainTask(MainTask_ConfirmExitGame);
        } else if (JOY_NEW(START_BUTTON)) {
            // Handle reset request
        } else if (JOY_NEW(DPAD_ANY)) {
            if (JOY_NEW(DPAD_UP))
                sSlidingBlocksState->currentMove = SLIDINGMOVE_UP;
            else if (JOY_NEW(DPAD_DOWN))
                sSlidingBlocksState->currentMove = SLIDINGMOVE_DOWN;
            else if (JOY_NEW(DPAD_LEFT))
                sSlidingBlocksState->currentMove = SLIDINGMOVE_LEFT;
            else if (JOY_NEW(DPAD_RIGHT))
                sSlidingBlocksState->currentMove = SLIDINGMOVE_RIGHT;
            data[0]++;
        }
        break;
    case 1:
        if (sSlidingBlocksState->currentMove == SLIDINGMOVE_NONE) {
            data[0] = 0;
        } else {
            ProcessMove(sSlidingBlocksState->currentMove);
        }
        break;
    }
}

static void MainTask_ConfirmExitGame(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        SetSlidingBlocksSetupTask(SLIDINGTASK_ASK_QUIT, 0);
        data[0]++;
        break;
    case 1:
        if (!IsSlidingBlocksSetupTaskActive(0))
            data[0]++;
        break;
    case 2:
        switch (Menu_ProcessInputNoWrapClearOnChoose())
        {
        case 0:
            gSpecialVar_Result = 0;
            data[0] = 3;
            break;
        case 1:
        case -1:
            SetSlidingBlocksSetupTask(SLIDINGTASK_DESTROY_YESNO, 0);
            data[0] = 4;
            break;
        }
        break;
    case 3:
        if (!IsSlidingBlocksSetupTaskActive(0))
            SetMainTask(MainTask_ExitSlidingBlocks);
        break;
    case 4:
        if (!IsSlidingBlocksSetupTaskActive(0))
            SetMainTask(MainTask_SlidingBlocksGameLoop);
        break;
    }
}

static void MainTask_ExitSlidingBlocks(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        SetSlidingBlocksSetupTask(SLIDINGTASK_FADEOUT_EXIT, 0);
        data[0]++;
        break;
    case 1:
        if (!IsSlidingBlocksSetupTaskActive(0))
        {
            SetMainCallback2(sSlidingBlocksState->savedCallback);
            CleanSupSlidingBlocksState();
        }
        break;
    }
}

static void ProcessMove(enum SlidingMove move) {
    switch (move) {
    case SLIDINGMOVE_UP:
        if (sSlidingBlocksState->hollowIndex[INDEX_Y] < 3)
            SetMainTask(MainTask_SlideBlock);
        else
            SetMainTask(MainTask_Bump);
        break;
    case SLIDINGMOVE_DOWN:
        if (sSlidingBlocksState->hollowIndex[INDEX_Y] > 0)
            SetMainTask(MainTask_SlideBlock);
        else
            SetMainTask(MainTask_Bump);
        break;
    case SLIDINGMOVE_LEFT:
        if (sSlidingBlocksState->hollowIndex[INDEX_X] < 3)
            SetMainTask(MainTask_SlideBlock);
        else
            SetMainTask(MainTask_Bump);
        break;
    case SLIDINGMOVE_RIGHT:
        if (sSlidingBlocksState->hollowIndex[INDEX_X] > 0)
            SetMainTask(MainTask_SlideBlock);
        else
            SetMainTask(MainTask_Bump);
        break;
    }
}

static bool32 IsSlidingLayoutSolved(u16 layout[4][4]) {
    u32 x;
    u32 y;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            if (layout[y][x] != y * 4 + x)
                return FALSE;
        }
    }
    return TRUE;
}

static void MainTask_SlideBlock(u8 taskId) {
    s16 *data = gTasks[taskId].data;
    u32 hollowIndexX = sSlidingBlocksState->hollowIndex[INDEX_X];
    u32 hollowIndexY = sSlidingBlocksState->hollowIndex[INDEX_Y];
    u32 targetIndexX; // X index of the block that needs to be moved
    u32 targetIndexY; // Y index of the block that needs to be moved
    u16 hollowContent;
    struct Sprite *hollowSprite;
    struct Sprite *targetSprite;


    switch (sSlidingBlocksState->currentMove) {
        case SLIDINGMOVE_UP:
            targetIndexX = hollowIndexX;
            targetIndexY = hollowIndexY + 1;
            break;
        case SLIDINGMOVE_DOWN:
            targetIndexX = hollowIndexX;
            targetIndexY = hollowIndexY - 1;
            break;
        case SLIDINGMOVE_LEFT:
            targetIndexX = hollowIndexX + 1;
            targetIndexY = hollowIndexY;
            break;
        case SLIDINGMOVE_RIGHT:
            targetIndexX = hollowIndexX - 1;
            targetIndexY = hollowIndexY;
            break;
        default:
            targetIndexX = hollowIndexX;
            targetIndexY = hollowIndexY;
            break;
    }

    switch (data[0]) {
        case 0:
            SetArrowsSpriteVisible(FALSE);
            sSlidingBlocksState->isSliding = TRUE;
            PlaySE(SE_M_STRENGTH);
            data[1] = 32;
            data[0]++;
            break;
        case 1:
            hollowSprite = sSlidingBlocksGfxManager->blocksSprites[sSlidingBlocksGfxManager->hollowSpriteIndex];
            //hollowSprite = sSlidingBlocksGfxManager->blocksSprites[sSlidingBlocksState->blocksCurrentLayout[hollowIndexY][hollowIndexX]];
            if (data[1] > 0) {
                targetSprite = sSlidingBlocksGfxManager->blocksSprites[sSlidingBlocksState->blocksCurrentLayout[targetIndexY][targetIndexX]];
                if (targetIndexX > hollowIndexX) {
                    hollowSprite->x++;
                    targetSprite->x--;
                }
                if (targetIndexX < hollowIndexX) {
                    hollowSprite->x--;
                    targetSprite->x++;
                }
                if (targetIndexY > hollowIndexY) {
                    hollowSprite->y++;
                    targetSprite->y--;
                }
                if (targetIndexY < hollowIndexY) {
                    hollowSprite->y--;
                    targetSprite->y++;
                }
                data[1]--;
            } else {
                sSlidingBlocksState->isSliding = FALSE;
                SetArrowsSpritePosition(hollowSprite->x, hollowSprite->y);
                data[0]++;
            }
            break;
        case 2:
            // Swap hollow place with target block
            hollowContent = sSlidingBlocksState->blocksCurrentLayout[hollowIndexY][hollowIndexX]; // Will always be 0
            sSlidingBlocksState->blocksCurrentLayout[hollowIndexY][hollowIndexX] = sSlidingBlocksState->blocksCurrentLayout[targetIndexY][targetIndexX];
            sSlidingBlocksState->blocksCurrentLayout[targetIndexY][targetIndexX] = hollowContent;
            sSlidingBlocksState->hollowIndex[INDEX_X] = targetIndexX;
            sSlidingBlocksState->hollowIndex[INDEX_Y] = targetIndexY;
            if (IsSlidingLayoutSolved(sSlidingBlocksState->blocksCurrentLayout)) {
                gSpecialVar_Result = 1;
                SetMainTask(MainTask_VictorySequence);
            } else {
                SetArrowsSpriteVisible(TRUE);
                StartSpriteAnim(sSlidingBlocksGfxManager->arrowsSprite, SPRITEANIM_ARROWS_CONVERGE);
                SetMainTask(MainTask_SlidingBlocksGameLoop);
            }
            break;
    }
}

static void MainTask_Bump(u8 taskId) {
    s16 *data = gTasks[taskId].data;

    switch (data[0]) {
    case 0:
        PlaySE(SE_WALL_HIT);
        data[0]++;
        break;
    case 1:
        if (!IsSEPlaying()) {
            sSlidingBlocksState->currentMove = SLIDINGMOVE_NONE;
            SetMainTask(MainTask_SlidingBlocksGameLoop);
        }
        break;
    }
}

static void MainTask_VictorySequence(u8 taskId) {
    s16 *data = gTasks[taskId].data;
    struct Sprite *hollowSprite = sSlidingBlocksGfxManager->blocksSprites[sSlidingBlocksGfxManager->hollowSpriteIndex];

    switch (data[0]) {
    case 0:
        PlayFanfare(MUS_SLOTS_WIN);
        data[1] = 90;
        data[0]++;
        break;
    case 1:
        // Revealing missing block phase
        if (data[1] > 0) {
            if (data[1] < 30) {
                hollowSprite->invisible = !hollowSprite->invisible;
            } else if (data[1] < 60) {
                if (data[1] % 2 == 0) {
                    hollowSprite->invisible = !hollowSprite->invisible;
                }
            } else {
                if (data[1] % 3 == 0) {
                    hollowSprite->invisible = !hollowSprite->invisible;
                }
            }
            data[1]--;
        } else {
            hollowSprite->invisible = FALSE;
            data[0]++;
        }
        break;
    case 2:
        SetSlidingBlocksSetupTask(SLIDINGTASK_VICTORY_MESSAGE, 0);
        data[0]++;
        break;
    case 3:
        if (!IsSlidingBlocksSetupTaskActive(0))
            data[0]++;
        break;
    case 4:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
            SetMainTask(MainTask_ExitSlidingBlocks);
        break;
    }
}

static void SetMainTask(TaskFunc taskFunc)
{
    gTasks[sSlidingBlocksState->taskId].func = taskFunc;
    gTasks[sSlidingBlocksState->taskId].data[0] = 0;
}

static bool32 LoadSpriteGraphicsAndAllocateManager(void)
{
    s32 i;

    for (i = 0; i < NELEMS(sSpriteSheets); i++)
        LoadCompressedSpriteSheet(&sSpriteSheets[i]);
    LoadSpritePalettes(sSpritePalettes);
    sSlidingBlocksGfxManager = Alloc(sizeof(*sSlidingBlocksGfxManager));
    if (sSlidingBlocksGfxManager == NULL)
        return FALSE;
    InitGfxManager(sSlidingBlocksGfxManager);
    return TRUE;
}

static void DestroyGfxManager(void)
{
    if (sSlidingBlocksGfxManager != NULL)
    {
        Free(sSlidingBlocksGfxManager);
        sSlidingBlocksGfxManager = NULL;
    }
}

static void InitGfxManager(struct SlidingBlocksGfxManager * manager)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        manager->blocksSprites[i] = NULL;
    }
    manager->arrowsSprite = NULL;
}

static void HBlankCB_SlidingBlocks(void)
{
    s32 vcount = REG_VCOUNT - 0x2B;
    if (vcount < 0x54u)
    {
        REG_BLDY = sReelIconBldY[vcount];
    }
    else
    {
        REG_BLDY = 0;
    }
}

static void CreateBlocksSprites(u32 indexOfHollowPiece) {
    u32 i;
    u32 x;
    u32 y;
    u32 spriteIndex;
    u32 spriteId;
    struct Sprite *currentSprite;

    for (i = 0; i < SLIDING_NUM_BLOCKS; i++) {
        spriteId = CreateSprite(&sSpriteTemplate_Blocks, sSlidingBlocksXs[i], sSlidingBlocksYs[i], 1);
        sSlidingBlocksGfxManager->blocksSprites[i] = &gSprites[spriteId];
        currentSprite = &gSprites[spriteId];
        currentSprite->oam.tileNum = i * 16;
    }
    sSlidingBlocksGfxManager->blocksSprites[indexOfHollowPiece]->invisible = TRUE;
    sSlidingBlocksGfxManager->hollowSpriteIndex = indexOfHollowPiece;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            spriteIndex = y * 4 + x;
            currentSprite = sSlidingBlocksGfxManager->blocksSprites[sSlidingBlocksState->blocksCurrentLayout[y][x]];
            currentSprite->x = sSlidingBlocksXs[spriteIndex];
            currentSprite->y = sSlidingBlocksYs[spriteIndex];
            if (currentSprite == sSlidingBlocksGfxManager->blocksSprites[indexOfHollowPiece]) {
                SetArrowsSpritePosition(currentSprite->x, currentSprite->y);
            }
        }
    }
}

static void CreateArrowsSprite(void) {
    s32 spriteId;

    spriteId = CreateSprite(&sSpriteTemplate_Arrows, 0x10, 0x68, 1);
    sSlidingBlocksGfxManager->arrowsSprite = &gSprites[spriteId];
}

static bool32 CreateSlidingBlocks(void)
{
    s32 i;

    struct SlidingBlocksSetupTaskData * ptr = Alloc(sizeof(struct SlidingBlocksSetupTaskData));
    if (ptr == NULL)
        return FALSE;
    for (i = 0; i < 8; i++)
        ptr->tasks[i].active = 0;
    ptr->yesNoMenuActive = FALSE;
    SetWordTaskArg(CreateTask(Task_SlidingBlocks, 2), 0, (uintptr_t)ptr);
    return FALSE;
}

static void SetArrowsSpritePosition(s16 x, s16 y) {
    sSlidingBlocksGfxManager->arrowsSprite->x = x;
    sSlidingBlocksGfxManager->arrowsSprite->y = y;
}

static void SetArrowsSpriteVisible(bool32 isVisible) {
    sSlidingBlocksGfxManager->arrowsSprite->invisible = !isVisible;
}

static void DestroySlidingBlocks(void)
{
    if (FuncIsActiveTask(Task_SlidingBlocks))
    {
        Free(GetSlidingBlocksSetupTaskDataPtr());
        DestroyTask(FindTaskIdByFunc(Task_SlidingBlocks));
    }
    DestroyGfxManager();
    FreeAllWindowBuffers();
}

static void Task_SlidingBlocks(u8 taskId)
{
    struct SlidingBlocksSetupTaskData * ptr = (void *)GetWordTaskArg(taskId, 0);
    s32 i;

    for (i = 0; i < 8; i++)
    {
        if (ptr->tasks[i].active)
            ptr->tasks[i].active = sSlidingBlocksSetupTasks[ptr->tasks[i].funcno](&ptr->tasks[i].state, ptr);
    }
}

static void VBlankCB_SlidingBlocks(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
}

static struct SlidingBlocksSetupTaskData * GetSlidingBlocksSetupTaskDataPtr(void)
{
    return (void *)GetWordTaskArg(FindTaskIdByFunc(Task_SlidingBlocks), 0);
}

static void SetSlidingBlocksSetupTask(u16 funcno, u8 taskId)
{
    struct SlidingBlocksSetupTaskData * ptr = GetSlidingBlocksSetupTaskDataPtr();
    ptr->tasks[taskId].funcno = funcno;
    ptr->tasks[taskId].state = 0;
    ptr->tasks[taskId].active = sSlidingBlocksSetupTasks[funcno](&ptr->tasks[taskId].state, ptr);
}

static bool32 IsSlidingBlocksSetupTaskActive(u8 taskId)
{
    return GetSlidingBlocksSetupTaskDataPtr()->tasks[taskId].active;
}

static inline void LoadColor(u16 color, u16 *pal)
{
    *pal = color;
    LoadPalette(pal, 0x00, 0x02);
}

static bool8 SlidingTask_GraphicsInit(u8 * state, struct SlidingBlocksSetupTaskData * ptr)
{
    u16 pal[2];
    u8 textColor[3];
    u32 x;

    switch (*state)
    {
    case 0:
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        (*state)++;
        break;
    case 1:
        SetVBlankCallback(NULL);
        ResetSpriteData();
        FreeAllSpritePalettes();
        RequestDma3Fill(0, (void *)OAM, OAM_SIZE, DMA3_32BIT);
        RequestDma3Fill(0, (void *)VRAM, 0x20, DMA3_32BIT);
        RequestDma3Fill(0, (void *)(VRAM + 0xC000), 0x20, DMA3_32BIT);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgPositions();
        ResetBgsAndClearDma3BusyFlags(FALSE);
        InitBgsFromTemplates(0, sBgTemplates, NELEMS(sBgTemplates));
        InitWindows(sWindowTemplates);

        SetBgTilemapBuffer(3, ptr->bg3TilemapBuffer);
        FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 32, 32);
        CopyBgTilemapBufferToVram(3);

        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(2, sBgWallTiles, 0, 0x00, 0);
        SetBgTilemapBuffer(2, ptr->bg2TilemapBuffer);
        CopyToBgTilemapBuffer(2, sBgWallMap, 0, 0x00);
        CopyBgTilemapBufferToVram(2);
        LoadPalette(sBgWallPal, 0x00, 0xA0);
        //LoadPalette(sBgPal_50, 0x50, 0x20);
        //LoadPalette(sBgPal_70, 0x70, 0x60);
        LoadColor(RGB(30, 30, 31), pal);
        LoadUserWindowGfx2(0, 0x00A, 0xD0);
        LoadStdWindowGfxOnBg(0, 0x001, 0xF0);

        SetBgTilemapBuffer(0, ptr->bg0TilemapBuffer);
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 2, 32, 30);
        //DecompressAndCopyTileDataToVram(1, sBg1Tiles, 0, 0, 0);
        //DecompressAndCopyTileDataToVram(1, sBg1Map, 0, 0, 1);
        CopyBgTilemapBufferToVram(1);

        LoadPalette(GetTextWindowPalette(2), 0xE0, 0x20);
        FillWindowPixelBuffer(1, 0x00);
        PutWindowTilemap(1);

        x = (240 - GetStringWidth(FONT_SMALL, sString_SlidingBlocksControls, 0)) / 2;
        textColor[0] = TEXT_COLOR_TRANSPARENT;
        textColor[1] = TEXT_COLOR_WHITE;
        textColor[2] = TEXT_COLOR_DARK_GRAY;
        AddTextPrinterParameterized3(1, FONT_SMALL, x, 0, textColor, 0, sString_SlidingBlocksControls);
        CopyBgTilemapBufferToVram(0);

        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | 0x20 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        //SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BD | BLDCNT_EFFECT_DARKEN);
        LoadSpriteGraphicsAndAllocateManager();
        CreateArrowsSprite();
        CreateBlocksSprites(0);
        BlendPalettes(PALETTES_ALL, 0x10, RGB_BLACK);
        SetVBlankCallback(VBlankCB_SlidingBlocks);
        SetHBlankCallback(HBlankCB_SlidingBlocks);
        (*state)++;
        break;
    case 2:
        // Probably change music here
        (*state)++;
        break;
    case 3:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            ShowBg(0);
            ShowBg(3);
            ShowBg(2);
            HideBg(1);
            BlendPalettes(PALETTES_ALL, 0x10, RGB_BLACK);
            BeginNormalPaletteFade(PALETTES_ALL, -1, 16, 0, RGB_BLACK);
            EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_HBLANK);
            (*state)++;
        }
        break;
    case 4:
        UpdatePaletteFade();
        if (!gPaletteFade.active)
            return FALSE;
        break;
    }
    return TRUE;
}

static bool8 SlidingTask_FadeOut(u8 * state, struct SlidingBlocksSetupTaskData * ptr)
{
    switch (*state)
    {
    case 0:
        BeginNormalPaletteFade(PALETTES_ALL, -1, 0, 16, 0);
        (*state)++;
        break;
    case 1:
        if (!gPaletteFade.active)
            return FALSE;
        break;
    }
    return TRUE;
}

static bool8 SlidingTask_AskQuitPlaying(u8 * state, struct SlidingBlocksSetupTaskData * ptr)
{
    switch (*state)
    {
    case 0:
        SlidingBlocks_PrintOnWindow0(sString_GiveUpPuzzle);
        SlidingBlocks_CreateYesNoMenu(0);
        CopyWindowToVram(0, COPYWIN_FULL);
        (*state)++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
            return FALSE;
        break;
    }
    return TRUE;
}

static bool8 SlidingTask_DestroyYesNoMenu(u8 * state, struct SlidingBlocksSetupTaskData * ptr)
{
    switch (*state)
    {
    case 0:
        SlidingBlocks_ClearWindow0();
        SlidingBlocks_DestroyYesNoMenu();
        CopyWindowToVram(0, COPYWIN_FULL);
        (*state)++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
            return FALSE;
        break;
    }
    return TRUE;
}

static bool8 SlidingTask_VictoryMessage(u8 *state, struct SlidingBlocksSetupTaskData *ptr) {
    switch (*state) {
    case 0:
        SlidingBlocks_PrintOnWindow0(sString_PuzzleSolved);
        CopyWindowToVram(0, COPYWIN_FULL);
        (*state)++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
            return FALSE;
        break;
    }
    return TRUE;
}

static void SlidingBlocks_PrintOnWindow0(const u8 * str)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    PutWindowTilemap(0);
    DrawTextBorderOuter(0, 0x001, 15);
    AddTextPrinterParameterized5(0, FONT_NORMAL, str, 1, 2, TEXT_SKIP_DRAW, NULL, 1, 2);
}

static void SlidingBlocks_ClearWindow0(void)
{
    rbox_fill_rectangle(0);
}

static void SlidingBlocks_CreateYesNoMenu(u8 cursorPos)
{
    CreateYesNoMenu(&sYesNoWindowTemplate, FONT_NORMAL, 0, 2, 10, 13, cursorPos);
    Menu_MoveCursorNoWrapAround(cursorPos);
    GetSlidingBlocksSetupTaskDataPtr()->yesNoMenuActive = TRUE;
}

static void SlidingBlocks_DestroyYesNoMenu(void)
{
    struct SlidingBlocksSetupTaskData * data = GetSlidingBlocksSetupTaskDataPtr();
    if (data->yesNoMenuActive)
    {
        DestroyYesNoMenu();
        data->yesNoMenuActive = FALSE;
    }
}
