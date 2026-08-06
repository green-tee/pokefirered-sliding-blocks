MtMoon_B1F_MapScripts::
# 2 "data/maps/MtMoon_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MtMoon_B1F_OnLoad
	.byte 0


MtMoon_B1F_OnLoad::
# 6 "data/maps/MtMoon_B1F/scripts.pory"
	goto_if_set FLAG_SOLVED_BIRDS, MtMoon_B1F_OnLoad_2
MtMoon_B1F_OnLoad_1:
# 9 "data/maps/MtMoon_B1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_HO_OH_BACK, MtMoon_B1F_OnLoad_4
	return

MtMoon_B1F_OnLoad_2:
# 7 "data/maps/MtMoon_B1F/scripts.pory"
	call MtMoon_B1F_EventScript_ClearPuzzleBirds
	goto MtMoon_B1F_OnLoad_1

MtMoon_B1F_OnLoad_4:
# 10 "data/maps/MtMoon_B1F/scripts.pory"
	call MtMoon_B1F_EventScript_SetPuzzleHoOhBack
	return


MtMoon_B1F_EventScript_PuzzleBirds::
# 15 "data/maps/MtMoon_B1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_BIRDS, MtMoon_B1F_EventScript_PuzzleBirds_1
	return

MtMoon_B1F_EventScript_PuzzleBirds_1:
# 16 "data/maps/MtMoon_B1F/scripts.pory"
	lockall
# 17 "data/maps/MtMoon_B1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_BIRDS
# 18 "data/maps/MtMoon_B1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne MtMoon_B1F_EventScript_PuzzleBirds_4
MtMoon_B1F_EventScript_PuzzleBirds_3:
# 25 "data/maps/MtMoon_B1F/scripts.pory"
	releaseall
	return

MtMoon_B1F_EventScript_PuzzleBirds_4:
# 19 "data/maps/MtMoon_B1F/scripts.pory"
	setflag FLAG_SOLVED_BIRDS
# 20 "data/maps/MtMoon_B1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 21 "data/maps/MtMoon_B1F/scripts.pory"
	playse SE_UNLOCK
# 22 "data/maps/MtMoon_B1F/scripts.pory"
	call MtMoon_B1F_EventScript_ClearPuzzleBirds
# 23 "data/maps/MtMoon_B1F/scripts.pory"
	special DrawWholeMapView
	goto MtMoon_B1F_EventScript_PuzzleBirds_3


MtMoon_B1F_EventScript_PuzzleHoOhBack::
# 30 "data/maps/MtMoon_B1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_HO_OH_BACK, MtMoon_B1F_EventScript_PuzzleHoOhBack_1
	return

MtMoon_B1F_EventScript_PuzzleHoOhBack_1:
# 31 "data/maps/MtMoon_B1F/scripts.pory"
	lockall
# 32 "data/maps/MtMoon_B1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_HO_OH_BACK
# 33 "data/maps/MtMoon_B1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne MtMoon_B1F_EventScript_PuzzleHoOhBack_4
MtMoon_B1F_EventScript_PuzzleHoOhBack_3:
# 40 "data/maps/MtMoon_B1F/scripts.pory"
	releaseall
	return

MtMoon_B1F_EventScript_PuzzleHoOhBack_4:
# 34 "data/maps/MtMoon_B1F/scripts.pory"
	setflag FLAG_SOLVED_HO_OH_BACK
# 35 "data/maps/MtMoon_B1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 36 "data/maps/MtMoon_B1F/scripts.pory"
	playse SE_UNLOCK
# 37 "data/maps/MtMoon_B1F/scripts.pory"
	call MtMoon_B1F_EventScript_ClearPuzzleHoOhBack
# 38 "data/maps/MtMoon_B1F/scripts.pory"
	special DrawWholeMapView
	goto MtMoon_B1F_EventScript_PuzzleHoOhBack_3


MtMoon_B1F_EventScript_ClearPuzzleBirds:
# 45 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 18, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 46 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 18, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 47 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 18, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 48 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 19, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 49 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 19, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 50 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 19, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 51 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 52 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 53 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 54 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 21, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 55 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 21, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 56 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 21, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 57 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 13, 21, METATILE_Lab_PuzzlePalace_Corner_FacingRight, TRUE
	return


MtMoon_B1F_EventScript_ClearPuzzleHoOhBack:
# 61 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 1, METATILE_Lab_PuzzlePalace_DoorTopLeft, TRUE
# 62 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 1, METATILE_Lab_PuzzlePalace_DoorTop, TRUE
# 63 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 1, METATILE_Lab_PuzzlePalace_DoorTopRight, TRUE
# 64 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 2, METATILE_Lab_PuzzlePalace_AboveDoorLeft, TRUE
# 65 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 2, METATILE_Lab_PuzzlePalace_AboveDoor, TRUE
# 66 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 2, METATILE_Lab_PuzzlePalace_AboveDoorRight, TRUE
# 67 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 3, METATILE_Lab_PuzzlePalace_DoorLeft, TRUE
# 68 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 3, METATILE_Lab_PuzzlePalace_Upstairs, FALSE
# 69 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 3, METATILE_Lab_PuzzlePalace_DoorRight, TRUE
	return


MtMoon_B1F_EventScript_SetPuzzleHoOhBack:
# 73 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 1, METATILE_Building_Void, TRUE
# 74 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 1, METATILE_Building_Void, TRUE
# 75 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 1, METATILE_Building_Void, TRUE
# 76 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 2, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 77 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 2, METATILE_Lab_PuzzlePalace_Wall_TopPuzzle, TRUE
# 78 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 2, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 79 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 3, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 80 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 3, METATILE_Lab_PuzzlePalace_Wall_BottomPuzzle, TRUE
# 81 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 3, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return

