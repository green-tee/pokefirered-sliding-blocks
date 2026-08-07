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
	playbgm MUS_PUZZLE, 0
# 18 "data/maps/MtMoon_B1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_BIRDS
# 19 "data/maps/MtMoon_B1F/scripts.pory"
	fadedefaultbgm
# 20 "data/maps/MtMoon_B1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne MtMoon_B1F_EventScript_PuzzleBirds_4
MtMoon_B1F_EventScript_PuzzleBirds_3:
# 27 "data/maps/MtMoon_B1F/scripts.pory"
	releaseall
	return

MtMoon_B1F_EventScript_PuzzleBirds_4:
# 21 "data/maps/MtMoon_B1F/scripts.pory"
	setflag FLAG_SOLVED_BIRDS
# 22 "data/maps/MtMoon_B1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 23 "data/maps/MtMoon_B1F/scripts.pory"
	playse SE_UNLOCK
# 24 "data/maps/MtMoon_B1F/scripts.pory"
	call MtMoon_B1F_EventScript_ClearPuzzleBirds
# 25 "data/maps/MtMoon_B1F/scripts.pory"
	special DrawWholeMapView
	goto MtMoon_B1F_EventScript_PuzzleBirds_3


MtMoon_B1F_EventScript_PuzzleHoOhBack::
# 32 "data/maps/MtMoon_B1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_HO_OH_BACK, MtMoon_B1F_EventScript_PuzzleHoOhBack_1
	return

MtMoon_B1F_EventScript_PuzzleHoOhBack_1:
# 33 "data/maps/MtMoon_B1F/scripts.pory"
	lockall
# 34 "data/maps/MtMoon_B1F/scripts.pory"
	playbgm MUS_PUZZLE, 0
# 35 "data/maps/MtMoon_B1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_HO_OH_BACK
# 36 "data/maps/MtMoon_B1F/scripts.pory"
	fadedefaultbgm
# 37 "data/maps/MtMoon_B1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne MtMoon_B1F_EventScript_PuzzleHoOhBack_4
MtMoon_B1F_EventScript_PuzzleHoOhBack_3:
# 44 "data/maps/MtMoon_B1F/scripts.pory"
	releaseall
	return

MtMoon_B1F_EventScript_PuzzleHoOhBack_4:
# 38 "data/maps/MtMoon_B1F/scripts.pory"
	setflag FLAG_SOLVED_HO_OH_BACK
# 39 "data/maps/MtMoon_B1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 40 "data/maps/MtMoon_B1F/scripts.pory"
	playse SE_UNLOCK
# 41 "data/maps/MtMoon_B1F/scripts.pory"
	call MtMoon_B1F_EventScript_ClearPuzzleHoOhBack
# 42 "data/maps/MtMoon_B1F/scripts.pory"
	special DrawWholeMapView
	goto MtMoon_B1F_EventScript_PuzzleHoOhBack_3


MtMoon_B1F_EventScript_ClearPuzzleBirds:
# 49 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 18, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 50 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 18, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 51 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 18, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 52 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 19, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 53 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 19, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 54 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 19, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 55 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 56 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 57 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 58 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 21, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 59 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 21, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 60 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 21, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 61 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 13, 21, METATILE_Lab_PuzzlePalace_Corner_FacingRight, TRUE
	return


MtMoon_B1F_EventScript_ClearPuzzleHoOhBack:
# 65 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 1, METATILE_Lab_PuzzlePalace_DoorTopLeft, TRUE
# 66 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 1, METATILE_Lab_PuzzlePalace_DoorTop, TRUE
# 67 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 1, METATILE_Lab_PuzzlePalace_DoorTopRight, TRUE
# 68 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 2, METATILE_Lab_PuzzlePalace_AboveDoorLeft, TRUE
# 69 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 2, METATILE_Lab_PuzzlePalace_AboveDoor, TRUE
# 70 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 2, METATILE_Lab_PuzzlePalace_AboveDoorRight, TRUE
# 71 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 3, METATILE_Lab_PuzzlePalace_DoorLeft, TRUE
# 72 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 3, METATILE_Lab_PuzzlePalace_Upstairs, FALSE
# 73 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 3, METATILE_Lab_PuzzlePalace_DoorRight, TRUE
	return


MtMoon_B1F_EventScript_SetPuzzleHoOhBack:
# 77 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 1, METATILE_Building_Void, TRUE
# 78 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 1, METATILE_Building_Void, TRUE
# 79 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 1, METATILE_Building_Void, TRUE
# 80 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 2, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 81 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 2, METATILE_Lab_PuzzlePalace_Wall_TopPuzzle, TRUE
# 82 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 2, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 83 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 3, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 84 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 3, METATILE_Lab_PuzzlePalace_Wall_BottomPuzzle, TRUE
# 85 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 3, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return

