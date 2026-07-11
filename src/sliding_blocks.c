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
#include "constants/sliding_blocks.h"

#define SLIDINGTASK_GFX_INIT        0
#define SLIDINGTASK_FADEOUT_EXIT    1
#define SLIDINGTASK_ASK_QUIT        2
#define SLIDINGTASK_DESTROY_YESNO   3
#define SLIDINGTASK_VICTORY_MESSAGE 4

#define INDEX_X 0
#define INDEX_Y 1

#define SPRITEANIM_ARROWS_CONVERGE 0
#define SPRITEANIM_HAND_POINT      0

#define TILETAG_BLOCKS 0
#define TILETAG_ARROWS 1
#define TILETAG_HAND   2

#define SLIDING_NUM_BLOCKS 16
#define ARROWS_NUM_TILES 16
#define HAND_NUM_TILES   16


enum ControlMode {
    CONTROLMODE_ARROWS,
    CONTROLMODE_CURSOR
};


enum SlidingMove {
    SLIDINGMOVE_NONE = 0,
    SLIDINGMOVE_UP,
    SLIDINGMOVE_DOWN,
    SLIDINGMOVE_LEFT,
    SLIDINGMOVE_RIGHT
};

struct SlidingBlocksLayout
{
    u16 blocksPermutation[4][4];
    u16 blocksOrientation[4][4];
    u16 hollowIndex[2];
};

struct SlidingBlocksPuzzle
{
    const u32 *spriteSheet;
    const u16 *palette;
    struct SlidingBlocksLayout blocksInitialLayout;
    bool32 (*winCondition)(const struct SlidingBlocksLayout *layout);
};

struct SlidingBlocksState
{
    MainCallback savedCallback;
    u16 puzzleId;
    u8 taskId;
    struct SlidingBlocksLayout blocksInitialLayout;
    struct SlidingBlocksLayout blocksCurrentLayout;
    enum ControlMode controlMode;
    bool32 (*winCondition)(const struct SlidingBlocksLayout *layout);
    bool32 isSliding;
    enum SlidingMove currentMove;
};

struct SlidingBlocksGfxManager
{
    struct Sprite *blocksSprites[SLIDING_NUM_BLOCKS];
    struct Sprite *arrowsSprite;
    struct Sprite *handSprite;
    u32 cursorIndex;
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
    u8 bg0TilemapBuffer[0x800];
    u8 bg1TilemapBuffer[0x800];
    u8 bg2TilemapBuffer[0x800];
    u8 bg3TilemapBuffer[0x800];
};

static EWRAM_DATA struct SlidingBlocksState * sSlidingBlocksState = NULL;
static EWRAM_DATA struct SlidingBlocksGfxManager * sSlidingBlocksGfxManager = NULL;

static void InitSlidingBlocksState(struct SlidingBlocksState *ptr, const struct SlidingBlocksPuzzle *puzzle);
static void CB2_InitSlidingBlocks(void);
static void CleanSupSlidingBlocksState(void);
static void CB2_RunSlidingBlocks(void);
static void MainTask_SlidingBlocksGameLoop(u8 taskId);
static void MainTask_ShowHelp(u8 taskId);
static void MainTask_ConfirmExitGame(u8 taskId);
static void MainTask_ExitSlidingBlocks(u8 taskId);
static void MainTask_VictorySequence(u8 taskId);
static bool32 CanSetControlMode(enum ControlMode mode);
static void SetControlMode(enum ControlMode mode);
static void HandleControlModeChange(void);
static void ProcessMove(enum SlidingMove move);
static bool32 IsSlidingLayoutSolved(const struct SlidingBlocksState *state);
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
static void SetHandSpritePosition(s16 x, s16 y);
static void SetHandSpriteVisible(bool32 isVisible);
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
static void SlidingBlocks_PrintControlsText(const u8 *str);
// Winning conditions for each puzzle
static bool32 WinCondition_AllCorrectPlaces(const struct SlidingBlocksLayout *layout);
static bool32 WinCondition_AllCorrectOrientations(const struct SlidingBlocksLayout *layout);
static bool32 WinCondition_AllCorrectPlacesAndOrientations(const struct SlidingBlocksLayout *layout);
static bool32 WinCondition_NeverWin(const struct SlidingBlocksLayout *layout);

static const u8 sString_SlidingBlocksControlsArrows[] = _("{SELECT_BUTTON}Mode {DPAD_ANY}Slide {B_BUTTON}Give up");
static const u8 sString_SlidingBlocksControlsArrowsCantSwitch[] = _("{DPAD_ANY}Slide {B_BUTTON}Give up");
static const u8 sString_SlidingBlocksControlsCursor[] = _("{SELECT_BUTTON}Mode {DPAD_ANY}Select {L_BUTTON}{R_BUTTON}Rotate {A_BUTTON}Slide");
static const u8 sString_SlidingBlocksControlsCursorCantSwitch[] = _("{DPAD_ANY}Select {L_BUTTON}{R_BUTTON}Rotate {B_BUTTON}Give up");
static const u8 sString_GiveUpPuzzle[] = _("Give up on this puzzle?");
static const u8 sString_PuzzleSolved[] = _("Congratulations!\nYou solved the puzzle!");

static const u32 sSpriteTiles_HoOh[] = INCBIN_U32("graphics/sliding_blocks/puzzle_ho_oh.4bpp.lz");
static const u32 sSpriteTiles_Voltorb[] = INCBIN_U32("graphics/sliding_blocks/puzzle_voltorb.4bpp.lz");
static const u32 sSpriteTiles_Electrode[] = INCBIN_U32("graphics/sliding_blocks/puzzle_electrode.4bpp.lz");

static const u16 sSpritePal_HoOh[] = INCBIN_U16("graphics/sliding_blocks/puzzle_ho_oh.gbapal");
static const u16 sSpritePal_Voltorb[] = INCBIN_U16("graphics/sliding_blocks/puzzle_voltorb.gbapal");
static const u16 sSpritePal_Electrode[] = INCBIN_U16("graphics/sliding_blocks/puzzle_electrode.gbapal");

static const u32 sSpriteTiles_Arrows[] = INCBIN_U32("graphics/sliding_blocks/arrows.4bpp.lz");
static const u32 sSpriteTiles_Hand[] = INCBIN_U32("graphics/sliding_blocks/hand.4bpp.lz");
static const u16 sSpritePal_Hud[] = INCBIN_U16("graphics/sliding_blocks/hud.gbapal");

static const struct CompressedSpriteSheet sSpriteSheets[] = {
    {(const void *)sSpriteTiles_Arrows,  0x2A00, TILETAG_ARROWS},
    {(const void *)sSpriteTiles_Hand,   0x2A00, TILETAG_HAND},
};

static const struct SpritePalette sSpriteHudPalettes[] = {
    {sSpritePal_Hud, 1},
    {NULL}
};

static const struct SlidingBlocksPuzzle sSlidingBlocksPuzzles[] = {

    [SLIDING_LAYOUT_TEST_HO_OH] = {
        .spriteSheet = sSpriteTiles_HoOh,
        .palette = sSpritePal_HoOh,
        .blocksInitialLayout = {
            .blocksPermutation = {
                { 1,  3, 14,  6},
                { 9,  0,  4,  2},
                { 7, 12, 11, 15},
                {13,  5, 10,  8}
            },
            .blocksOrientation = {
                {DIR_NORTH, DIR_NORTH, DIR_NORTH, DIR_NORTH},
                {DIR_NORTH, DIR_NORTH, DIR_NORTH, DIR_NORTH},
                {DIR_NORTH, DIR_NORTH, DIR_NORTH, DIR_NORTH},
                {DIR_NORTH, DIR_NORTH, DIR_NORTH, DIR_NORTH}
            },
            .hollowIndex = {[INDEX_X] = 1, [INDEX_Y] = 1} // Where 0 is
        },
        .winCondition = WinCondition_AllCorrectPlaces
    },

    [SLIDING_LAYOUT_VOLTORB] = {
        .spriteSheet = sSpriteTiles_Voltorb,
        .palette = sSpritePal_Voltorb,
        .blocksInitialLayout = {
            .blocksPermutation = {
                {15, 14, 13, 12},
                {11, 10,  9,  8},
                { 7,  6,  5,  4},
                { 3,  2,  1,  0}
            },
            .blocksOrientation = {
                {DIR_SOUTH, DIR_SOUTH, DIR_SOUTH, DIR_SOUTH},
                {DIR_SOUTH, DIR_SOUTH, DIR_SOUTH, DIR_SOUTH},
                {DIR_SOUTH, DIR_SOUTH, DIR_SOUTH, DIR_SOUTH},
                {DIR_SOUTH, DIR_SOUTH, DIR_SOUTH, DIR_SOUTH}
            },
            .hollowIndex = {[INDEX_X] = 3, [INDEX_Y] = 3} // Where 0 is
        },
        .winCondition = WinCondition_AllCorrectPlacesAndOrientations
    },

    [SLIDING_LAYOUT_ELECTRODE] = {
        .spriteSheet = sSpriteTiles_Electrode,
        .palette = sSpritePal_Electrode,
        .blocksInitialLayout = {
            .blocksPermutation = {
                {15, 14, 13, 12},
                {11, 10,  9,  8},
                { 7,  6,  5,  4},
                { 3,  2,  1,  0}
            },
            .blocksOrientation = {
                {DIR_SOUTH, DIR_SOUTH, DIR_SOUTH, DIR_SOUTH},
                {DIR_SOUTH, DIR_SOUTH, DIR_SOUTH, DIR_SOUTH},
                {DIR_SOUTH, DIR_SOUTH, DIR_SOUTH, DIR_SOUTH},
                {DIR_SOUTH, DIR_SOUTH, DIR_SOUTH, DIR_SOUTH}
            },
            .hollowIndex = {[INDEX_X] = 0, [INDEX_Y] = 0} // Where 15 is
        },
        .winCondition = WinCondition_AllCorrectOrientations
    }

};

static const u8 sReelIconBldY[] = {
    0x10, 0x10, 0x10, 0x10, 0x0f, 0x0e, 0x0d, 0x0d, 0x0c, 0x0b, 0x0a, 0x0a, 0x09, 0x08, 0x07, 0x07, 0x06, 0x05, 0x04, 0x04, 0x03, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x03, 0x04, 0x05, 0x06, 0x06, 0x07, 0x08, 0x09, 0x09, 0x0a, 0x0b, 0x0c, 0x0c, 0x0d, 0x0e, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f
};

enum TileAnimation {
    TILEANIM_BE_COUNTERCLOCKWISE,
    TILEANIM_BE_CLOCKWISE,
    TILEANIM_BE_FLIPPED,
    TILEANIM_ROTATE_COUNTERCLOCKWISE,
    TILEANIM_ROTATE_CLOCKWISE
};

static const union AffineAnimCmd sTileAffineAnim_BeCounterclockwise[] = {
    AFFINEANIMCMD_FRAME(0, 0, 64, 1), // Rotate 90 degrees counter-clockwise instantly
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sTileAffineAnim_BeClockwise[] = {
    AFFINEANIMCMD_FRAME(0, 0, -64, 1), // Rotate 90 degrees clockwise instantly
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sTileAffineAnim_BeFlipped[] = {
    AFFINEANIMCMD_FRAME(0, 0, 128, 1), // Rotate 180 degrees instantly
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sTileAffineAnim_RotateCounterclockwise[] = {
    AFFINEANIMCMD_FRAME(0, 0, 4, 16), // Rotate 90 degrees counter-clockwise
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sTileAffineAnim_RotateClockwise[] = {
    AFFINEANIMCMD_FRAME(0, 0, -4, 16), // Rotate 90 degrees clockwise
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sTileAffineAnims[] = {
    [TILEANIM_BE_COUNTERCLOCKWISE]     = sTileAffineAnim_BeCounterclockwise,
    [TILEANIM_BE_CLOCKWISE]            = sTileAffineAnim_BeClockwise,
    [TILEANIM_BE_FLIPPED]              = sTileAffineAnim_BeFlipped,
    [TILEANIM_ROTATE_COUNTERCLOCKWISE] = sTileAffineAnim_RotateCounterclockwise,
    [TILEANIM_ROTATE_CLOCKWISE]        = sTileAffineAnim_RotateClockwise
};

static const struct OamData sOamData_Blocks = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
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

static const struct OamData sOamData_Hand = {
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

static const union AnimCmd sAnimCmd_Hand_Point[] = {
    ANIMCMD_FRAME(0 * HAND_NUM_TILES,  1),
    ANIMCMD_FRAME(1 * HAND_NUM_TILES,  1),
    ANIMCMD_FRAME(2 * HAND_NUM_TILES,  1),
    ANIMCMD_FRAME(3 * HAND_NUM_TILES, 30),
    ANIMCMD_FRAME(2 * HAND_NUM_TILES,  1),
    ANIMCMD_FRAME(1 * HAND_NUM_TILES,  1),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnimTable_Arrows[] = {
    [SPRITEANIM_ARROWS_CONVERGE] = sAnimCmd_Arrows_Converge
};

static const union AnimCmd *const sAnimTable_Hand[] = {
    [SPRITEANIM_HAND_POINT] = sAnimCmd_Hand_Point
};

static const struct SpriteTemplate sSpriteTemplate_Blocks = {
    .tileTag = TILETAG_BLOCKS,
    .paletteTag = 0,
    .oam = &sOamData_Blocks,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sTileAffineAnims,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_Arrows = {
    .tileTag = TILETAG_ARROWS,
    .paletteTag = 1,
    .oam = &sOamData_Arrows,
    .anims = sAnimTable_Arrows,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_Hand = {
    .tileTag = TILETAG_HAND,
    .paletteTag = 1,
    .oam = &sOamData_Hand,
    .anims = sAnimTable_Hand,
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

void PlaySlidingBlocks(u16 puzzleId, MainCallback savedCallback)
{
    ResetTasks();
    sSlidingBlocksState = Alloc(sizeof(*sSlidingBlocksState));
    if (sSlidingBlocksState == NULL)
        SetMainCallback2(savedCallback);
    else
    {
        const struct SlidingBlocksPuzzle *puzzle = &sSlidingBlocksPuzzles[puzzleId];
        sSlidingBlocksState->puzzleId = puzzleId;
        sSlidingBlocksState->savedCallback = savedCallback;
        InitSlidingBlocksState(sSlidingBlocksState, puzzle);
        SetMainCallback2(CB2_InitSlidingBlocks);
    }
}

static void InitSlidingBlocksState(struct SlidingBlocksState *ptr, const struct SlidingBlocksPuzzle *puzzle)
{
    /*
    TODO: Set winning condition according to the puzzle
    */
    u32 x;
    u32 y;

    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            // Init copy of initial layout
            ptr->blocksInitialLayout.blocksPermutation[y][x] = puzzle->blocksInitialLayout.blocksPermutation[y][x];
            ptr->blocksInitialLayout.blocksOrientation[y][x] = puzzle->blocksInitialLayout.blocksOrientation[y][x];
            ptr->blocksInitialLayout.hollowIndex[INDEX_X] = puzzle->blocksInitialLayout.hollowIndex[INDEX_X];
            ptr->blocksInitialLayout.hollowIndex[INDEX_Y] = puzzle->blocksInitialLayout.hollowIndex[INDEX_Y];

            // Init current layout, starting the same as the initial layout
            ptr->blocksCurrentLayout.blocksPermutation[y][x] = puzzle->blocksInitialLayout.blocksPermutation[y][x];
            ptr->blocksCurrentLayout.blocksOrientation[y][x] = puzzle->blocksInitialLayout.blocksOrientation[y][x];
            ptr->blocksCurrentLayout.hollowIndex[INDEX_X] = puzzle->blocksInitialLayout.hollowIndex[INDEX_X];
            ptr->blocksCurrentLayout.hollowIndex[INDEX_Y] = puzzle->blocksInitialLayout.hollowIndex[INDEX_Y];
        }
    }
    ptr->winCondition = puzzle->winCondition;

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
        if (JOY_NEW(B_BUTTON))
        {
            SetMainTask(MainTask_ConfirmExitGame);
        } else if (JOY_NEW(SELECT_BUTTON)) {
            // Change control mode
            HandleControlModeChange();
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

static bool32 CanSetControlMode(enum ControlMode mode) {
    // TODO: Rewrite checking if there are blocks that can rotate or slide
    u16 *hollowIndexVector;
    switch (mode) {
        case CONTROLMODE_ARROWS:
            hollowIndexVector = sSlidingBlocksState->blocksCurrentLayout.hollowIndex;
            return hollowIndexVector[INDEX_X] < 4 && hollowIndexVector[INDEX_Y] < 4;
        case CONTROLMODE_CURSOR:
            return TRUE;
    }
}

static void SetControlMode(enum ControlMode mode) {
    sSlidingBlocksState->controlMode = mode;
    switch (mode) {
        case CONTROLMODE_ARROWS:
            SetArrowsSpriteVisible(TRUE);
            SetHandSpriteVisible(FALSE);
            FillWindowPixelBuffer(1, PIXEL_FILL(0));
            if (CanSetControlMode(CONTROLMODE_CURSOR)) {
                SlidingBlocks_PrintControlsText(sString_SlidingBlocksControlsArrows);
            } else {
                SlidingBlocks_PrintControlsText(sString_SlidingBlocksControlsArrowsCantSwitch);
            }
            break;
        case CONTROLMODE_CURSOR:
            SetArrowsSpriteVisible(FALSE);
            SetHandSpriteVisible(TRUE);
            FillWindowPixelBuffer(1, PIXEL_FILL(0));
            if (CanSetControlMode(CONTROLMODE_ARROWS)) {
                SlidingBlocks_PrintControlsText(sString_SlidingBlocksControlsCursor);
            } else {
                SlidingBlocks_PrintControlsText(sString_SlidingBlocksControlsCursorCantSwitch);
            }
            break;
    }
}

static void HandleControlModeChange(void) {
    switch (sSlidingBlocksState->controlMode) {
        case CONTROLMODE_ARROWS:
            if (CanSetControlMode(CONTROLMODE_CURSOR)) {
                SetControlMode(CONTROLMODE_CURSOR);
            }
            break;
        case CONTROLMODE_CURSOR:
            if (CanSetControlMode(CONTROLMODE_ARROWS)) {
                SetControlMode(CONTROLMODE_ARROWS);
            }
            break;
    }
}

static void ProcessMove(enum SlidingMove move) {
    switch (move) {
    case SLIDINGMOVE_UP:
        if (sSlidingBlocksState->blocksCurrentLayout.hollowIndex[INDEX_Y] < 3)
            SetMainTask(MainTask_SlideBlock);
        else
            SetMainTask(MainTask_Bump);
        break;
    case SLIDINGMOVE_DOWN:
        if (sSlidingBlocksState->blocksCurrentLayout.hollowIndex[INDEX_Y] > 0)
            SetMainTask(MainTask_SlideBlock);
        else
            SetMainTask(MainTask_Bump);
        break;
    case SLIDINGMOVE_LEFT:
        if (sSlidingBlocksState->blocksCurrentLayout.hollowIndex[INDEX_X] < 3)
            SetMainTask(MainTask_SlideBlock);
        else
            SetMainTask(MainTask_Bump);
        break;
    case SLIDINGMOVE_RIGHT:
        if (sSlidingBlocksState->blocksCurrentLayout.hollowIndex[INDEX_X] > 0)
            SetMainTask(MainTask_SlideBlock);
        else
            SetMainTask(MainTask_Bump);
        break;
    }
}

static bool32 IsSlidingLayoutSolved(const struct SlidingBlocksState *state) {
    return state->winCondition(&state->blocksCurrentLayout);
}

static void MainTask_SlideBlock(u8 taskId) {
    s16 *data = gTasks[taskId].data;
    u32 hollowIndexX = sSlidingBlocksState->blocksCurrentLayout.hollowIndex[INDEX_X];
    u32 hollowIndexY = sSlidingBlocksState->blocksCurrentLayout.hollowIndex[INDEX_Y];
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
                targetSprite = sSlidingBlocksGfxManager->blocksSprites[sSlidingBlocksState->blocksCurrentLayout.blocksPermutation[targetIndexY][targetIndexX]];
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
            hollowContent = sSlidingBlocksState->blocksCurrentLayout.blocksPermutation[hollowIndexY][hollowIndexX];
            sSlidingBlocksState->blocksCurrentLayout.blocksPermutation[hollowIndexY][hollowIndexX] = sSlidingBlocksState->blocksCurrentLayout.blocksPermutation[targetIndexY][targetIndexX];
            sSlidingBlocksState->blocksCurrentLayout.blocksPermutation[targetIndexY][targetIndexX] = hollowContent;
            hollowContent = sSlidingBlocksState->blocksCurrentLayout.blocksOrientation[hollowIndexY][hollowIndexX];
            sSlidingBlocksState->blocksCurrentLayout.blocksOrientation[hollowIndexY][hollowIndexX] = sSlidingBlocksState->blocksCurrentLayout.blocksOrientation[targetIndexY][targetIndexX];
            sSlidingBlocksState->blocksCurrentLayout.blocksOrientation[targetIndexY][targetIndexX] = hollowContent;
            sSlidingBlocksState->blocksCurrentLayout.hollowIndex[INDEX_X] = targetIndexX;
            sSlidingBlocksState->blocksCurrentLayout.hollowIndex[INDEX_Y] = targetIndexY;
            if (IsSlidingLayoutSolved(sSlidingBlocksState)) {
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
    struct Sprite *hollowSprite = NULL;

    switch (data[0]) {
    case 0:
        PlayFanfare(MUS_SLOTS_WIN);
        data[1] = 90;
        data[0]++;
        break;
    case 1:
        // Revealing missing block phase
        if (sSlidingBlocksGfxManager->hollowSpriteIndex < SLIDING_NUM_BLOCKS) {
            hollowSprite = sSlidingBlocksGfxManager->blocksSprites[sSlidingBlocksGfxManager->hollowSpriteIndex];
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
    struct CompressedSpriteSheet blocksSpriteSheet;
    struct SpritePalette blocksSpritePaletteWrapper[] = {{NULL}, {NULL}};
    const struct SlidingBlocksPuzzle *puzzle = &sSlidingBlocksPuzzles[sSlidingBlocksState->puzzleId];
    
    blocksSpriteSheet.data = puzzle->spriteSheet;
    blocksSpriteSheet.size = 0x2000;
    blocksSpriteSheet.tag = TILETAG_BLOCKS;
    blocksSpritePaletteWrapper[0].data = puzzle->palette;
    blocksSpritePaletteWrapper[0].tag = 0;
    LoadCompressedSpriteSheet(&blocksSpriteSheet);
    for (i = 0; i < NELEMS(sSpriteSheets); i++)
        LoadCompressedSpriteSheet(&sSpriteSheets[i]);
    LoadSpritePalettes(blocksSpritePaletteWrapper);
    LoadSpritePalettes(sSpriteHudPalettes);
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
    manager->handSprite = NULL;
}

static void HBlankCB_SlidingBlocks(void)
{
    /*
    s32 vcount = REG_VCOUNT - 0x2B;
    if (vcount < 0x54u)
    {
        REG_BLDY = sReelIconBldY[vcount];
    }
    else
    {
        REG_BLDY = 0;
    }
    */
    REG_BLDY = 0;
}

static void CreateBlocksSprites(u32 indexOfHollowPiece) {
    u32 i;
    u32 x;
    u32 y;
    u32 spriteIndex;
    u32 spriteId;
    u16 currentPermutation;
    u16 currentOrientation;
    struct Sprite *currentSprite;

    for (i = 0; i < SLIDING_NUM_BLOCKS; i++) {
        spriteId = CreateSprite(&sSpriteTemplate_Blocks, sSlidingBlocksXs[i], sSlidingBlocksYs[i], 1);
        sSlidingBlocksGfxManager->blocksSprites[i] = &gSprites[spriteId];
        currentSprite = &gSprites[spriteId];
        currentSprite->oam.tileNum = i * 16;
        currentSprite->oam.matrixNum = AllocOamMatrix();
        StartSpriteAffineAnim(currentSprite, 0);
    }
    if (indexOfHollowPiece < SLIDING_NUM_BLOCKS) {
        sSlidingBlocksGfxManager->blocksSprites[indexOfHollowPiece]->invisible = TRUE;
    }
    sSlidingBlocksGfxManager->hollowSpriteIndex = indexOfHollowPiece;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            spriteIndex = y * 4 + x;
            currentPermutation = sSlidingBlocksState->blocksCurrentLayout.blocksPermutation[y][x];
            currentOrientation = sSlidingBlocksState->blocksCurrentLayout.blocksOrientation[y][x];
            currentSprite = sSlidingBlocksGfxManager->blocksSprites[currentPermutation];
            currentSprite->x = sSlidingBlocksXs[spriteIndex];
            currentSprite->y = sSlidingBlocksYs[spriteIndex];
            switch (currentOrientation) {
                case DIR_NORTH:
                    break;
                case DIR_EAST:
                    StartSpriteAffineAnim(currentSprite, TILEANIM_BE_CLOCKWISE);
                    break;
                case DIR_SOUTH:
                    StartSpriteAffineAnim(currentSprite, TILEANIM_BE_FLIPPED);
                    break;
                case DIR_WEST:
                    StartSpriteAffineAnim(currentSprite, TILEANIM_BE_COUNTERCLOCKWISE);
                    break;
            }
            if (indexOfHollowPiece < SLIDING_NUM_BLOCKS && currentSprite == sSlidingBlocksGfxManager->blocksSprites[indexOfHollowPiece]) {
                SetArrowsSpritePosition(currentSprite->x, currentSprite->y);
            }
            if (x == 0 && y == 0) {
                SetHandSpritePosition(currentSprite->x, currentSprite->y);
            }
        }
    }
}

static void CreateArrowsAndHandSprite(void) {
    s32 spriteId;

    spriteId = CreateSprite(&sSpriteTemplate_Arrows, 0x10, 0x68, 0);
    sSlidingBlocksGfxManager->arrowsSprite = &gSprites[spriteId];

    spriteId = CreateSprite(&sSpriteTemplate_Hand, 0x10, 0x68, 0);
    sSlidingBlocksGfxManager->handSprite = &gSprites[spriteId];
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

static void SetHandSpritePosition(s16 x, s16 y) {
    sSlidingBlocksGfxManager->handSprite->x = x;
    sSlidingBlocksGfxManager->handSprite->y = y;
}

static void SetHandSpriteVisible(bool32 isVisible) {
    sSlidingBlocksGfxManager->handSprite->invisible = !isVisible;
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
    u16 hollowIndexX;
    u16 hollowIndexY;
    u32 indexOfHollowSprite;

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
        LoadColor(RGB(30, 30, 31), pal);
        LoadUserWindowGfx2(0, 0x00A, 0xD0);
        LoadStdWindowGfxOnBg(0, 0x001, 0xF0);

        SetBgTilemapBuffer(0, ptr->bg0TilemapBuffer);
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 2, 32, 30);
        CopyBgTilemapBufferToVram(1);

        LoadPalette(GetTextWindowPalette(2), 0xE0, 0x20);
        PutWindowTilemap(1);

        CopyBgTilemapBufferToVram(0);

        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | 0x20 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        //SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BD | BLDCNT_EFFECT_DARKEN);
        LoadSpriteGraphicsAndAllocateManager();
        CreateArrowsAndHandSprite();
        hollowIndexX = sSlidingBlocksState->blocksCurrentLayout.hollowIndex[INDEX_X];
        hollowIndexY = sSlidingBlocksState->blocksCurrentLayout.hollowIndex[INDEX_Y];
        indexOfHollowSprite = sSlidingBlocksState->blocksCurrentLayout.blocksPermutation[hollowIndexY][hollowIndexX];
        CreateBlocksSprites(indexOfHollowSprite);

        if (CanSetControlMode(CONTROLMODE_ARROWS)) {
            SetControlMode(CONTROLMODE_ARROWS);
        } else {
            SetControlMode(CONTROLMODE_CURSOR);
        }

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

static void SlidingBlocks_PrintControlsText(const u8 *str) {
    u32 x;
    u8 textColor[3];
    x = (240 - GetStringWidth(FONT_SMALL, str, 0)) / 2;
    textColor[0] = TEXT_COLOR_TRANSPARENT;
    textColor[1] = TEXT_COLOR_WHITE;
    textColor[2] = TEXT_COLOR_DARK_GRAY;
    AddTextPrinterParameterized3(1, FONT_SMALL, x, 0, textColor, 0, str);
}

// Winning conditions defined starting from here

static bool32 WinCondition_AllCorrectPlaces(const struct SlidingBlocksLayout *layout) {
    u32 x;
    u32 y;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            if (layout->blocksPermutation[y][x] != y * 4 + x)
                return FALSE;
        }
    }
    return TRUE;
}

static bool32 WinCondition_AllCorrectOrientations(const struct SlidingBlocksLayout *layout) {
    u32 x;
    u32 y;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            if (layout->blocksOrientation[y][x] != DIR_NORTH)
                return FALSE;
        }
    }
    return TRUE;
}

static bool32 WinCondition_AllCorrectPlacesAndOrientations(const struct SlidingBlocksLayout *layout) {
    return WinCondition_AllCorrectPlaces(layout) && WinCondition_AllCorrectOrientations(layout);
}

static bool32 WinCondition_NeverWin(const struct SlidingBlocksLayout *layout) {
    return FALSE;
}
