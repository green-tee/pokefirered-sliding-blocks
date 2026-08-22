MtMoon_B2F_MapScripts::
# 2 "data/maps/MtMoon_B2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MtMoon_B2F_OnLoad
	.byte 0


MtMoon_B2F_OnLoad::
# 6 "data/maps/MtMoon_B2F/scripts.pory"
	goto_if_set FLAG_SOLVED_VOLTORB, MtMoon_B2F_OnLoad_2
MtMoon_B2F_OnLoad_1:
# 10 "data/maps/MtMoon_B2F/scripts.pory"
	goto_if_unset FLAG_SOLVED_ELECTRODE, MtMoon_B2F_OnLoad_4
	return

MtMoon_B2F_OnLoad_2:
# 7 "data/maps/MtMoon_B2F/scripts.pory"
	call MtMoon_B2F_EventScript_ClearPuzzleVoltorb
# 8 "data/maps/MtMoon_B2F/scripts.pory"
	call MtMoon_B2F_EventScript_ClearPathToPuzzleElectrode
	goto MtMoon_B2F_OnLoad_1

MtMoon_B2F_OnLoad_4:
# 11 "data/maps/MtMoon_B2F/scripts.pory"
	call MtMoon_B2F_EventScript_SetPuzzleElectrode
	return


MtMoon_B2F_FloorSign::
# 16 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_FloorName, MSGBOX_SIGN
	return


MtMoon_B2F_EventScript_PuzzleVoltorb::
# 20 "data/maps/MtMoon_B2F/scripts.pory"
	goto_if_unset FLAG_SOLVED_VOLTORB, MtMoon_B2F_EventScript_PuzzleVoltorb_1
	return

MtMoon_B2F_EventScript_PuzzleVoltorb_1:
# 21 "data/maps/MtMoon_B2F/scripts.pory"
	lockall
# 22 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_MakeElectrode, MSGBOX_DEFAULT
# 23 "data/maps/MtMoon_B2F/scripts.pory"
	closemessage
# 24 "data/maps/MtMoon_B2F/scripts.pory"
	playbgm MUS_PUZZLE, 0
# 25 "data/maps/MtMoon_B2F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_VOLTORB
# 26 "data/maps/MtMoon_B2F/scripts.pory"
	fadedefaultbgm
# 27 "data/maps/MtMoon_B2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne MtMoon_B2F_EventScript_PuzzleVoltorb_4
MtMoon_B2F_EventScript_PuzzleVoltorb_3:
# 36 "data/maps/MtMoon_B2F/scripts.pory"
	releaseall
	return

MtMoon_B2F_EventScript_PuzzleVoltorb_4:
# 28 "data/maps/MtMoon_B2F/scripts.pory"
	setflag FLAG_SOLVED_VOLTORB
# 29 "data/maps/MtMoon_B2F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 30 "data/maps/MtMoon_B2F/scripts.pory"
	playse SE_UNLOCK
# 31 "data/maps/MtMoon_B2F/scripts.pory"
	call MtMoon_B2F_EventScript_ClearPuzzleVoltorb
# 32 "data/maps/MtMoon_B2F/scripts.pory"
	special DrawWholeMapView
# 33 "data/maps/MtMoon_B2F/scripts.pory"
	delay 30
# 34 "data/maps/MtMoon_B2F/scripts.pory"
	call MtMoon_B2F_EventScript_ShowClearPathToPuzzleElectrode
	goto MtMoon_B2F_EventScript_PuzzleVoltorb_3


MtMoon_b2F_EventScript_PuzzleElectrode::
# 41 "data/maps/MtMoon_B2F/scripts.pory"
	goto_if_unset FLAG_SOLVED_ELECTRODE, MtMoon_b2F_EventScript_PuzzleElectrode_1
	return

MtMoon_b2F_EventScript_PuzzleElectrode_1:
# 42 "data/maps/MtMoon_B2F/scripts.pory"
	lockall
# 43 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_MakeElectrodeAgain, MSGBOX_DEFAULT
# 44 "data/maps/MtMoon_B2F/scripts.pory"
	closemessage
# 45 "data/maps/MtMoon_B2F/scripts.pory"
	playbgm MUS_PUZZLE, 0
# 46 "data/maps/MtMoon_B2F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ELECTRODE
# 47 "data/maps/MtMoon_B2F/scripts.pory"
	fadedefaultbgm
# 48 "data/maps/MtMoon_B2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne MtMoon_b2F_EventScript_PuzzleElectrode_4
MtMoon_b2F_EventScript_PuzzleElectrode_3:
# 55 "data/maps/MtMoon_B2F/scripts.pory"
	releaseall
	return

MtMoon_b2F_EventScript_PuzzleElectrode_4:
# 49 "data/maps/MtMoon_B2F/scripts.pory"
	setflag FLAG_SOLVED_ELECTRODE
# 50 "data/maps/MtMoon_B2F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 51 "data/maps/MtMoon_B2F/scripts.pory"
	playse SE_UNLOCK
# 52 "data/maps/MtMoon_B2F/scripts.pory"
	call MtMoon_B2F_EventScript_ClearPuzzleElectrode
# 53 "data/maps/MtMoon_B2F/scripts.pory"
	special DrawWholeMapView
	goto MtMoon_b2F_EventScript_PuzzleElectrode_3


MtMoon_B2F_EventScript_ShowClearPathToPuzzleElectrode:
# 60 "data/maps/MtMoon_B2F/scripts.pory"
	special SpawnCameraObject
# 61 "data/maps/MtMoon_B2F/scripts.pory"
	applymovement LOCALID_CAMERA, MtMoon_B2F_Movement_PanToPathToElectrode
# 62 "data/maps/MtMoon_B2F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 63 "data/maps/MtMoon_B2F/scripts.pory"
	delay 30
# 64 "data/maps/MtMoon_B2F/scripts.pory"
	playse SE_UNLOCK
# 65 "data/maps/MtMoon_B2F/scripts.pory"
	call MtMoon_B2F_EventScript_ClearPathToPuzzleElectrode
# 66 "data/maps/MtMoon_B2F/scripts.pory"
	special DrawWholeMapView
# 67 "data/maps/MtMoon_B2F/scripts.pory"
	delay 30
# 68 "data/maps/MtMoon_B2F/scripts.pory"
	applymovement LOCALID_CAMERA, MtMoon_B2F_Movement_PanToVoltorb
# 69 "data/maps/MtMoon_B2F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 70 "data/maps/MtMoon_B2F/scripts.pory"
	special RemoveCameraObject
	return


# 73 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_Movement_PanToPathToElectrode:
# 74 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 74 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 74 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 74 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 74 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 74 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 74 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 74 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 74 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 74 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 74 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 74 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
	step_end

# 78 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_Movement_PanToVoltorb:
# 79 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 79 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 79 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 79 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 79 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 79 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 79 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 79 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 79 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 79 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 79 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 79 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 79 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 79 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 80 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
# 80 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
# 80 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
# 80 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
# 80 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
# 80 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
# 80 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
# 80 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
# 80 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
# 80 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
# 80 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
# 80 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
	step_end

MtMoon_B2F_EventScript_ClearPathToPuzzleElectrode:
# 84 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 21, 15, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 85 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 22, 15, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 86 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 23, 15, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 87 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 21, 16, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 88 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 22, 16, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 89 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 23, 16, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 90 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 21, 17, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 91 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 22, 17, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 92 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 23, 17, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 93 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 21, 18, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 94 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 22, 18, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 95 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 23, 18, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 96 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 24, 18, METATILE_Lab_PuzzlePalace_Corner_FacingRight, TRUE
	return


MtMoon_B2F_EventScript_ClearPuzzleVoltorb:
# 100 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 36, 4, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 101 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 36, 5, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


MtMoon_B2F_EventScript_ClearPuzzleElectrode:
# 105 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 21, 1, METATILE_Lab_PuzzlePalace_DoorTopLeft, TRUE
# 106 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 22, 1, METATILE_Lab_PuzzlePalace_DoorTop, TRUE
# 107 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 23, 1, METATILE_Lab_PuzzlePalace_DoorTopRight, TRUE
# 108 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 21, 2, METATILE_Lab_PuzzlePalace_AboveDoorLeft, TRUE
# 109 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 22, 2, METATILE_Lab_PuzzlePalace_AboveDoor, TRUE
# 110 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 23, 2, METATILE_Lab_PuzzlePalace_AboveDoorRight, TRUE
# 111 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 21, 3, METATILE_Lab_PuzzlePalace_DoorLeft, TRUE
# 112 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 22, 3, METATILE_Lab_PuzzlePalace_Upstairs, FALSE
# 113 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 23, 3, METATILE_Lab_PuzzlePalace_DoorRight, TRUE
	return


MtMoon_B2F_EventScript_SetPuzzleElectrode:
# 117 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 21, 1, METATILE_Building_Void, TRUE
# 118 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 22, 1, METATILE_Building_Void, TRUE
# 119 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 23, 1, METATILE_Building_Void, TRUE
# 120 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 21, 2, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 121 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 22, 2, METATILE_Lab_PuzzlePalace_Wall_TopPuzzle, TRUE
# 122 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 23, 2, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 123 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 21, 3, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 124 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 22, 3, METATILE_Lab_PuzzlePalace_Wall_BottomPuzzle, TRUE
# 125 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 23, 3, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return

