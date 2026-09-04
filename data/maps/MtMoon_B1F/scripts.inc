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


MtMoon_B1F_EventScript_FloorSign::
# 15 "data/maps/MtMoon_B1F/scripts.pory"
	msgbox MtMoon_B1F_Text_FloorName, MSGBOX_SIGN
	return


MtMoon_B1F_EventScript_PuzzleBirds::
# 19 "data/maps/MtMoon_B1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_BIRDS, MtMoon_B1F_EventScript_PuzzleBirds_1
	return

MtMoon_B1F_EventScript_PuzzleBirds_1:
# 20 "data/maps/MtMoon_B1F/scripts.pory"
	lockall
# 21 "data/maps/MtMoon_B1F/scripts.pory"
	playbgm MUS_PUZZLE, 0
# 22 "data/maps/MtMoon_B1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_BIRDS
# 23 "data/maps/MtMoon_B1F/scripts.pory"
	fadedefaultbgm
# 24 "data/maps/MtMoon_B1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne MtMoon_B1F_EventScript_PuzzleBirds_4
MtMoon_B1F_EventScript_PuzzleBirds_3:
# 31 "data/maps/MtMoon_B1F/scripts.pory"
	releaseall
	return

MtMoon_B1F_EventScript_PuzzleBirds_4:
# 25 "data/maps/MtMoon_B1F/scripts.pory"
	setflag FLAG_SOLVED_BIRDS
# 26 "data/maps/MtMoon_B1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 27 "data/maps/MtMoon_B1F/scripts.pory"
	playse SE_UNLOCK
# 28 "data/maps/MtMoon_B1F/scripts.pory"
	call MtMoon_B1F_EventScript_ClearPuzzleBirds
# 29 "data/maps/MtMoon_B1F/scripts.pory"
	special DrawWholeMapView
	goto MtMoon_B1F_EventScript_PuzzleBirds_3


MtMoon_B1F_EventScript_PuzzleHoOhBack::
# 36 "data/maps/MtMoon_B1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_HO_OH_BACK, MtMoon_B1F_EventScript_PuzzleHoOhBack_1
	return

MtMoon_B1F_EventScript_PuzzleHoOhBack_1:
# 37 "data/maps/MtMoon_B1F/scripts.pory"
	lockall
# 38 "data/maps/MtMoon_B1F/scripts.pory"
	playbgm MUS_PUZZLE, 0
# 39 "data/maps/MtMoon_B1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_HO_OH_BACK
# 40 "data/maps/MtMoon_B1F/scripts.pory"
	fadedefaultbgm
# 41 "data/maps/MtMoon_B1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne MtMoon_B1F_EventScript_PuzzleHoOhBack_4
MtMoon_B1F_EventScript_PuzzleHoOhBack_3:
# 48 "data/maps/MtMoon_B1F/scripts.pory"
	releaseall
	return

MtMoon_B1F_EventScript_PuzzleHoOhBack_4:
# 42 "data/maps/MtMoon_B1F/scripts.pory"
	setflag FLAG_SOLVED_HO_OH_BACK
# 43 "data/maps/MtMoon_B1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 44 "data/maps/MtMoon_B1F/scripts.pory"
	playse SE_UNLOCK
# 45 "data/maps/MtMoon_B1F/scripts.pory"
	call MtMoon_B1F_EventScript_ClearPuzzleHoOhBack
# 46 "data/maps/MtMoon_B1F/scripts.pory"
	special DrawWholeMapView
	goto MtMoon_B1F_EventScript_PuzzleHoOhBack_3


MtMoon_B1F_EventScript_ItemMasterBall::
# 53 "data/maps/MtMoon_B1F/scripts.pory"
	finditem ITEM_MASTER_BALL, 1
	return


MtMoon_B1F_EventScript_ClearPuzzleBirds:
# 57 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 18, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 58 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 18, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 59 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 18, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 60 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 19, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 61 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 19, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 62 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 19, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 63 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 64 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 65 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 66 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 21, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 67 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 21, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 68 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 21, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 69 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 13, 21, METATILE_Lab_PuzzlePalace_Corner_FacingRight, TRUE
	return


MtMoon_B1F_EventScript_ClearPuzzleHoOhBack:
# 73 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 1, METATILE_Lab_PuzzlePalace_DoorTopLeft, TRUE
# 74 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 1, METATILE_Lab_PuzzlePalace_DoorTop, TRUE
# 75 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 1, METATILE_Lab_PuzzlePalace_DoorTopRight, TRUE
# 76 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 2, METATILE_Lab_PuzzlePalace_AboveDoorLeft, TRUE
# 77 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 2, METATILE_Lab_PuzzlePalace_AboveDoor, TRUE
# 78 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 2, METATILE_Lab_PuzzlePalace_AboveDoorRight, TRUE
# 79 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 3, METATILE_Lab_PuzzlePalace_DoorLeft, TRUE
# 80 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 3, METATILE_Lab_PuzzlePalace_Upstairs, FALSE
# 81 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 3, METATILE_Lab_PuzzlePalace_DoorRight, TRUE
	return


MtMoon_B1F_EventScript_SetPuzzleHoOhBack:
# 85 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 1, METATILE_Building_Void, TRUE
# 86 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 1, METATILE_Building_Void, TRUE
# 87 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 1, METATILE_Building_Void, TRUE
# 88 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 2, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 89 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 2, METATILE_Lab_PuzzlePalace_Wall_TopPuzzle, TRUE
# 90 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 2, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 91 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 10, 3, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 92 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 11, 3, METATILE_Lab_PuzzlePalace_Wall_BottomPuzzle, TRUE
# 93 "data/maps/MtMoon_B1F/scripts.pory"
	setmetatile 12, 3, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return

