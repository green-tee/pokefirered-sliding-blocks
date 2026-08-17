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


DiglettsCave_B1F_EventScript_PuzzleHoOhBackShiny::
# 12 "data/maps/DiglettsCave_B1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_HO_OH_BACK_SHINY, DiglettsCave_B1F_EventScript_PuzzleHoOhBackShiny_1
	return

DiglettsCave_B1F_EventScript_PuzzleHoOhBackShiny_1:
# 13 "data/maps/DiglettsCave_B1F/scripts.pory"
	lockall
# 14 "data/maps/DiglettsCave_B1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_HO_OH_BACK_SHINY
# 15 "data/maps/DiglettsCave_B1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_B1F_EventScript_PuzzleHoOhBackShiny_4
DiglettsCave_B1F_EventScript_PuzzleHoOhBackShiny_3:
# 22 "data/maps/DiglettsCave_B1F/scripts.pory"
	releaseall
	return

DiglettsCave_B1F_EventScript_PuzzleHoOhBackShiny_4:
# 16 "data/maps/DiglettsCave_B1F/scripts.pory"
	setflag FLAG_SOLVED_HO_OH_BACK_SHINY
# 17 "data/maps/DiglettsCave_B1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 18 "data/maps/DiglettsCave_B1F/scripts.pory"
	playse SE_UNLOCK
# 19 "data/maps/DiglettsCave_B1F/scripts.pory"
	call DiglettsCave_B1F_EventScript_ClearPuzzleHoOhBackShiny
# 20 "data/maps/DiglettsCave_B1F/scripts.pory"
	special DrawWholeMapView
	goto DiglettsCave_B1F_EventScript_PuzzleHoOhBackShiny_3


DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable1::
# 27 "data/maps/DiglettsCave_B1F/scripts.pory"
	lockall
# 28 "data/maps/DiglettsCave_B1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_HO_OH_BACK_SHINY_UNSOLVABLE_1
# 29 "data/maps/DiglettsCave_B1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable1_2
DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable1_1:
# 33 "data/maps/DiglettsCave_B1F/scripts.pory"
	releaseall
	return

DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable1_2:
# 30 "data/maps/DiglettsCave_B1F/scripts.pory"
	msgbox DiglettsCave_B1F_Text_ThisPuzzleIsUnsolvable, MSGBOX_DEFAULT
# 31 "data/maps/DiglettsCave_B1F/scripts.pory"
	closemessage
	goto DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable1_1


DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable2::
# 37 "data/maps/DiglettsCave_B1F/scripts.pory"
	lockall
# 38 "data/maps/DiglettsCave_B1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_HO_OH_BACK_SHINY_UNSOLVABLE_2
# 39 "data/maps/DiglettsCave_B1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable2_2
DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable2_1:
# 43 "data/maps/DiglettsCave_B1F/scripts.pory"
	releaseall
	return

DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable2_2:
# 40 "data/maps/DiglettsCave_B1F/scripts.pory"
	msgbox DiglettsCave_B1F_Text_ThisPuzzleIsUnsolvable, MSGBOX_DEFAULT
# 41 "data/maps/DiglettsCave_B1F/scripts.pory"
	closemessage
	goto DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable2_1


DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable3::
# 47 "data/maps/DiglettsCave_B1F/scripts.pory"
	lockall
# 48 "data/maps/DiglettsCave_B1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_HO_OH_BACK_SHINY_UNSOLVABLE_3
# 49 "data/maps/DiglettsCave_B1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable3_2
DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable3_1:
# 53 "data/maps/DiglettsCave_B1F/scripts.pory"
	releaseall
	return

DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable3_2:
# 50 "data/maps/DiglettsCave_B1F/scripts.pory"
	msgbox DiglettsCave_B1F_Text_ThisPuzzleIsUnsolvable, MSGBOX_DEFAULT
# 51 "data/maps/DiglettsCave_B1F/scripts.pory"
	closemessage
	goto DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable3_1


DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable4::
# 57 "data/maps/DiglettsCave_B1F/scripts.pory"
	lockall
# 58 "data/maps/DiglettsCave_B1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_HO_OH_BACK_SHINY_UNSOLVABLE_4
# 59 "data/maps/DiglettsCave_B1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable4_2
DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable4_1:
# 63 "data/maps/DiglettsCave_B1F/scripts.pory"
	releaseall
	return

DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable4_2:
# 60 "data/maps/DiglettsCave_B1F/scripts.pory"
	msgbox DiglettsCave_B1F_Text_ThisPuzzleIsUnsolvable, MSGBOX_DEFAULT
# 61 "data/maps/DiglettsCave_B1F/scripts.pory"
	closemessage
	goto DiglettsCave_B1F_EventScript_PuzzleHoOhBackShinyUnsolvable4_1


DiglettsCave_B1F_EventScript_ClearPuzzleHoOhBackShiny::
# 67 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 7, 12, METATILE_Lab_PuzzlePalace_DoorTopLeft, TRUE
# 68 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 8, 12, METATILE_Lab_PuzzlePalace_DoorTop, TRUE
# 69 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 9, 12, METATILE_Lab_PuzzlePalace_DoorTopRight, TRUE
# 70 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 7, 13, METATILE_Lab_PuzzlePalace_AboveDoorLeft, TRUE
# 71 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 8, 13, METATILE_Lab_PuzzlePalace_AboveDoor, TRUE
# 72 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 9, 13, METATILE_Lab_PuzzlePalace_AboveDoorRight, TRUE
# 73 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 7, 14, METATILE_Lab_PuzzlePalace_DoorLeft, TRUE
# 74 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 8, 14, METATILE_Lab_PuzzlePalace_Upstairs, FALSE
# 75 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 9, 14, METATILE_Lab_PuzzlePalace_DoorRight, TRUE
# 76 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 7, 15, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 77 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 9, 15, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
	return


DiglettsCave_B1F_EventScript_SetPuzzleHoOhBackShiny::
# 81 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 7, 12, METATILE_Building_Void, TRUE
# 82 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 8, 12, METATILE_Building_Void, TRUE
# 83 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 9, 12, METATILE_Building_Void, TRUE
# 84 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 7, 13, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 85 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 8, 13, METATILE_Lab_PuzzlePalace_Wall_TopPuzzle, TRUE
# 86 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 9, 13, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 87 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 7, 14, METATILE_Lab_PuzzlePalace_SmallTree_Top_Wall_Bottom, TRUE
# 88 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 8, 14, METATILE_Lab_PuzzlePalace_Wall_BottomPuzzle, TRUE
# 89 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 9, 14, METATILE_Lab_PuzzlePalace_SmallTree_Top_Wall_Bottom, TRUE
# 90 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 7, 15, METATILE_Lab_PuzzlePalace_SmallTree_Bottom, TRUE
# 91 "data/maps/DiglettsCave_B1F/scripts.pory"
	setmetatile 9, 15, METATILE_Lab_PuzzlePalace_SmallTree_Bottom, TRUE
	return

