VictoryRoad_1F_MapScripts::
# 2 "data/maps/VictoryRoad_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_1F_OnLoad
	.byte 0


VictoryRoad_1F_OnLoad::
# 6 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_set FLAG_SOLVED_ALAKAZAM, VictoryRoad_1F_OnLoad_2
VictoryRoad_1F_OnLoad_1:
# 9 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_set FLAG_SOLVED_SNORLAX, VictoryRoad_1F_OnLoad_5
# 12 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_BlockPathToPuzzleDugtrio
VictoryRoad_1F_OnLoad_4:
# 14 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_set FLAG_SOLVED_DUGTRIO, VictoryRoad_1F_OnLoad_9
# 18 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_MASTEROFALLTRADES_PUZZLE_BLASTOISE, 11, 18
# 19 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleBlastoise
VictoryRoad_1F_OnLoad_8:
# 21 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_set FLAG_SOLVED_RAICHU, VictoryRoad_1F_OnLoad_13
VictoryRoad_1F_OnLoad_12:
# 24 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_set FLAG_SOLVED_BLASTOISE, VictoryRoad_1F_OnLoad_16
VictoryRoad_1F_OnLoad_15:
# 28 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_set FLAG_SOLVED_VENUSAUR, VictoryRoad_1F_OnLoad_19
VictoryRoad_1F_OnLoad_18:
# 32 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_set FLAG_SOLVED_PIDGEOT, VictoryRoad_1F_OnLoad_22
VictoryRoad_1F_OnLoad_21:
# 35 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_set FLAG_SOLVED_HITMONCHAN, VictoryRoad_1F_OnLoad_25
VictoryRoad_1F_OnLoad_24:
# 38 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_set FLAG_SOLVED_GENGAR, VictoryRoad_1F_OnLoad_28
# 41 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_MASTEROFALLTRADES_PUZZLE_WALREIN, 6, 2
# 42 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_MASTEROFALLTRADES_PUZZLE_STEELIX, 10, 2
# 43 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_MASTEROFALLTRADES_PUZZLE_HERACROSS, 14, 2
# 44 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzlesNorthWest
VictoryRoad_1F_OnLoad_27:
# 46 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_set FLAG_SOLVED_CHARIZARD, VictoryRoad_1F_OnLoad_32
VictoryRoad_1F_OnLoad_31:
# 50 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_set FLAG_SOLVED_WALREIN, VictoryRoad_1F_OnLoad_35
# 53 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_MASTEROFALLTRADES_PUZZLE_SALAMENCE, 26, 5
VictoryRoad_1F_OnLoad_34:
# 55 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_set FLAG_SOLVED_SALAMENCE, VictoryRoad_1F_OnLoad_38
# 60 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_BlockPathToFinalPuzzle
# 61 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_set FLAG_SOLVED_WALREIN, VictoryRoad_1F_OnLoad_43
	return

VictoryRoad_1F_OnLoad_2:
# 7 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleAlakazam
	goto VictoryRoad_1F_OnLoad_1

VictoryRoad_1F_OnLoad_5:
# 10 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleSnorlax
	goto VictoryRoad_1F_OnLoad_4

VictoryRoad_1F_OnLoad_9:
# 15 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleDugtrio
# 16 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPathToPuzzleRaichu
	goto VictoryRoad_1F_OnLoad_8

VictoryRoad_1F_OnLoad_13:
# 22 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleRaichu
	goto VictoryRoad_1F_OnLoad_12

VictoryRoad_1F_OnLoad_16:
# 25 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleBlastoise
# 26 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPathToPuzzleVenusaur
	goto VictoryRoad_1F_OnLoad_15

VictoryRoad_1F_OnLoad_19:
# 29 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleVenusaur
# 30 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPathToSouthWestPuzzles
	goto VictoryRoad_1F_OnLoad_18

VictoryRoad_1F_OnLoad_22:
# 33 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzlePidgeot
	goto VictoryRoad_1F_OnLoad_21

VictoryRoad_1F_OnLoad_25:
# 36 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleHitmonchan
	goto VictoryRoad_1F_OnLoad_24

VictoryRoad_1F_OnLoad_28:
# 39 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleGengar
	goto VictoryRoad_1F_OnLoad_27

VictoryRoad_1F_OnLoad_32:
# 47 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleCharizard
# 48 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPathToNorthWestPuzzles
	goto VictoryRoad_1F_OnLoad_31

VictoryRoad_1F_OnLoad_35:
# 51 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleWalrein
	goto VictoryRoad_1F_OnLoad_34

VictoryRoad_1F_OnLoad_38:
# 56 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_NUMBERS_MAGIC, VictoryRoad_1F_OnLoad_41
	return

VictoryRoad_1F_OnLoad_41:
# 57 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPathToFinalPuzzle
	return

VictoryRoad_1F_OnLoad_43:
# 62 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_SetPuzzleSalamence
	return


VictoryRoad_1F_EventScript_FloorSign::
# 68 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_FloorName, MSGBOX_SIGN
	return


VictoryRoad_1F_EventScript_PuzzleAlakazam::
# 72 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_ALAKAZAM, VictoryRoad_1F_EventScript_PuzzleAlakazam_1
	return

VictoryRoad_1F_EventScript_PuzzleAlakazam_1:
# 73 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 74 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_TUTORIAL, 0
# 75 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ALAKAZAM
# 76 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 77 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleAlakazam_4
VictoryRoad_1F_EventScript_PuzzleAlakazam_3:
# 86 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleAlakazam_4:
# 78 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_ALAKAZAM
# 79 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 80 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 81 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleAlakazam
# 82 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 83 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_NothingHappened, MSGBOX_DEFAULT
# 84 "data/maps/VictoryRoad_1F/scripts.pory"
	closemessage
	goto VictoryRoad_1F_EventScript_PuzzleAlakazam_3


VictoryRoad_1F_EventScript_PuzzleSnorlax::
# 91 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_SNORLAX, VictoryRoad_1F_EventScript_PuzzleSnorlax_1
	return

VictoryRoad_1F_EventScript_PuzzleSnorlax_1:
# 92 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 93 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_TUTORIAL, 0
# 94 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_SNORLAX
# 95 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 96 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleSnorlax_4
VictoryRoad_1F_EventScript_PuzzleSnorlax_3:
# 105 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleSnorlax_4:
# 97 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_SNORLAX
# 98 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 99 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 100 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleSnorlax
# 101 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 102 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 103 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ShowClearPathToPuzzleDugtrio
	goto VictoryRoad_1F_EventScript_PuzzleSnorlax_3


VictoryRoad_1F_EventScript_ShowClearPathToPuzzleDugtrio:
# 110 "data/maps/VictoryRoad_1F/scripts.pory"
	special SpawnCameraObject
# 111 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToPathToDugtrio
# 112 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 113 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 114 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 115 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPathToPuzzleDugtrio
# 116 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 117 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 118 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToSnorlax
# 119 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 120 "data/maps/VictoryRoad_1F/scripts.pory"
	special RemoveCameraObject
	return


# 123 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToPathToDugtrio:
# 124 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 124 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 124 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 124 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 124 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 124 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 124 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 124 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 124 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 124 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 124 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 124 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 125 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 125 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
	step_end

# 128 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToSnorlax:
# 129 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 129 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 130 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 130 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 130 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 130 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 130 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 130 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 130 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 130 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 130 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 130 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 130 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 130 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
	step_end

VictoryRoad_1F_EventScript_BlockPathToPuzzleDugtrio:
# 134 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 23, METATILE_Building_Void, TRUE
# 135 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 23, METATILE_Building_Void, TRUE
# 136 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 29, 23, METATILE_Building_Void, TRUE
# 137 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 23, METATILE_Building_Void, TRUE
# 138 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 23, METATILE_Building_Void, TRUE
# 139 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 23, METATILE_Building_Void, TRUE
# 140 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 24, METATILE_Building_Void, TRUE
# 141 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 29, 24, METATILE_Building_Void, TRUE
# 142 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 24, METATILE_Building_Void, TRUE
# 143 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 24, METATILE_Building_Void, TRUE
# 144 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 25, METATILE_Building_Void, TRUE
# 145 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 29, 25, METATILE_Building_Void, TRUE
# 146 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 25, METATILE_Building_Void, TRUE
# 147 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 25, METATILE_Building_Void, TRUE
# 148 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 26, METATILE_Building_Void, TRUE
# 149 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 29, 26, METATILE_Building_Void, TRUE
# 150 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 26, METATILE_Building_Void, TRUE
# 151 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 26, METATILE_Building_Void, TRUE
# 152 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 26, METATILE_Building_Void, TRUE
# 153 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 27, METATILE_Building_Void, TRUE
# 154 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 29, 27, METATILE_Building_Void, TRUE
# 155 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 27, METATILE_Building_Void, TRUE
# 156 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 27, METATILE_Building_Void, TRUE
# 157 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 27, METATILE_Building_Void, TRUE
# 158 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 33, 27, METATILE_Building_Void, TRUE
# 159 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 34, 27, METATILE_Building_Void, TRUE
# 160 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 35, 27, METATILE_Building_Void, TRUE
# 161 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 36, 27, METATILE_Building_Void, TRUE
# 162 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 37, 27, METATILE_Building_Void, TRUE
	return


VictoryRoad_1F_EventScript_ClearPathToPuzzleDugtrio:
# 166 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 23, METATILE_Lab_PuzzlePalace_TileCornerSouthWest, TRUE
# 167 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 23, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 168 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 29, 23, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 169 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 23, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 170 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 23, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 171 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 23, METATILE_Lab_PuzzlePalace_TileCornerSouthEast, TRUE
# 172 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 24, METATILE_Lab_PuzzlePalace_LedgeLeft, TRUE
# 173 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 29, 24, METATILE_Lab_PuzzlePalace_Ledge, TRUE
# 174 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 24, METATILE_Lab_PuzzlePalace_Ledge, TRUE
# 175 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 24, METATILE_Lab_PuzzlePalace_LedgeRight, TRUE
# 176 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 25, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 177 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 29, 25, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 178 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 25, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 179 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 25, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 180 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 26, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 181 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 29, 26, METATILE_Lab_PuzzlePalace_TallGrass, FALSE
# 182 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 26, METATILE_Lab_PuzzlePalace_TallGrass, FALSE
# 183 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 26, METATILE_Lab_PuzzlePalace_TallGrass, FALSE
# 184 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 26, METATILE_Lab_PuzzlePalace_Wall_TopCornerNorthEast, TRUE
# 185 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 27, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 186 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 29, 27, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 187 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 27, METATILE_Lab_PuzzlePalace_TallGrass, FALSE
# 188 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 27, METATILE_Lab_PuzzlePalace_TallGrass, FALSE
# 189 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 27, METATILE_Lab_PuzzlePalace_Wall_BottomCornerSouthEast, TRUE
# 190 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 33, 27, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 191 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 34, 27, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 192 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 35, 27, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 193 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 36, 27, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 194 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 37, 27, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
	return


VictoryRoad_1F_EventScript_PuzzleDugtrio::
# 198 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_DUGTRIO, VictoryRoad_1F_EventScript_PuzzleDugtrio_1
	return

VictoryRoad_1F_EventScript_PuzzleDugtrio_1:
# 199 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 200 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE, 0
# 201 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_DUGTRIO
# 202 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 203 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleDugtrio_4
VictoryRoad_1F_EventScript_PuzzleDugtrio_3:
# 212 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleDugtrio_4:
# 204 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_DUGTRIO
# 205 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 206 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 207 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleDugtrio
# 208 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 209 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 210 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ShowSetPuzzleBlastoiseAndClearPathToPuzzleRaichu
	goto VictoryRoad_1F_EventScript_PuzzleDugtrio_3


VictoryRoad_1F_EventScript_ShowSetPuzzleBlastoiseAndClearPathToPuzzleRaichu:
# 217 "data/maps/VictoryRoad_1F/scripts.pory"
	special SpawnCameraObject
# 218 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToBlastoiseFromDugtrio
# 219 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 220 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 221 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 222 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_MASTEROFALLTRADES_PUZZLE_BLASTOISE, 11, 19
# 223 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_SetPuzzleBlastoise
# 224 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 225 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 226 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToPathToRaichu
# 227 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 228 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 229 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 230 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPathToPuzzleRaichu
# 231 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 232 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 233 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToDugtrio
# 234 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 235 "data/maps/VictoryRoad_1F/scripts.pory"
	special RemoveCameraObject
	return


# 238 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToBlastoiseFromDugtrio:
# 239 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 239 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 239 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 240 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
	step_end

# 243 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToPathToRaichu:
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 245 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 245 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 245 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 245 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 245 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 245 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 245 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 245 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 245 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
	step_end

# 248 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToDugtrio:
# 249 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 249 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 249 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 249 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 249 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 249 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 249 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 249 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 249 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 250 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 250 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 250 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 250 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 250 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 250 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 250 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 250 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 250 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 250 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 250 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 250 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
	step_end

VictoryRoad_1F_EventScript_ClearPathToPuzzleRaichu:
# 254 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 30, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 255 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 30, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 256 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 30, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 257 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 33, 30, METATILE_Lab_PuzzlePalace_TileCornerSouthEastShaded, TRUE
# 258 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 31, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 259 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 31, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 260 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 31, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 261 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 32, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 262 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 32, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 263 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 32, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 264 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 33, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 265 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 33, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 266 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 33, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 267 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 34, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 268 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 34, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 269 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 34, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 270 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 35, METATILE_Lab_PuzzlePalace_LedgeLeft, TRUE
# 271 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 35, METATILE_Lab_PuzzlePalace_Ledge, TRUE
# 272 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 35, METATILE_Lab_PuzzlePalace_LedgeRight, TRUE
	return


VictoryRoad_1F_EventScript_PuzzleRaichu::
# 276 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_RAICHU, VictoryRoad_1F_EventScript_PuzzleRaichu_1
	return

VictoryRoad_1F_EventScript_PuzzleRaichu_1:
# 277 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 278 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE, 0
# 279 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_RAICHU
# 280 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 281 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleRaichu_4
VictoryRoad_1F_EventScript_PuzzleRaichu_3:
# 288 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleRaichu_4:
# 282 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_RAICHU
# 283 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 284 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 285 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleRaichu
# 286 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
	goto VictoryRoad_1F_EventScript_PuzzleRaichu_3


VictoryRoad_1F_EventScript_PuzzleBlastoise::
# 293 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_BLASTOISE, VictoryRoad_1F_EventScript_PuzzleBlastoise_1
	return

VictoryRoad_1F_EventScript_PuzzleBlastoise_1:
# 294 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 295 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE, 0
# 296 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_BLASTOISE
# 297 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 298 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleBlastoise_4
VictoryRoad_1F_EventScript_PuzzleBlastoise_3:
# 307 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleBlastoise_4:
# 299 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_BLASTOISE
# 300 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 301 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 302 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleBlastoise
# 303 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 304 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 305 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ShowClearPathToPuzzleVenusaur
	goto VictoryRoad_1F_EventScript_PuzzleBlastoise_3


VictoryRoad_1F_EventScript_ShowClearPathToPuzzleVenusaur:
# 312 "data/maps/VictoryRoad_1F/scripts.pory"
	special SpawnCameraObject
# 313 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToPathToVenusaur
# 314 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 315 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 316 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 317 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPathToPuzzleVenusaur
# 318 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 319 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 320 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToBlastoiseFromVenusaur
# 321 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 322 "data/maps/VictoryRoad_1F/scripts.pory"
	special RemoveCameraObject
	return


# 325 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToPathToVenusaur:
# 326 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 326 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 326 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 326 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 326 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 326 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
	step_end

# 329 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToBlastoiseFromVenusaur:
# 330 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 330 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 330 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 330 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 330 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 330 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
	step_end

VictoryRoad_1F_EventScript_ClearPathToPuzzleVenusaur:
# 334 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 13, 12, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 335 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 14, 12, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 336 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 15, 12, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 337 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 13, 13, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 338 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 14, 13, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 339 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 15, 13, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 340 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 13, 14, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 341 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 14, 14, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 342 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 15, 14, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 343 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 16, 14, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 344 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 13, 15, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 345 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 14, 15, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 346 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 15, 15, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 347 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 16, 15, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 349 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 16, 16, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 350 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 17, 16, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 351 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 18, 16, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 352 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 15, 17, METATILE_Lab_PuzzlePalace_Wall_TopCornerNorthWest, TRUE
# 353 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 16, 17, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 354 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 17, 17, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 355 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 18, 17, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 356 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 19, 17, METATILE_Lab_PuzzlePalace_Wall_TopCornerNorthEast, TRUE
# 357 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 15, 18, METATILE_Lab_PuzzlePalace_Wall_BottomCornerSouthWest, TRUE
# 358 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 16, 18, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 359 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 17, 18, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 360 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 18, 18, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 361 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 19, 18, METATILE_Lab_PuzzlePalace_Wall_BottomCornerSouthEast, TRUE
# 362 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 15, 19, METATILE_Lab_PuzzlePalace_Corner_FacingLeftShaded, TRUE
# 363 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 16, 19, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 364 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 17, 19, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 365 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 18, 19, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 366 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 19, 19, METATILE_Lab_PuzzlePalace_Corner_FacingRight, TRUE
# 367 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 14, 20, METATILE_Lab_PuzzlePalace_TreeMiddleRight, TRUE
# 368 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 15, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 369 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 19, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 370 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 20, 20, METATILE_Lab_PuzzlePalace_TreeMiddleLeft, TRUE
	return


VictoryRoad_1F_EventScript_PuzzleVenusaur::
# 374 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_VENUSAUR, VictoryRoad_1F_EventScript_PuzzleVenusaur_1
	return

VictoryRoad_1F_EventScript_PuzzleVenusaur_1:
# 375 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 376 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE, 0
# 377 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_VENUSAUR
# 378 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 379 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleVenusaur_4
VictoryRoad_1F_EventScript_PuzzleVenusaur_3:
# 388 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleVenusaur_4:
# 380 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_VENUSAUR
# 381 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 382 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 383 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleVenusaur
# 384 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 385 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 386 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ShowClearPathToSouthWestPuzzles
	goto VictoryRoad_1F_EventScript_PuzzleVenusaur_3


VictoryRoad_1F_EventScript_ShowClearPathToSouthWestPuzzles:
# 393 "data/maps/VictoryRoad_1F/scripts.pory"
	special SpawnCameraObject
# 394 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToPathToSouthWest
# 395 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 396 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 397 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 398 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPathToSouthWestPuzzles
# 399 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 400 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 401 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToVenusaur
# 402 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 403 "data/maps/VictoryRoad_1F/scripts.pory"
	special RemoveCameraObject
	return


# 406 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToPathToSouthWest:
# 407 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 407 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 407 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 407 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 407 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 407 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 407 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 407 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 407 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 408 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
	step_end

# 411 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToVenusaur:
# 412 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 413 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 413 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 413 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 413 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 413 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 413 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 413 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 413 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 413 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
	step_end

VictoryRoad_1F_EventScript_ClearPathToSouthWestPuzzles:
# 417 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 9, 23, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 418 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 23, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 419 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 23, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 420 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 12, 23, METATILE_Lab_PuzzlePalace_TileCornerSouthEast, TRUE
# 421 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 9, 24, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 422 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 24, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 423 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 24, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 424 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 9, 25, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 425 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 25, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 426 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 25, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 427 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 9, 26, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 428 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 26, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 429 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 26, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 430 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 9, 27, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 431 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 27, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 432 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 27, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 433 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 9, 28, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 434 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 28, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 435 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 28, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 436 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 9, 29, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 437 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 29, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 438 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 29, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 439 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 9, 30, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 440 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 30, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 441 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 30, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 442 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 12, 30, METATILE_Lab_PuzzlePalace_Corner_FacingRight, TRUE
	return


VictoryRoad_1F_EventScript_PuzzleGolem::
# 446 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 447 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_LOST_WOODS, 0
# 448 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_GOLEM
# 449 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 450 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleGolem_2
VictoryRoad_1F_EventScript_PuzzleGolem_1:
# 454 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleGolem_2:
# 451 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_ImpossibleNothingHappened, MSGBOX_DEFAULT
# 452 "data/maps/VictoryRoad_1F/scripts.pory"
	closemessage
	goto VictoryRoad_1F_EventScript_PuzzleGolem_1


VictoryRoad_1F_EventScript_PuzzleMuk::
# 458 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 459 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_LOST_WOODS, 0
# 460 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_MUK
# 461 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 462 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleMuk_2
VictoryRoad_1F_EventScript_PuzzleMuk_1:
# 466 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleMuk_2:
# 463 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_ImpossibleNothingHappened, MSGBOX_DEFAULT
# 464 "data/maps/VictoryRoad_1F/scripts.pory"
	closemessage
	goto VictoryRoad_1F_EventScript_PuzzleMuk_1


VictoryRoad_1F_EventScript_PuzzleHoundoom::
# 470 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 471 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_LOST_WOODS, 0
# 472 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_HOUNDOOM
# 473 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 474 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleHoundoom_2
VictoryRoad_1F_EventScript_PuzzleHoundoom_1:
# 478 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleHoundoom_2:
# 475 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_ImpossibleNothingHappened, MSGBOX_DEFAULT
# 476 "data/maps/VictoryRoad_1F/scripts.pory"
	closemessage
	goto VictoryRoad_1F_EventScript_PuzzleHoundoom_1


VictoryRoad_1F_EventScript_PuzzlePidgeot::
# 482 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_PIDGEOT, VictoryRoad_1F_EventScript_PuzzlePidgeot_1
	return

VictoryRoad_1F_EventScript_PuzzlePidgeot_1:
# 483 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 484 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_LOST_WOODS, 0
# 485 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_PIDGEOT
# 486 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 487 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzlePidgeot_4
VictoryRoad_1F_EventScript_PuzzlePidgeot_3:
# 496 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzlePidgeot_4:
# 488 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_PIDGEOT
# 489 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 490 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 491 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzlePidgeot
# 492 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 493 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_NothingHappened, MSGBOX_DEFAULT
# 494 "data/maps/VictoryRoad_1F/scripts.pory"
	closemessage
	goto VictoryRoad_1F_EventScript_PuzzlePidgeot_3


VictoryRoad_1F_EventScript_PuzzleHitmonchan::
# 501 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_HITMONCHAN, VictoryRoad_1F_EventScript_PuzzleHitmonchan_1
	return

VictoryRoad_1F_EventScript_PuzzleHitmonchan_1:
# 502 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 503 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_LOST_WOODS, 0
# 504 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_HITMONCHAN
# 505 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 506 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleHitmonchan_4
VictoryRoad_1F_EventScript_PuzzleHitmonchan_3:
# 515 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleHitmonchan_4:
# 507 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_HITMONCHAN
# 508 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 509 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 510 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleHitmonchan
# 511 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 512 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_NothingHappened, MSGBOX_DEFAULT
# 513 "data/maps/VictoryRoad_1F/scripts.pory"
	closemessage
	goto VictoryRoad_1F_EventScript_PuzzleHitmonchan_3


VictoryRoad_1F_EventScript_PuzzleGengar::
# 520 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_GENGAR, VictoryRoad_1F_EventScript_PuzzleGengar_1
	return

VictoryRoad_1F_EventScript_PuzzleGengar_1:
# 521 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 522 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_LOST_WOODS, 0
# 523 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_GENGAR
# 524 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 525 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleGengar_4
VictoryRoad_1F_EventScript_PuzzleGengar_3:
# 534 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleGengar_4:
# 526 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_GENGAR
# 527 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 528 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 529 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleGengar
# 530 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 531 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 532 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ShowSetPuzzlesNorthWest
	goto VictoryRoad_1F_EventScript_PuzzleGengar_3


VictoryRoad_1F_EventScript_ShowSetPuzzlesNorthWest:
# 539 "data/maps/VictoryRoad_1F/scripts.pory"
	special SpawnCameraObject
# 540 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToNorthWestFromGengar
# 541 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 542 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 543 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 544 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_MASTEROFALLTRADES_PUZZLE_WALREIN, 6, 3
# 545 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_MASTEROFALLTRADES_PUZZLE_STEELIX, 10, 3
# 546 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_MASTEROFALLTRADES_PUZZLE_HERACROSS, 14, 3
# 547 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_SetPuzzlesNorthWest
# 548 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 549 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 550 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToGengar
# 551 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 552 "data/maps/VictoryRoad_1F/scripts.pory"
	special RemoveCameraObject
	return


# 555 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToNorthWestFromGengar:
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
	step_end

# 559 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToGengar:
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
	step_end

VictoryRoad_1F_EventScript_SetPuzzlesNorthWest:
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_SetPuzzleWalrein
# 565 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_SetPuzzleSteelix
# 566 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_SetPuzzleHeracross
	return


VictoryRoad_1F_EventScript_ClearPuzzlesNorthWest:
# 570 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleWalrein
# 571 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleSteelix
# 572 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleHeracross
	return


VictoryRoad_1F_EventScript_PuzzleCharizard::
# 576 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_CHARIZARD, VictoryRoad_1F_EventScript_PuzzleCharizard_1
	return

VictoryRoad_1F_EventScript_PuzzleCharizard_1:
# 577 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 578 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_LOST_WOODS, 0
# 579 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_CHARIZARD
# 580 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 581 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleCharizard_4
VictoryRoad_1F_EventScript_PuzzleCharizard_3:
# 590 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleCharizard_4:
# 582 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_CHARIZARD
# 583 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 584 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 585 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleCharizard
# 586 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 587 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 588 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ShowClearPathToNorthWestPuzzles
	goto VictoryRoad_1F_EventScript_PuzzleCharizard_3


VictoryRoad_1F_EventScript_ShowClearPathToNorthWestPuzzles:
# 595 "data/maps/VictoryRoad_1F/scripts.pory"
	special SpawnCameraObject
# 596 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToPathToNorthWest
# 597 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 598 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 599 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 600 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPathToNorthWestPuzzles
# 601 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 602 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 603 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToCharizard
# 604 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 605 "data/maps/VictoryRoad_1F/scripts.pory"
	special RemoveCameraObject
	return


# 608 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToPathToNorthWest:
# 609 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 609 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 609 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 609 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 609 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 609 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 609 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 609 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 609 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 609 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 609 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 609 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 609 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 609 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 609 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 609 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 609 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 609 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 610 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
	step_end

# 613 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToCharizard:
# 614 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 615 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 615 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 615 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 615 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 615 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 615 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 615 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 615 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 615 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 615 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 615 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 615 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 615 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 615 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 615 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 615 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 615 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 615 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
	step_end

VictoryRoad_1F_EventScript_ClearPathToNorthWestPuzzles:
# 619 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 17, 10, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 620 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 17, 11, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 621 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 17, 12, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 622 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 17, 13, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 623 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 18, 13, METATILE_Lab_PuzzlePalace_Corner_FacingRight, TRUE
	return


VictoryRoad_1F_EventScript_PuzzleSteelix::
# 627 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 628 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_DEDUCTIONS, 0
# 629 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_STEELIX
# 630 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 631 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleSteelix_2
VictoryRoad_1F_EventScript_PuzzleSteelix_1:
# 635 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleSteelix_2:
# 632 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_ImpossibleNothingHappened, MSGBOX_DEFAULT
# 633 "data/maps/VictoryRoad_1F/scripts.pory"
	closemessage
	goto VictoryRoad_1F_EventScript_PuzzleSteelix_1


VictoryRoad_1F_EventScript_PuzzleHeracross::
# 639 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 640 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_DEDUCTIONS, 0
# 641 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_HERACROSS
# 642 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 643 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleHeracross_2
VictoryRoad_1F_EventScript_PuzzleHeracross_1:
# 647 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleHeracross_2:
# 644 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_ImpossibleNothingHappened, MSGBOX_DEFAULT
# 645 "data/maps/VictoryRoad_1F/scripts.pory"
	closemessage
	goto VictoryRoad_1F_EventScript_PuzzleHeracross_1


VictoryRoad_1F_EventScript_PuzzleWalrein::
# 651 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_WALREIN, VictoryRoad_1F_EventScript_PuzzleWalrein_1
	return

VictoryRoad_1F_EventScript_PuzzleWalrein_1:
# 652 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 653 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_DEDUCTIONS, 0
# 654 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_WALREIN
# 655 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 656 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleWalrein_4
VictoryRoad_1F_EventScript_PuzzleWalrein_3:
# 665 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleWalrein_4:
# 657 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_WALREIN
# 658 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 659 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 660 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleWalrein
# 661 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 662 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 663 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ShowSetPuzzleSalamence
	goto VictoryRoad_1F_EventScript_PuzzleWalrein_3


VictoryRoad_1F_EventScript_ShowSetPuzzleSalamence:
# 670 "data/maps/VictoryRoad_1F/scripts.pory"
	special SpawnCameraObject
# 671 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToSalamence
# 672 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 673 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 674 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 675 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_MASTEROFALLTRADES_PUZZLE_SALAMENCE, 26, 6
# 676 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_SetPuzzleSalamence
# 677 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 678 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 679 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToWalrein
# 680 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 681 "data/maps/VictoryRoad_1F/scripts.pory"
	special RemoveCameraObject
	return


# 684 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToSalamence:
# 685 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 685 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 685 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 686 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 686 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 686 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 686 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 686 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 686 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 686 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 686 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 686 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 686 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 686 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 686 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 686 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 686 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 686 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 686 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 686 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 686 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 686 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 686 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
	step_end

# 689 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToWalrein:
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 691 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 691 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 691 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
	step_end

VictoryRoad_1F_EventScript_PuzzleSalamence::
# 695 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_SALAMENCE, VictoryRoad_1F_EventScript_PuzzleSalamence_1
	return

VictoryRoad_1F_EventScript_PuzzleSalamence_1:
# 696 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 697 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_IMPORTANT, 0
# 698 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_SALAMENCE
# 699 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 700 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleSalamence_4
VictoryRoad_1F_EventScript_PuzzleSalamence_3:
# 707 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleSalamence_4:
# 701 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_SALAMENCE
# 702 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 703 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 704 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPathToFinalPuzzle
# 705 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
	goto VictoryRoad_1F_EventScript_PuzzleSalamence_3


VictoryRoad_1F_EventScript_BlockPathToFinalPuzzle:
# 712 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 25, 3, METATILE_Building_Void, TRUE
# 713 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 3, METATILE_Building_Void, TRUE
# 714 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 3, METATILE_Building_Void, TRUE
# 715 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 24, 4, METATILE_Building_Void, TRUE
# 716 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 25, 4, METATILE_Building_Void, TRUE
# 717 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 4, METATILE_Building_Void, TRUE
# 718 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 4, METATILE_Building_Void, TRUE
# 719 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 4, METATILE_Building_Void, TRUE
# 720 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 24, 5, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 721 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 25, 5, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 722 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 5, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 723 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 5, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 724 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 5, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 725 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 24, 6, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 726 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 25, 6, METATILE_Lab_PuzzlePalace_SmallTree_Top_Wall_Bottom, TRUE
# 727 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 6, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 728 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 6, METATILE_Lab_PuzzlePalace_SmallTree_Top_Wall_Bottom, TRUE
# 729 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 6, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 730 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 7, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
	return


VictoryRoad_1F_EventScript_ClearPathToFinalPuzzle:
# 734 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 25, 3, METATILE_Building_Void, TRUE
# 735 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 3, METATILE_Building_Void, TRUE
# 736 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 3, METATILE_Building_Void, TRUE
# 737 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 24, 4, METATILE_Lab_PuzzlePalace_Wall_TopCornerNorthWest, TRUE
# 738 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 25, 4, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 739 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 4, METATILE_Lab_PuzzlePalace_Wall_TopPuzzle, TRUE
# 740 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 4, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 741 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 4, METATILE_Lab_PuzzlePalace_Wall_TopCornerNorthEast, TRUE
# 742 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 24, 5, METATILE_Lab_PuzzlePalace_Wall_BottomCornerSouthWest, TRUE
# 743 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 25, 5, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 744 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 5, METATILE_Lab_PuzzlePalace_Wall_BottomPuzzle, TRUE
# 745 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 5, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 746 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 5, METATILE_Lab_PuzzlePalace_Wall_BottomCornerSouthEast, TRUE
# 747 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 24, 6, METATILE_Lab_PuzzlePalace_Corner_FacingLeftShaded, TRUE
# 748 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 25, 6, METATILE_Lab_PuzzlePalace_SmallTree_TopShaded, FALSE
# 749 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 6, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 750 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 6, METATILE_Lab_PuzzlePalace_SmallTree_TopShaded, FALSE
# 751 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 6, METATILE_Lab_PuzzlePalace_Corner_FacingRightShaded, TRUE
# 752 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 7, METATILE_Lab_PuzzlePalace_TileArrowUp, FALSE
	return


VictoryRoad_1F_EventScript_PuzzleNumbersMagic::
# 756 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_NUMBERS_MAGIC, VictoryRoad_1F_EventScript_PuzzleNumbersMagic_1
	return

VictoryRoad_1F_EventScript_PuzzleNumbersMagic_1:
# 757 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 758 "data/maps/VictoryRoad_1F/scripts.pory"
	fadenewbgm MUS_PUZZLE_IMPORTANT
# 759 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_MagicSquare, MSGBOX_DEFAULT
# 760 "data/maps/VictoryRoad_1F/scripts.pory"
	closemessage
# 761 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_NUMBERS_MAGIC
# 762 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 763 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleNumbersMagic_4
VictoryRoad_1F_EventScript_PuzzleNumbersMagic_3:
# 770 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleNumbersMagic_4:
# 764 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag SLIDING_LAYOUT_NUMBERS_MAGIC
# 765 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 766 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 767 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleNumbersMagic
# 768 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
	goto VictoryRoad_1F_EventScript_PuzzleNumbersMagic_3


VictoryRoad_1F_EventScript_ItemSitrusBerry::
# 775 "data/maps/VictoryRoad_1F/scripts.pory"
	finditem ITEM_SITRUS_BERRY, 1
	return


VictoryRoad_1F_EventScript_ItemMasterBall::
# 779 "data/maps/VictoryRoad_1F/scripts.pory"
	finditem ITEM_MASTER_BALL, 1
	return


VictoryRoad_1F_EventScript_Rocker::
# 783 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_BOT_ROCKER, VictoryRoad_1F_Text_RockerIntro, VictoryRoad_1F_Text_RockerDefeated
# 784 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_RockerDefeated, MSGBOX_NPC
	return


VictoryRoad_1F_EventScript_StuckBoy::
# 788 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_ImStuck, MSGBOX_NPC
	return


VictoryRoad_1F_EventScript_DefeatedBeauty::
# 792 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_ThisIsTooDifficult, MSGBOX_NPC
	return


VictoryRoad_1F_EventScript_Hiker::
# 796 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_ImLookingForMetragross, MSGBOX_NPC
	return


VictoryRoad_1F_EventScript_ClearPuzzleAlakazam:
# 800 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 23, 18, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 801 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 23, 19, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleSnorlax:
# 805 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 17, 18, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 806 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 17, 19, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleDugtrio:
# 810 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 39, 15, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 811 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 39, 16, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleRaichu:
# 815 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 41, 29, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 816 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 36, 30, METATILE_Lab_PuzzlePalace_TileCornerSouthWestShaded, TRUE
# 817 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 37, 30, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 818 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 38, 30, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 819 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 39, 30, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 820 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 40, 30, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 821 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 41, 30, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 822 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 37, 31, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 823 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 38, 31, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 824 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 39, 31, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 825 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 40, 31, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 826 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 41, 31, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 827 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 37, 32, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 828 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 38, 32, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 829 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 39, 32, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 830 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 40, 32, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 831 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 41, 32, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 832 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 37, 33, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 833 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 38, 33, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 834 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 39, 33, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 835 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 40, 33, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 836 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 41, 33, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 837 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 37, 34, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 838 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 38, 34, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 839 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 39, 34, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 840 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 40, 34, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 841 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 41, 34, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 842 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 37, 35, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 843 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 38, 35, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 844 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 39, 35, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 845 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 40, 35, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 846 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 41, 35, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 847 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 37, 36, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 848 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 38, 36, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 849 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 39, 36, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 850 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 40, 36, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 851 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 41, 36, METATILE_Lab_PuzzlePalace_Tile, FALSE
	return


VictoryRoad_1F_EventScript_SetPuzzleBlastoise:
# 855 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 18, METATILE_Lab_PuzzlePalace_Wall_TopPuzzle, TRUE
# 856 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 19, METATILE_Lab_PuzzlePalace_Wall_BottomPuzzle, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleBlastoise:
# 860 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 18, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 861 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 19, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleVenusaur:
# 865 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 11, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 866 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 12, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzlePidgeot:
# 870 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 6, 29, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 871 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 6, 30, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleHitmonchan:
# 875 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 8, 38, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 876 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 8, 39, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleGengar:
# 880 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 38, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 881 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 39, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleCharizard:
# 885 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 16, 29, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 886 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 16, 30, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_SetPuzzleSteelix:
# 890 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 2, METATILE_Lab_PuzzlePalace_Wall_TopPuzzle, TRUE
# 891 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 3, METATILE_Lab_PuzzlePalace_Wall_BottomPuzzle, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleSteelix:
# 895 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 2, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 896 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 3, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_SetPuzzleHeracross:
# 900 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 14, 2, METATILE_Lab_PuzzlePalace_Wall_TopPuzzle, TRUE
# 901 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 14, 3, METATILE_Lab_PuzzlePalace_Wall_BottomPuzzle, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleHeracross:
# 905 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 14, 2, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 906 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 14, 3, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_SetPuzzleWalrein:
# 910 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 6, 2, METATILE_Lab_PuzzlePalace_Wall_TopPuzzle, TRUE
# 911 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 6, 3, METATILE_Lab_PuzzlePalace_Wall_BottomPuzzle, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleWalrein:
# 915 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 6, 2, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 916 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 6, 3, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_SetPuzzleSalamence:
# 920 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 5, METATILE_Lab_PuzzlePalace_Wall_TopPuzzle, TRUE
# 921 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 6, METATILE_Lab_PuzzlePalace_Wall_BottomPuzzle, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleNumbersMagic:
# 925 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 25, 3, METATILE_Lab_PuzzlePalace_DoorTopLeft, TRUE
# 926 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 3, METATILE_Lab_PuzzlePalace_DoorTop, TRUE
# 927 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 3, METATILE_Lab_PuzzlePalace_DoorTopRight, TRUE
# 928 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 25, 4, METATILE_Lab_PuzzlePalace_AboveDoorLeft, TRUE
# 929 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 4, METATILE_Lab_PuzzlePalace_AboveDoor, TRUE
# 930 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 4, METATILE_Lab_PuzzlePalace_AboveDoorRight, TRUE
# 931 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 25, 5, METATILE_Lab_PuzzlePalace_DoorLeft, TRUE
# 932 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 5, METATILE_Lab_PuzzlePalace_Upstairs, FALSE
# 933 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 5, METATILE_Lab_PuzzlePalace_DoorRight, TRUE
	return

