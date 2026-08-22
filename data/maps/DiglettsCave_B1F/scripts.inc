DiglettsCave_B1F_MapScripts::
# 2 "data/maps/DiglettsCave_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, DiglettsCave_B1F_OnLoad
	.byte 0


DiglettsCave_B1F_OnLoad::
# 6 "data/maps/DiglettsCave_B1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_HO_OH_BACK_SHINY, DiglettsCave_B1F_OnLoad_1
	return

DiglettsCave_B1F_OnLoad_1:
# 7 "data/maps/DiglettsCave_B1F/scripts.pory"
	call DiglettsCave_B1F_EventScript_SetPuzzleHoOhBackShiny
	return


DiglettsCave_B1F_EventScript_FloorSign::
# 12 "data/maps/DiglettsCave_B1F/scripts.pory"
	msgbox DiglettsCave_B1F_Text_FloorName, MSGBOX_SIGN
	return


DiglettsCave_B1F_EventScript_PuzzleHoOhBackShiny::
# 16 "data/maps/DiglettsCave_B1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_HO_OH_BACK_SHINY, DiglettsCave_B1F_EventScript_PuzzleHoOhBackShiny_1
	return

DiglettsCave_B1F_EventScript_PuzzleHoOhBackShiny_1:
# 17 "data/maps/DiglettsCave_B1F/scripts.pory"
	lockall
# 18 "data/maps/DiglettsCave_B1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_HO_OH_BACK_SHINY
# 19 "data/maps/DiglettsCave_B1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_B1F_EventScript_PuzzleHoOhBackShiny_4
DiglettsCave_B1F_EventScript_PuzzleHoOhBackShiny_3:
# 26 "data/maps/DiglettsCave_B1F/scripts.pory"
	releaseall
	return

DiglettsCave_B1F_EventScript_PuzzleHoOhBackShiny_4:
# 20 "data/maps/DiglettsCave_B1F/scripts.pory"
	setflag FLAG_SOLVED_HO_OH_BACK_SHINY
# 21 "data/maps/DiglettsCave_B1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 22 "data/maps/DiglettsCave_B1F/scripts.pory"
	playse SE_UNLOCK
# 23 "data/maps/DiglettsCave_B1F/scripts.pory"
	call DiglettsCave_B1F_EventScript_ClearPuzzleHoOhBackShiny
# 24 "data/maps/DiglettsCave_B1F/scripts.pory"
	special DrawWholeMapView
	goto DiglettsCave_B1F_EventScript_PuzzleHoOhBackShiny_3


DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable1::
# 31 "data/maps/DiglettsCave_B1F/scripts.pory"
	lockall
# 32 "data/maps/DiglettsCave_B1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_HO_OH_BACK_SHINY_UNSOLVABLE_1
# 33 "data/maps/DiglettsCave_B1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable1_2
DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable1_1:
# 37 "data/maps/DiglettsCave_B1F/scripts.pory"
	releaseall
	return

DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable1_2:
# 34 "data/maps/DiglettsCave_B1F/scripts.pory"
	msgbox DiglettsCave_B1F_Text_ThisPuzzleIsUnsolvable, MSGBOX_DEFAULT
# 35 "data/maps/DiglettsCave_B1F/scripts.pory"
	closemessage
	goto DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable1_1


DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable2::
# 41 "data/maps/DiglettsCave_B1F/scripts.pory"
	lockall
# 42 "data/maps/DiglettsCave_B1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_HO_OH_BACK_SHINY_UNSOLVABLE_2
# 43 "data/maps/DiglettsCave_B1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable2_2
DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable2_1:
# 47 "data/maps/DiglettsCave_B1F/scripts.pory"
	releaseall
	return

DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable2_2:
# 44 "data/maps/DiglettsCave_B1F/scripts.pory"
	msgbox DiglettsCave_B1F_Text_ThisPuzzleIsUnsolvable, MSGBOX_DEFAULT
# 45 "data/maps/DiglettsCave_B1F/scripts.pory"
	closemessage
	goto DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable2_1


DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable3::
# 51 "data/maps/DiglettsCave_B1F/scripts.pory"
	lockall
# 52 "data/maps/DiglettsCave_B1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_HO_OH_BACK_SHINY_UNSOLVABLE_3
# 53 "data/maps/DiglettsCave_B1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable3_2
DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable3_1:
# 57 "data/maps/DiglettsCave_B1F/scripts.pory"
	releaseall
	return

DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable3_2:
# 54 "data/maps/DiglettsCave_B1F/scripts.pory"
	msgbox DiglettsCave_B1F_Text_ThisPuzzleIsUnsolvable, MSGBOX_DEFAULT
# 55 "data/maps/DiglettsCave_B1F/scripts.pory"
	closemessage
	goto DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable3_1


DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable4::
# 61 "data/maps/DiglettsCave_B1F/scripts.pory"
	lockall
# 62 "data/maps/DiglettsCave_B1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_HO_OH_BACK_SHINY_UNSOLVABLE_4
# 63 "data/maps/DiglettsCave_B1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable4_2
DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable4_1:
# 67 "data/maps/DiglettsCave_B1F/scripts.pory"
	releaseall
	return

DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable4_2:
# 64 "data/maps/DiglettsCave_B1F/scripts.pory"
	msgbox DiglettsCave_B1F_Text_ThisPuzzleIsUnsolvable, MSGBOX_DEFAULT
# 65 "data/maps/DiglettsCave_B1F/scripts.pory"
	closemessage
	goto DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable4_1


DiglettsCave_B1F_EventScript_ClearPuzzleHoOhBackShiny::
# 71 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 7, 12, METATILE_Lab_PuzzlePalace_DoorTopLeft, TRUE
# 72 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 8, 12, METATILE_Lab_PuzzlePalace_DoorTop, TRUE
# 73 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 9, 12, METATILE_Lab_PuzzlePalace_DoorTopRight, TRUE
# 74 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 7, 13, METATILE_Lab_PuzzlePalace_AboveDoorLeft, TRUE
# 75 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 8, 13, METATILE_Lab_PuzzlePalace_AboveDoor, TRUE
# 76 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 9, 13, METATILE_Lab_PuzzlePalace_AboveDoorRight, TRUE
# 77 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 7, 14, METATILE_Lab_PuzzlePalace_DoorLeft, TRUE
# 78 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 8, 14, METATILE_Lab_PuzzlePalace_Upstairs, FALSE
# 79 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 9, 14, METATILE_Lab_PuzzlePalace_DoorRight, TRUE
# 80 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 7, 15, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 81 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 9, 15, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 82 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 8, 16, METATILE_Lab_PuzzlePalace_TileArrowUp, FALSE
	return


DiglettsCave_B1F_EventScript_SetPuzzleHoOhBackShiny::
# 86 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 7, 12, METATILE_Building_Void, TRUE
# 87 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 8, 12, METATILE_Building_Void, TRUE
# 88 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 9, 12, METATILE_Building_Void, TRUE
# 89 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 7, 13, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 90 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 8, 13, METATILE_Lab_PuzzlePalace_Wall_TopPuzzle, TRUE
# 91 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 9, 13, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 92 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 7, 14, METATILE_Lab_PuzzlePalace_SmallTree_Top_Wall_Bottom, TRUE
# 93 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 8, 14, METATILE_Lab_PuzzlePalace_Wall_BottomPuzzle, TRUE
# 94 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 9, 14, METATILE_Lab_PuzzlePalace_SmallTree_Top_Wall_Bottom, TRUE
# 95 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 7, 15, METATILE_Lab_PuzzlePalace_SmallTree_Bottom, TRUE
# 96 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 9, 15, METATILE_Lab_PuzzlePalace_SmallTree_Bottom, TRUE
# 97 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 8, 16, METATILE_Lab_PuzzlePalace_Tile, FALSE
	return

