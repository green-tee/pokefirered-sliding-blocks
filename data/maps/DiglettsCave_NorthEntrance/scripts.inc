DiglettsCave_NorthEntrance_MapScripts::
# 2 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, DiglettsCave_NorthEntrance_OnLoad
	.byte 0


DiglettsCave_NorthEntrance_OnLoad::
# 6 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	goto_if_set FLAG_SOLVED_WHIRLPOOL_ISLANDS, DiglettsCave_NorthEntrance_OnLoad_2
DiglettsCave_NorthEntrance_OnLoad_1:
# 9 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	goto_if_set FLAG_SOLVED_EUSINE, DiglettsCave_NorthEntrance_OnLoad_5
DiglettsCave_NorthEntrance_OnLoad_4:
# 12 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	goto_if_unset FLAG_SOLVED_LUGIA, DiglettsCave_NorthEntrance_OnLoad_7
	return

DiglettsCave_NorthEntrance_OnLoad_2:
# 7 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	call DiglettsCave_NorthEntrance_EventScript_ClearPuzzleWhirlpoolIslands
	goto DiglettsCave_NorthEntrance_OnLoad_1

DiglettsCave_NorthEntrance_OnLoad_5:
# 10 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	call DiglettsCave_NorthEntrance_EventScript_ClearPuzzleEusine
	goto DiglettsCave_NorthEntrance_OnLoad_4

DiglettsCave_NorthEntrance_OnLoad_7:
# 13 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	call DiglettsCave_NorthEntrance_EventScript_SetPuzzleLugia
	return


DiglettsCave_NorthEntrance_EventScript_FloorSign::
# 18 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	msgbox DiglettsCave_NorthEntrance_Text_FloorName, MSGBOX_NPC
	return


DiglettsCave_NorthEntrance_EventScript_PuzzleWhirlpoolIslands::
# 22 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	goto_if_unset FLAG_SOLVED_WHIRLPOOL_ISLANDS, DiglettsCave_NorthEntrance_EventScript_PuzzleWhirlpoolIslands_1
	return

DiglettsCave_NorthEntrance_EventScript_PuzzleWhirlpoolIslands_1:
# 23 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	lockall
# 24 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	playbgm MUS_PUZZLE, 0
# 25 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_WHIRLPOOL_ISLANDS
# 26 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	fadedefaultbgm
# 27 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_NorthEntrance_EventScript_PuzzleWhirlpoolIslands_4
DiglettsCave_NorthEntrance_EventScript_PuzzleWhirlpoolIslands_3:
# 34 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_NorthEntrance_EventScript_PuzzleWhirlpoolIslands_4:
# 28 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setflag FLAG_SOLVED_WHIRLPOOL_ISLANDS
# 29 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	removeobject VAR_LAST_TALKED
# 30 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	playse SE_UNLOCK
# 31 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	call DiglettsCave_NorthEntrance_EventScript_ClearPuzzleWhirlpoolIslands
# 32 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	special DrawWholeMapView
	goto DiglettsCave_NorthEntrance_EventScript_PuzzleWhirlpoolIslands_3


DiglettsCave_NorthEntrance_EventScript_PuzzleEusine::
# 39 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	goto_if_unset FLAG_SOLVED_EUSINE, DiglettsCave_NorthEntrance_EventScript_PuzzleEusine_1
	return

DiglettsCave_NorthEntrance_EventScript_PuzzleEusine_1:
# 40 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	lockall
# 41 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	playbgm MUS_PUZZLE, 0
# 42 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_EUSINE
# 43 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	fadedefaultbgm
# 44 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_NorthEntrance_EventScript_PuzzleEusine_4
DiglettsCave_NorthEntrance_EventScript_PuzzleEusine_3:
# 51 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_NorthEntrance_EventScript_PuzzleEusine_4:
# 45 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setflag FLAG_SOLVED_EUSINE
# 46 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	removeobject VAR_LAST_TALKED
# 47 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	playse SE_UNLOCK
# 48 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	call DiglettsCave_NorthEntrance_EventScript_ClearPuzzleEusine
# 49 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	special DrawWholeMapView
	goto DiglettsCave_NorthEntrance_EventScript_PuzzleEusine_3


DiglettsCave_NorthEntrance_EventScript_PuzzleLugia::
# 56 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	goto_if_unset FLAG_SOLVED_LUGIA, DiglettsCave_NorthEntrance_EventScript_PuzzleLugia_1
	return

DiglettsCave_NorthEntrance_EventScript_PuzzleLugia_1:
# 57 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	lockall
# 58 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	playbgm MUS_PUZZLE, 0
# 59 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_LUGIA
# 60 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	fadedefaultbgm
# 61 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_NorthEntrance_EventScript_PuzzleLugia_4
DiglettsCave_NorthEntrance_EventScript_PuzzleLugia_3:
# 68 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_NorthEntrance_EventScript_PuzzleLugia_4:
# 62 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setflag FLAG_SOLVED_LUGIA
# 63 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	removeobject VAR_LAST_TALKED
# 64 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	playse SE_UNLOCK
# 65 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	call DiglettsCave_NorthEntrance_EventScript_ClearPuzzleLugia
# 66 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	special DrawWholeMapView
	goto DiglettsCave_NorthEntrance_EventScript_PuzzleLugia_3


DiglettsCave_NorthEntrance_EventScript_ClearPuzzleWhirlpoolIslands::
# 73 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 38, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 74 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 38, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 75 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 38, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 76 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 39, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 77 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 39, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 78 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 39, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 79 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 40, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 80 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 40, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 81 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 40, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 82 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 41, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 83 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 41, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 84 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 41, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 85 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 22, 41, METATILE_Lab_PuzzlePalace_Corner_FacingRight, TRUE
	return


DiglettsCave_NorthEntrance_EventScript_ClearPuzzleEusine::
# 89 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 19, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 90 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 19, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 91 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 19, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 92 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 93 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 94 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 95 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 21, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 96 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 21, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 97 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 21, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 98 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 22, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 99 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 22, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 100 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 22, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 101 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 22, 22, METATILE_Lab_PuzzlePalace_Corner_FacingRight, TRUE
	return


DiglettsCave_NorthEntrance_EventScript_ClearPuzzleLugia::
# 105 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 1, METATILE_Lab_PuzzlePalace_DoorTopLeft, TRUE
# 106 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 1, METATILE_Lab_PuzzlePalace_DoorTop, TRUE
# 107 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 1, METATILE_Lab_PuzzlePalace_DoorTopRight, TRUE
# 108 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 2, METATILE_Lab_PuzzlePalace_AboveDoorLeft, TRUE
# 109 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 2, METATILE_Lab_PuzzlePalace_AboveDoor, TRUE
# 110 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 2, METATILE_Lab_PuzzlePalace_AboveDoorRight, TRUE
# 111 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 3, METATILE_Lab_PuzzlePalace_DoorLeft, TRUE
# 112 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 3, METATILE_Lab_PuzzlePalace_Upstairs, FALSE
# 113 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 3, METATILE_Lab_PuzzlePalace_DoorRight, TRUE
	return


DiglettsCave_NorthEntrance_EventScript_SetPuzzleLugia::
# 117 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 1, METATILE_Building_Void, TRUE
# 118 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 1, METATILE_Building_Void, TRUE
# 119 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 1, METATILE_Building_Void, TRUE
# 120 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 2, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 121 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 2, METATILE_Lab_PuzzlePalace_Wall_TopPuzzle, TRUE
# 122 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 2, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 123 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 3, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 124 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 3, METATILE_Lab_PuzzlePalace_Wall_BottomPuzzle, TRUE
# 125 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 3, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return

