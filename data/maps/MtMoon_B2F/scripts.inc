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


MtMoon_B2F_EventScript_PuzzleVoltorb::
# 16 "data/maps/MtMoon_B2F/scripts.pory"
	goto_if_unset FLAG_SOLVED_VOLTORB, MtMoon_B2F_EventScript_PuzzleVoltorb_1
	return

MtMoon_B2F_EventScript_PuzzleVoltorb_1:
# 17 "data/maps/MtMoon_B2F/scripts.pory"
	lockall
# 18 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_MakeElectrode, MSGBOX_DEFAULT
# 19 "data/maps/MtMoon_B2F/scripts.pory"
	closemessage
# 20 "data/maps/MtMoon_B2F/scripts.pory"
	playbgm MUS_PUZZLE, 0
# 21 "data/maps/MtMoon_B2F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_VOLTORB
# 22 "data/maps/MtMoon_B2F/scripts.pory"
	fadedefaultbgm
# 23 "data/maps/MtMoon_B2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne MtMoon_B2F_EventScript_PuzzleVoltorb_4
MtMoon_B2F_EventScript_PuzzleVoltorb_3:
# 32 "data/maps/MtMoon_B2F/scripts.pory"
	releaseall
	return

MtMoon_B2F_EventScript_PuzzleVoltorb_4:
# 24 "data/maps/MtMoon_B2F/scripts.pory"
	setflag FLAG_SOLVED_VOLTORB
# 25 "data/maps/MtMoon_B2F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 26 "data/maps/MtMoon_B2F/scripts.pory"
	playse SE_UNLOCK
# 27 "data/maps/MtMoon_B2F/scripts.pory"
	call MtMoon_B2F_EventScript_ClearPuzzleVoltorb
# 28 "data/maps/MtMoon_B2F/scripts.pory"
	special DrawWholeMapView
# 29 "data/maps/MtMoon_B2F/scripts.pory"
	delay 30
# 30 "data/maps/MtMoon_B2F/scripts.pory"
	call MtMoon_B2F_EventScript_ShowClearPathToPuzzleElectrode
	goto MtMoon_B2F_EventScript_PuzzleVoltorb_3


MtMoon_b2F_EventScript_PuzzleElectrode::
# 37 "data/maps/MtMoon_B2F/scripts.pory"
	goto_if_unset FLAG_SOLVED_ELECTRODE, MtMoon_b2F_EventScript_PuzzleElectrode_1
	return

MtMoon_b2F_EventScript_PuzzleElectrode_1:
# 38 "data/maps/MtMoon_B2F/scripts.pory"
	lockall
# 39 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_MakeElectrodeAgain, MSGBOX_DEFAULT
# 40 "data/maps/MtMoon_B2F/scripts.pory"
	closemessage
# 41 "data/maps/MtMoon_B2F/scripts.pory"
	playbgm MUS_PUZZLE, 0
# 42 "data/maps/MtMoon_B2F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ELECTRODE
# 43 "data/maps/MtMoon_B2F/scripts.pory"
	fadedefaultbgm
# 44 "data/maps/MtMoon_B2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne MtMoon_b2F_EventScript_PuzzleElectrode_4
MtMoon_b2F_EventScript_PuzzleElectrode_3:
# 51 "data/maps/MtMoon_B2F/scripts.pory"
	releaseall
	return

MtMoon_b2F_EventScript_PuzzleElectrode_4:
# 45 "data/maps/MtMoon_B2F/scripts.pory"
	setflag FLAG_SOLVED_ELECTRODE
# 46 "data/maps/MtMoon_B2F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 47 "data/maps/MtMoon_B2F/scripts.pory"
	playse SE_UNLOCK
# 48 "data/maps/MtMoon_B2F/scripts.pory"
	call MtMoon_B2F_EventScript_ClearPuzzleElectrode
# 49 "data/maps/MtMoon_B2F/scripts.pory"
	special DrawWholeMapView
	goto MtMoon_b2F_EventScript_PuzzleElectrode_3


MtMoon_B2F_EventScript_ShowClearPathToPuzzleElectrode:
# 56 "data/maps/MtMoon_B2F/scripts.pory"
	special SpawnCameraObject
# 57 "data/maps/MtMoon_B2F/scripts.pory"
	applymovement LOCALID_CAMERA, MtMoon_B2F_Movement_PanToPathToElectrode
# 58 "data/maps/MtMoon_B2F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 59 "data/maps/MtMoon_B2F/scripts.pory"
	delay 30
# 60 "data/maps/MtMoon_B2F/scripts.pory"
	playse SE_UNLOCK
# 61 "data/maps/MtMoon_B2F/scripts.pory"
	call MtMoon_B2F_EventScript_ClearPathToPuzzleElectrode
# 62 "data/maps/MtMoon_B2F/scripts.pory"
	special DrawWholeMapView
# 63 "data/maps/MtMoon_B2F/scripts.pory"
	delay 30
# 64 "data/maps/MtMoon_B2F/scripts.pory"
	applymovement LOCALID_CAMERA, MtMoon_B2F_Movement_PanToVoltorb
# 65 "data/maps/MtMoon_B2F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 66 "data/maps/MtMoon_B2F/scripts.pory"
	special RemoveCameraObject
	return


# 69 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_Movement_PanToPathToElectrode:
# 70 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 70 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 70 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 70 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 70 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 70 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 70 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 70 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 70 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 70 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 70 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 70 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_down
# 71 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 71 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 71 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 71 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 71 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 71 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 71 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 71 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 71 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 71 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 71 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 71 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 71 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
# 71 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_left
	step_end

# 74 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_Movement_PanToVoltorb:
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_right
# 76 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
# 76 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
# 76 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
# 76 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
# 76 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
# 76 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
# 76 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
# 76 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
# 76 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
# 76 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
# 76 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
# 76 "data/maps/MtMoon_B2F/scripts.pory"
	walk_faster_up
	step_end

MtMoon_B2F_EventScript_ClearPathToPuzzleElectrode:
# 80 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 21, 15, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 81 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 22, 15, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 82 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 23, 15, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 83 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 21, 16, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 84 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 22, 16, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 85 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 23, 16, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 86 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 21, 17, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 87 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 22, 17, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 88 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 23, 17, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 89 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 21, 18, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 90 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 22, 18, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 91 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 23, 18, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 92 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 24, 18, METATILE_Lab_PuzzlePalace_Corner_FacingRight, TRUE
	return


MtMoon_B2F_EventScript_ClearPuzzleVoltorb:
# 96 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 36, 4, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 97 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 36, 5, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


MtMoon_B2F_EventScript_ClearPuzzleElectrode:
# 101 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 21, 1, METATILE_Lab_PuzzlePalace_DoorTopLeft, TRUE
# 102 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 22, 1, METATILE_Lab_PuzzlePalace_DoorTop, TRUE
# 103 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 23, 1, METATILE_Lab_PuzzlePalace_DoorTopRight, TRUE
# 104 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 21, 2, METATILE_Lab_PuzzlePalace_AboveDoorLeft, TRUE
# 105 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 22, 2, METATILE_Lab_PuzzlePalace_AboveDoor, TRUE
# 106 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 23, 2, METATILE_Lab_PuzzlePalace_AboveDoorRight, TRUE
# 107 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 21, 3, METATILE_Lab_PuzzlePalace_DoorLeft, TRUE
# 108 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 22, 3, METATILE_Lab_PuzzlePalace_Upstairs, FALSE
# 109 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 23, 3, METATILE_Lab_PuzzlePalace_DoorRight, TRUE
	return


MtMoon_B2F_EventScript_SetPuzzleElectrode:
# 113 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 21, 1, METATILE_Building_Void, TRUE
# 114 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 22, 1, METATILE_Building_Void, TRUE
# 115 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 23, 1, METATILE_Building_Void, TRUE
# 116 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 21, 2, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 117 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 22, 2, METATILE_Lab_PuzzlePalace_Wall_TopPuzzle, TRUE
# 118 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 23, 2, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 119 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 21, 3, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 120 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 22, 3, METATILE_Lab_PuzzlePalace_Wall_BottomPuzzle, TRUE
# 121 "data/maps/MtMoon_B2F/scripts.pory"
	setmetatile 23, 3, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return

