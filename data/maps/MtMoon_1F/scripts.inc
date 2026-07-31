MtMoon_1F_MapScripts::
# 2 "data/maps/MtMoon_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MtMoon_1F_OnLoad
	.byte 0


MtMoon_1F_OnLoad::
# 6 "data/maps/MtMoon_1F/scripts.pory"
	goto_if_set FLAG_SOLVED_NUMBERS_1, MtMoon_1F_OnLoad_2
MtMoon_1F_OnLoad_1:
# 9 "data/maps/MtMoon_1F/scripts.pory"
	goto_if_set SLIDING_LAYOUT_NUMBERS_1234, MtMoon_1F_OnLoad_5
MtMoon_1F_OnLoad_4:
# 12 "data/maps/MtMoon_1F/scripts.pory"
	goto_if_set SLIDING_LAYOUT_NUMBERS_3X3, MtMoon_1F_OnLoad_7
	return

MtMoon_1F_OnLoad_2:
# 7 "data/maps/MtMoon_1F/scripts.pory"
	call MtMoon_1F_EventScript_ClearPuzzleNumbers1
	goto MtMoon_1F_OnLoad_1

MtMoon_1F_OnLoad_5:
# 10 "data/maps/MtMoon_1F/scripts.pory"
	call MtMoon_1F_EventScript_ClearPuzzleNumbers1234
	goto MtMoon_1F_OnLoad_4

MtMoon_1F_OnLoad_7:
# 13 "data/maps/MtMoon_1F/scripts.pory"
	call MtMoon_1F_EventScript_ClearPuzzleNumbers3x3
	return


MtMoon_1F_EventScript_PuzzleNumbers1::
# 18 "data/maps/MtMoon_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_NUMBERS_1, MtMoon_1F_EventScript_PuzzleNumbers1_1
	return

MtMoon_1F_EventScript_PuzzleNumbers1_1:
# 19 "data/maps/MtMoon_1F/scripts.pory"
	lockall
# 20 "data/maps/MtMoon_1F/scripts.pory"
	msgbox MtMoon_1F_Text_UseDPad, MSGBOX_DEFAULT
# 21 "data/maps/MtMoon_1F/scripts.pory"
	closemessage
# 22 "data/maps/MtMoon_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_NUMBERS_1
# 23 "data/maps/MtMoon_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne MtMoon_1F_EventScript_PuzzleNumbers1_4
MtMoon_1F_EventScript_PuzzleNumbers1_3:
# 28 "data/maps/MtMoon_1F/scripts.pory"
	releaseall
	return

MtMoon_1F_EventScript_PuzzleNumbers1_4:
# 24 "data/maps/MtMoon_1F/scripts.pory"
	playse SE_UNLOCK
# 25 "data/maps/MtMoon_1F/scripts.pory"
	call MtMoon_1F_EventScript_ClearPuzzleNumbers1
# 26 "data/maps/MtMoon_1F/scripts.pory"
	special DrawWholeMapView
	goto MtMoon_1F_EventScript_PuzzleNumbers1_3


MtMoon_1F_EventScript_PuzzleNumbers1234::
# 33 "data/maps/MtMoon_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_NUMBERS_1234, MtMoon_1F_EventScript_PuzzleNumbers1234_1
	return

MtMoon_1F_EventScript_PuzzleNumbers1234_1:
# 34 "data/maps/MtMoon_1F/scripts.pory"
	lockall
# 35 "data/maps/MtMoon_1F/scripts.pory"
	msgbox MtMoon_1F_Text_CantMoveBorderedBlocks, MSGBOX_DEFAULT
# 36 "data/maps/MtMoon_1F/scripts.pory"
	closemessage
# 37 "data/maps/MtMoon_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_NUMBERS_1234
# 38 "data/maps/MtMoon_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne MtMoon_1F_EventScript_PuzzleNumbers1234_4
MtMoon_1F_EventScript_PuzzleNumbers1234_3:
# 43 "data/maps/MtMoon_1F/scripts.pory"
	releaseall
	return

MtMoon_1F_EventScript_PuzzleNumbers1234_4:
# 39 "data/maps/MtMoon_1F/scripts.pory"
	playse SE_UNLOCK
# 40 "data/maps/MtMoon_1F/scripts.pory"
	call MtMoon_1F_EventScript_ClearPuzzleNumbers1234
# 41 "data/maps/MtMoon_1F/scripts.pory"
	special DrawWholeMapView
	goto MtMoon_1F_EventScript_PuzzleNumbers1234_3


MtMoon_1F_EventScript_PuzzleNumbers3x3::
# 48 "data/maps/MtMoon_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_NUMBERS_3X3, MtMoon_1F_EventScript_PuzzleNumbers3x3_1
	return

MtMoon_1F_EventScript_PuzzleNumbers3x3_1:
# 49 "data/maps/MtMoon_1F/scripts.pory"
	lockall
# 50 "data/maps/MtMoon_1F/scripts.pory"
	msgbox MtMoon_1F_Text_Complete3x3, MSGBOX_DEFAULT
# 51 "data/maps/MtMoon_1F/scripts.pory"
	closemessage
# 52 "data/maps/MtMoon_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_NUMBERS_3X3
# 53 "data/maps/MtMoon_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne MtMoon_1F_EventScript_PuzzleNumbers3x3_4
MtMoon_1F_EventScript_PuzzleNumbers3x3_3:
# 58 "data/maps/MtMoon_1F/scripts.pory"
	releaseall
	return

MtMoon_1F_EventScript_PuzzleNumbers3x3_4:
# 54 "data/maps/MtMoon_1F/scripts.pory"
	playse SE_UNLOCK
# 55 "data/maps/MtMoon_1F/scripts.pory"
	call MtMoon_1F_EventScript_ClearPuzzleNumbers3x3
# 56 "data/maps/MtMoon_1F/scripts.pory"
	special DrawWholeMapView
	goto MtMoon_1F_EventScript_PuzzleNumbers3x3_3


MtMoon_1F_EventScript_ClearPuzzleNumbers1:
# 63 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 2, 27, METATILE_Building_PuzzlePalace_Tile, FALSE
# 64 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 3, 27, METATILE_Building_PuzzlePalace_Tile, FALSE
# 65 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 4, 27, METATILE_Building_PuzzlePalace_Tile, FALSE
# 66 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 2, 28, METATILE_Building_PuzzlePalace_Tile, FALSE
# 67 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 3, 28, METATILE_Building_PuzzlePalace_Tile, FALSE
# 68 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 4, 28, METATILE_Building_PuzzlePalace_Tile, FALSE
# 69 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 2, 29, METATILE_Building_PuzzlePalace_Tile, FALSE
# 70 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 3, 29, METATILE_Building_PuzzlePalace_Tile, FALSE
# 71 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 4, 29, METATILE_Building_PuzzlePalace_Tile, FALSE
# 72 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 2, 30, METATILE_Building_PuzzlePalace_Tile, FALSE
# 73 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 3, 30, METATILE_Building_PuzzlePalace_Tile, FALSE
# 74 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 4, 30, METATILE_Building_PuzzlePalace_Tile, FALSE
	return


MtMoon_1F_EventScript_ClearPuzzleNumbers1234:
# 78 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 2, 20, METATILE_Building_PuzzlePalace_Tile, FALSE
# 79 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 3, 20, METATILE_Building_PuzzlePalace_Tile, FALSE
# 80 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 4, 20, METATILE_Building_PuzzlePalace_Tile, FALSE
# 81 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 2, 21, METATILE_Building_PuzzlePalace_Tile, FALSE
# 82 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 3, 21, METATILE_Building_PuzzlePalace_Tile, FALSE
# 83 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 4, 21, METATILE_Building_PuzzlePalace_Tile, FALSE
# 84 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 2, 22, METATILE_Building_PuzzlePalace_Tile, FALSE
# 85 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 3, 22, METATILE_Building_PuzzlePalace_Tile, FALSE
# 86 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 4, 22, METATILE_Building_PuzzlePalace_Tile, FALSE
# 87 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 2, 23, METATILE_Building_PuzzlePalace_Tile, FALSE
# 88 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 3, 23, METATILE_Building_PuzzlePalace_Tile, FALSE
# 89 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 4, 23, METATILE_Building_PuzzlePalace_Tile, FALSE
	return


MtMoon_1F_EventScript_ClearPuzzleNumbers3x3:
# 93 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 27, 18, METATILE_Building_PuzzlePalace_TileShaded, FALSE
# 94 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 28, 18, METATILE_Building_PuzzlePalace_Tile, FALSE
# 95 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 29, 18, METATILE_Building_PuzzlePalace_Tile, FALSE
# 96 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 27, 19, METATILE_Building_PuzzlePalace_TileShaded, FALSE
# 97 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 28, 19, METATILE_Building_PuzzlePalace_Tile, FALSE
# 98 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 29, 19, METATILE_Building_PuzzlePalace_Tile, FALSE
# 99 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 27, 20, METATILE_Building_PuzzlePalace_TileShaded, FALSE
# 100 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 28, 20, METATILE_Building_PuzzlePalace_Tile, FALSE
# 101 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 29, 20, METATILE_Building_PuzzlePalace_Tile, FALSE
# 102 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 27, 21, METATILE_Building_PuzzlePalace_TileShaded, FALSE
# 103 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 28, 21, METATILE_Building_PuzzlePalace_Tile, FALSE
# 104 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 29, 21, METATILE_Building_PuzzlePalace_Tile, FALSE
# 105 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 27, 22, METATILE_Building_PuzzlePalace_TileShaded, FALSE
# 106 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 28, 22, METATILE_Building_PuzzlePalace_Tile, FALSE
# 107 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 29, 22, METATILE_Building_PuzzlePalace_Tile, FALSE
	return

