/*
#include "global.h"
#include "constants/field_weather.h"
#include "field_weather.h"
#include "gba/io_reg.h"
#include "gba/types.h"
#include "gba/defines.h"
#include "main.h"
#include "bg.h"
#include "main_menu.h"
#include "window.h"
#include "palette.h"
#include "task.h"
#include "malloc.h"
#include "gba/macro.h"
#include "menu_helpers.h"
#include "menu.h"
#include "scanline_effect.h"
#include "sprite.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "sound.h"
#include "sprite.h"
#include "graphics.h"
#include "gpu_regs.h"
#include "custom_title_screen.h"

#define TAG_PRESS_START 0x1000

#define SUBSPRITE_SHAPE(dim) \
    .shape = SPRITE_SHAPE(dim), .size = SPRITE_SIZE(dim)

#define SUBSPRITE(_x, _y, dim, offset, prio) \
    {                                        \
        .x = _x,                             \
        .y = _y,                             \
        SUBSPRITE_SHAPE(dim),                \
        .tileOffset = offset,                \
        .priority = prio,                    \
    }

#define SUBSPRITE_TABLE_ENTRY(x) {ARRAY_COUNT(x), x}

#define TITLE_TEXT_INITIAL_OFFSET 101
#define STEP_FRAME_DURATION 36

struct CustomTitleState
{
    MainCallback savedCallback;
    u8 loadState;
};

static EWRAM_DATA struct CustomTitleState *sCustomTitleState = NULL;
static EWRAM_DATA u8 *sBg0TilemapBuffer = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

static const struct BgTemplate sCustomTitleBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .priority = 2
    }
};

static const u32 sCustomTitleTiles[] = INCBIN_U32("graphics/custom_title/night/tiles.4bpp.smol");
static const u32 sCustomTitleTilemap[] = INCBIN_U32("graphics/custom_title/night/map.bin.smolTM");
static const u16 sCustomTitlePalette[] = INCBIN_U16("graphics/custom_title/night/palette_00.gbapal", "graphics/custom_title/night/palette_01.gbapal");

static const u32 sCustomTitleTextTiles[] = INCBIN_U32("graphics/custom_title/text/tiles.4bpp.smol");
static const u32 sCustomTitleTextTilemap[] = INCBIN_U32("graphics/custom_title/text/map.bin.smolTM");
static const u16 sCustomTitleTextPalette[] = INCBIN_U16("graphics/custom_title/text/palette_02.gbapal");

static const u32 sCustomTitlePressStartGfx[] = INCBIN_U32("graphics/custom_title/press_start.4bpp");
static const u16 sCustomTitlePressStartPal[] = INCBIN_U16("graphics/custom_title/press_start.gbapal");

const struct Subsprite sCustomTitlePressStartSubsprites[] = {
    SUBSPRITE(-32, 0, 32x8, 0, 0),
    SUBSPRITE( 0,  0, 32x8, 4, 0),
    SUBSPRITE( 32, 0, 32x8, 8, 0),
};

const struct SubspriteTable sCustomTitlePressStartSubspriteTable[] = {
    SUBSPRITE_TABLE_ENTRY(sCustomTitlePressStartSubsprites),
};

enum FontColor
{
    FONT_WHITE,
    FONT_RED
};
static const u8 sCustomTitleWindowFontColors[][3] =
{
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,      TEXT_COLOR_DARK_GRAY},
    [FONT_RED]    = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED,        TEXT_COLOR_LIGHT_GRAY},
};

// Callbacks for the Title Screen
static void CustomTitle_SetupCB(void);
static void CustomTitle_MainCB(void);
static void CustomTitle_VBlankCB(void);

//Custom Title tasks
static void Task_CustomTitleWaitFadeIn(u8 taskId);
static void Task_CustomTitleMainInput(u8 taskId);
static void Task_CustomTitleWaitFadeAndBail(u8 taskId);
static void Task_CustomTitleWaitFadeAndExitGracefully(u8 taskId);

//Custom Title helper functions
static void CustomTitle_Init(MainCallback callback);
static void CustomTitle_ResetGpuRegsAndBgs(void);
static bool8 CustomTitle_InitBgs(void);
static void CustomTitle_FadeAndBail(void);
static bool8 CustomTitle_LoadGraphics(void);
static void CustomTitle_FreeResources(void);
static void SpriteCB_HandleBlink(struct Sprite *sprite);

static const struct OamData sCustomTitlePressStartOam = {
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .size = SPRITE_SIZE(32x8),
    .priority = 0,
    .paletteNum = 0,
};

static const struct SpriteTemplate sCustomTitlePressStartTemplate = {
    .tileTag = TAG_PRESS_START,
    .paletteTag = TAG_PRESS_START,
    .oam = &sCustomTitlePressStartOam,
    .anims = gDummySpriteAnimTable,
    .callback = SpriteCB_HandleBlink,
};

static const struct SpriteSheet sSpriteSheet_CustomTitlePressStart = {
    .data = sCustomTitlePressStartGfx,
    .size = 384,
    .tag = TAG_PRESS_START,
};
static const struct SpritePalette sSpritePalette_CustomTitlePressStart = {
    .data = sCustomTitlePressStartPal,
    .tag = TAG_PRESS_START
};

static void CB2_GoToMainMenu(void)
{
    if (!UpdatePaletteFade())
        SetMainCallback2(CB2_InitMainMenu);
}

void CB2_InitCustomTitleScreen(void)
{
    FadeOutBGM(2);
    FadeScreen(FADE_TO_BLACK, 0);
    CustomTitle_Init(CB2_GoToMainMenu);
}

static void CustomTitle_Init(MainCallback callback)
{
    sCustomTitleState = AllocZeroed(sizeof(struct CustomTitleState));
    if (sCustomTitleState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    sCustomTitleState->loadState = 0;
    sCustomTitleState->savedCallback = callback;

    SetMainCallback2(CustomTitle_SetupCB);
}

static void CustomTitle_ResetGpuRegsAndBgs(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    ChangeBgX(2, 0, BG_COORD_SET);
    ChangeBgY(2, 0, BG_COORD_SET);
    ChangeBgX(3, 0, BG_COORD_SET);
    ChangeBgY(3, 0, BG_COORD_SET);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, DISPLAY_WIDTH));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(DISPLAY_HEIGHT - 32, DISPLAY_HEIGHT));
    SetGpuReg(REG_OFFSET_WIN1H, 0);
    SetGpuReg(REG_OFFSET_WIN1V, 0);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_ALL & ~WININ_WIN0_BG0);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_ALL);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP | DISPCNT_WIN0_ON);
    CpuFill16(0, (void*)VRAM, VRAM_SIZE);
    CpuFill32(0, (void*)OAM, OAM_SIZE);
}

static void CustomTitle_SetupCB(void)
{
    switch (gMain.state)
    {
    case 0:
        CustomTitle_ResetGpuRegsAndBgs();
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (CustomTitle_InitBgs())
        {
            sCustomTitleState->loadState = 0;
            gMain.state++;
        }
        else
        {
            CustomTitle_FadeAndBail();
            return;
        }
        break;
    case 3:
        if (CustomTitle_LoadGraphics() == TRUE)
        {
            gMain.state++;
        }
        break;
    case 4:
        ChangeBgY(0, Q_8_8(0), BG_COORD_SET);
        gMain.state++;
        break;
    case 5:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        CreateTask(Task_CustomTitleWaitFadeIn, 0);
        u32 id = CreateSprite(&sCustomTitlePressStartTemplate, 108, 120, 0);
        struct Sprite* pressStartPtr = &gSprites[id];
        SetSubspriteTables(pressStartPtr, sCustomTitlePressStartSubspriteTable);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        SetVBlankCallback(CustomTitle_VBlankCB);
        SetMainCallback2(CustomTitle_MainCB);
        break;
    }
}

static void CustomTitle_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void CustomTitle_VBlankCB(void)
{
    LoadOam();
    ScanlineEffect_InitHBlankDmaTransfer();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Task_CustomTitleWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_CustomTitleMainInput;
}

static void Task_CustomTitleMainInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON) || JOY_NEW(START_BUTTON))
    {
        FadeOutBGM(2);
        PlaySE(SE_M_CUT);
        FadeScreen(FADE_TO_WHITE, 0);
        gTasks[taskId].func = Task_CustomTitleWaitFadeAndExitGracefully;
    }
}

static void Task_CustomTitleWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sCustomTitleState->savedCallback);
        CustomTitle_FreeResources();
        DestroyTask(taskId);
    }
}

static void Task_CustomTitleWaitFadeAndExitGracefully(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sCustomTitleState->savedCallback);
        CustomTitle_FreeResources();
        DestroyTask(taskId);
    }
}
#define TILEMAP_BUFFER_SIZE (1024 * 2)
static bool8 CustomTitle_InitBgs(void)
{
    ResetAllBgsCoordinates();

    sBg1TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);

    if (sBg1TilemapBuffer == NULL)
    {
        return FALSE;
    }

    sBg0TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);

    if (sBg0TilemapBuffer == NULL) {
        return  FALSE; 
    }

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sCustomTitleBgTemplates, NELEMS(sCustomTitleBgTemplates));

    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    SetBgTilemapBuffer(0, sBg0TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(0);

    ShowBg(0);
    ShowBg(1);

    return TRUE;
}
#undef TILEMAP_BUFFER_SIZE

static void CustomTitle_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_CustomTitleWaitFadeAndBail, 0);
    SetVBlankCallback(CustomTitle_VBlankCB);
    SetMainCallback2(CustomTitle_MainCB);
}

static bool8 CustomTitle_LoadGraphics(void)
{
    switch (sCustomTitleState->loadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndLoadBgGfxUsingHeap(1, sCustomTitleTiles, 0, 0, 0);
        DecompressAndLoadBgGfxUsingHeap(0, sCustomTitleTextTiles, 0, 0, 0);
        sCustomTitleState->loadState++;
        break;
    case 1:
        DecompressAndCopyToBgTilemapBuffer(1, sCustomTitleTilemap, BG_SCREEN_SIZE, 0);
        DecompressAndCopyToBgTilemapBuffer(0, sCustomTitleTextTilemap, BG_SCREEN_SIZE, 0);
        sCustomTitleState->loadState++;
        break;
    case 2:
        LoadPalette(sCustomTitlePalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP * 2);
        LoadPalette(sCustomTitleTextPalette, BG_PLTT_ID(2), PLTT_SIZE_4BPP);
        LoadPalette(gMessageBox_Pal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        sCustomTitleState->loadState++;
    case 3:
        LoadSpriteSheet(&sSpriteSheet_CustomTitlePressStart);
        LoadSpritePalette(&sSpritePalette_CustomTitlePressStart);
    default:
        sCustomTitleState->loadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void SpriteCB_HandleBlink(struct Sprite *sprite)
{
    s16 *frameCounter = &sprite->data[7];

    if (++(*frameCounter) % STEP_FRAME_DURATION < STEP_FRAME_DURATION/2)
        sprite->invisible = TRUE;
    else
        sprite->invisible = FALSE;
}

static void CustomTitle_FreeResources(void)
{
    if (sCustomTitleState != NULL)
    {
        Free(sCustomTitleState);
    }
    if (sBg1TilemapBuffer != NULL)
    {
        Free(sBg1TilemapBuffer);
    }

    if (sBg0TilemapBuffer != NULL)
    {
        Free(sBg0TilemapBuffer);
    }
    FreeAllWindowBuffers();
    ResetSpriteData();
}
//*/
