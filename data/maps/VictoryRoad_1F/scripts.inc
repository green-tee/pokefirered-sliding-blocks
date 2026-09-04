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


VictoryRoad_1F_EventScript_CreditsSign::
# 72 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_Credits, MSGBOX_SIGN
	return


VictoryRoad_1F_EventScript_PuzzleAlakazam::
# 76 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_ALAKAZAM, VictoryRoad_1F_EventScript_PuzzleAlakazam_1
	return

VictoryRoad_1F_EventScript_PuzzleAlakazam_1:
# 77 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 78 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_TUTORIAL, 0
# 79 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ALAKAZAM
# 80 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 81 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleAlakazam_4
VictoryRoad_1F_EventScript_PuzzleAlakazam_3:
# 90 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleAlakazam_4:
# 82 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_ALAKAZAM
# 83 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 84 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 85 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleAlakazam
# 86 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 87 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_NothingHappened, MSGBOX_DEFAULT
# 88 "data/maps/VictoryRoad_1F/scripts.pory"
	closemessage
	goto VictoryRoad_1F_EventScript_PuzzleAlakazam_3


VictoryRoad_1F_EventScript_PuzzleSnorlax::
# 95 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_SNORLAX, VictoryRoad_1F_EventScript_PuzzleSnorlax_1
	return

VictoryRoad_1F_EventScript_PuzzleSnorlax_1:
# 96 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 97 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_TUTORIAL, 0
# 98 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_SNORLAX
# 99 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 100 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleSnorlax_4
VictoryRoad_1F_EventScript_PuzzleSnorlax_3:
# 109 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleSnorlax_4:
# 101 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_SNORLAX
# 102 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 103 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 104 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleSnorlax
# 105 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 106 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 107 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ShowClearPathToPuzzleDugtrio
	goto VictoryRoad_1F_EventScript_PuzzleSnorlax_3


VictoryRoad_1F_EventScript_ShowClearPathToPuzzleDugtrio:
# 114 "data/maps/VictoryRoad_1F/scripts.pory"
	special SpawnCameraObject
# 115 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToPathToDugtrio
# 116 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 117 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 118 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 119 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPathToPuzzleDugtrio
# 120 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 121 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 122 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToSnorlax
# 123 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 124 "data/maps/VictoryRoad_1F/scripts.pory"
	special RemoveCameraObject
	return


# 127 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToPathToDugtrio:
# 128 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 128 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 128 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 128 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 128 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 128 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 128 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 128 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 128 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 128 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 128 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 128 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 129 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 129 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
	step_end

# 132 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToSnorlax:
# 133 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 133 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 134 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 134 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 134 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 134 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 134 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 134 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 134 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 134 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 134 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 134 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 134 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 134 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
	step_end

VictoryRoad_1F_EventScript_BlockPathToPuzzleDugtrio:
# 138 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 23, METATILE_Building_Void, TRUE
# 139 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 23, METATILE_Building_Void, TRUE
# 140 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 29, 23, METATILE_Building_Void, TRUE
# 141 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 23, METATILE_Building_Void, TRUE
# 142 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 23, METATILE_Building_Void, TRUE
# 143 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 23, METATILE_Building_Void, TRUE
# 144 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 24, METATILE_Building_Void, TRUE
# 145 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 29, 24, METATILE_Building_Void, TRUE
# 146 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 24, METATILE_Building_Void, TRUE
# 147 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 24, METATILE_Building_Void, TRUE
# 148 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 25, METATILE_Building_Void, TRUE
# 149 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 29, 25, METATILE_Building_Void, TRUE
# 150 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 25, METATILE_Building_Void, TRUE
# 151 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 25, METATILE_Building_Void, TRUE
# 152 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 26, METATILE_Building_Void, TRUE
# 153 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 29, 26, METATILE_Building_Void, TRUE
# 154 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 26, METATILE_Building_Void, TRUE
# 155 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 26, METATILE_Building_Void, TRUE
# 156 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 26, METATILE_Building_Void, TRUE
# 157 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 27, METATILE_Building_Void, TRUE
# 158 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 29, 27, METATILE_Building_Void, TRUE
# 159 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 27, METATILE_Building_Void, TRUE
# 160 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 27, METATILE_Building_Void, TRUE
# 161 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 27, METATILE_Building_Void, TRUE
# 162 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 33, 27, METATILE_Building_Void, TRUE
# 163 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 34, 27, METATILE_Building_Void, TRUE
# 164 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 35, 27, METATILE_Building_Void, TRUE
# 165 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 36, 27, METATILE_Building_Void, TRUE
# 166 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 37, 27, METATILE_Building_Void, TRUE
	return


VictoryRoad_1F_EventScript_ClearPathToPuzzleDugtrio:
# 170 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 23, METATILE_Lab_PuzzlePalace_TileCornerSouthWest, TRUE
# 171 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 23, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 172 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 29, 23, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 173 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 23, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 174 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 23, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 175 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 23, METATILE_Lab_PuzzlePalace_TileCornerSouthEast, TRUE
# 176 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 24, METATILE_Lab_PuzzlePalace_LedgeLeft, TRUE
# 177 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 29, 24, METATILE_Lab_PuzzlePalace_Ledge, TRUE
# 178 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 24, METATILE_Lab_PuzzlePalace_Ledge, TRUE
# 179 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 24, METATILE_Lab_PuzzlePalace_LedgeRight, TRUE
# 180 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 25, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 181 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 29, 25, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 182 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 25, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 183 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 25, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 184 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 26, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 185 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 29, 26, METATILE_Lab_PuzzlePalace_TallGrass, FALSE
# 186 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 26, METATILE_Lab_PuzzlePalace_TallGrass, FALSE
# 187 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 26, METATILE_Lab_PuzzlePalace_TallGrass, FALSE
# 188 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 26, METATILE_Lab_PuzzlePalace_Wall_TopCornerNorthEast, TRUE
# 189 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 27, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 190 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 29, 27, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 191 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 27, METATILE_Lab_PuzzlePalace_TallGrass, FALSE
# 192 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 27, METATILE_Lab_PuzzlePalace_TallGrass, FALSE
# 193 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 27, METATILE_Lab_PuzzlePalace_Wall_BottomCornerSouthEast, TRUE
# 194 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 33, 27, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 195 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 34, 27, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 196 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 35, 27, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 197 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 36, 27, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 198 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 37, 27, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
	return


VictoryRoad_1F_EventScript_PuzzleDugtrio::
# 202 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_DUGTRIO, VictoryRoad_1F_EventScript_PuzzleDugtrio_1
	return

VictoryRoad_1F_EventScript_PuzzleDugtrio_1:
# 203 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 204 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE, 0
# 205 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_DUGTRIO
# 206 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 207 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleDugtrio_4
VictoryRoad_1F_EventScript_PuzzleDugtrio_3:
# 216 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleDugtrio_4:
# 208 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_DUGTRIO
# 209 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 210 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 211 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleDugtrio
# 212 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 213 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 214 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ShowSetPuzzleBlastoiseAndClearPathToPuzzleRaichu
	goto VictoryRoad_1F_EventScript_PuzzleDugtrio_3


VictoryRoad_1F_EventScript_ShowSetPuzzleBlastoiseAndClearPathToPuzzleRaichu:
# 221 "data/maps/VictoryRoad_1F/scripts.pory"
	special SpawnCameraObject
# 222 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToBlastoiseFromDugtrio
# 223 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 224 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 225 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 226 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_MASTEROFALLTRADES_PUZZLE_BLASTOISE, 11, 19
# 227 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_SetPuzzleBlastoise
# 228 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 229 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 230 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToPathToRaichu
# 231 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 232 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 233 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 234 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPathToPuzzleRaichu
# 235 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 236 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 237 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToDugtrio
# 238 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 239 "data/maps/VictoryRoad_1F/scripts.pory"
	special RemoveCameraObject
	return


# 242 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToBlastoiseFromDugtrio:
# 243 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 243 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 243 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 244 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
	step_end

# 247 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToPathToRaichu:
# 248 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 248 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 248 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 248 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 248 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 248 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 248 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 248 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 248 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 248 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 248 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 248 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 248 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 248 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 248 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 248 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 248 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 248 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 248 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 249 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 249 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 249 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 249 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 249 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 249 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 249 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 249 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 249 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
	step_end

# 252 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToDugtrio:
# 253 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 253 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 253 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 253 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 253 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 253 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 253 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 253 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 253 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 254 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 254 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 254 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 254 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 254 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 254 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 254 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 254 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 254 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 254 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 254 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 254 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
	step_end

VictoryRoad_1F_EventScript_ClearPathToPuzzleRaichu:
# 258 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 30, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 259 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 30, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 260 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 30, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 261 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 33, 30, METATILE_Lab_PuzzlePalace_TileCornerSouthEastShaded, TRUE
# 262 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 31, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 263 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 31, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 264 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 31, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 265 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 32, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 266 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 32, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 267 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 32, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 268 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 33, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 269 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 33, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 270 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 33, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 271 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 34, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 272 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 34, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 273 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 34, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 274 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 30, 35, METATILE_Lab_PuzzlePalace_LedgeLeft, TRUE
# 275 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 31, 35, METATILE_Lab_PuzzlePalace_Ledge, TRUE
# 276 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 32, 35, METATILE_Lab_PuzzlePalace_LedgeRight, TRUE
	return


VictoryRoad_1F_EventScript_PuzzleRaichu::
# 280 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_RAICHU, VictoryRoad_1F_EventScript_PuzzleRaichu_1
	return

VictoryRoad_1F_EventScript_PuzzleRaichu_1:
# 281 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 282 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE, 0
# 283 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_RAICHU
# 284 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 285 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleRaichu_4
VictoryRoad_1F_EventScript_PuzzleRaichu_3:
# 292 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleRaichu_4:
# 286 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_RAICHU
# 287 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 288 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 289 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleRaichu
# 290 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
	goto VictoryRoad_1F_EventScript_PuzzleRaichu_3


VictoryRoad_1F_EventScript_PuzzleBlastoise::
# 297 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_BLASTOISE, VictoryRoad_1F_EventScript_PuzzleBlastoise_1
	return

VictoryRoad_1F_EventScript_PuzzleBlastoise_1:
# 298 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 299 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE, 0
# 300 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_BLASTOISE
# 301 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 302 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleBlastoise_4
VictoryRoad_1F_EventScript_PuzzleBlastoise_3:
# 311 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleBlastoise_4:
# 303 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_BLASTOISE
# 304 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 305 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 306 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleBlastoise
# 307 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 308 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 309 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ShowClearPathToPuzzleVenusaur
	goto VictoryRoad_1F_EventScript_PuzzleBlastoise_3


VictoryRoad_1F_EventScript_ShowClearPathToPuzzleVenusaur:
# 316 "data/maps/VictoryRoad_1F/scripts.pory"
	special SpawnCameraObject
# 317 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToPathToVenusaur
# 318 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 319 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 320 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 321 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPathToPuzzleVenusaur
# 322 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 323 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 324 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToBlastoiseFromVenusaur
# 325 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 326 "data/maps/VictoryRoad_1F/scripts.pory"
	special RemoveCameraObject
	return


# 329 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToPathToVenusaur:
# 330 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 330 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 330 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 330 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 330 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 330 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
	step_end

# 333 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToBlastoiseFromVenusaur:
# 334 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 334 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 334 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 334 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 334 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 334 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
	step_end

VictoryRoad_1F_EventScript_ClearPathToPuzzleVenusaur:
# 338 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 13, 12, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 339 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 14, 12, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 340 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 15, 12, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 341 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 13, 13, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 342 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 14, 13, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 343 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 15, 13, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 344 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 13, 14, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 345 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 14, 14, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 346 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 15, 14, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 347 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 16, 14, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 348 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 13, 15, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 349 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 14, 15, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 350 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 15, 15, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 351 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 16, 15, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 353 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 16, 16, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 354 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 17, 16, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 355 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 18, 16, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 356 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 15, 17, METATILE_Lab_PuzzlePalace_Wall_TopCornerNorthWest, TRUE
# 357 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 16, 17, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 358 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 17, 17, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 359 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 18, 17, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 360 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 19, 17, METATILE_Lab_PuzzlePalace_Wall_TopCornerNorthEast, TRUE
# 361 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 15, 18, METATILE_Lab_PuzzlePalace_Wall_BottomCornerSouthWest, TRUE
# 362 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 16, 18, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 363 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 17, 18, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 364 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 18, 18, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 365 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 19, 18, METATILE_Lab_PuzzlePalace_Wall_BottomCornerSouthEast, TRUE
# 366 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 15, 19, METATILE_Lab_PuzzlePalace_Corner_FacingLeftShaded, TRUE
# 367 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 16, 19, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 368 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 17, 19, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 369 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 18, 19, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 370 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 19, 19, METATILE_Lab_PuzzlePalace_Corner_FacingRight, TRUE
# 371 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 14, 20, METATILE_Lab_PuzzlePalace_TreeMiddleRight, TRUE
# 372 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 15, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 373 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 19, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 374 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 20, 20, METATILE_Lab_PuzzlePalace_TreeMiddleLeft, TRUE
	return


VictoryRoad_1F_EventScript_PuzzleVenusaur::
# 378 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_VENUSAUR, VictoryRoad_1F_EventScript_PuzzleVenusaur_1
	return

VictoryRoad_1F_EventScript_PuzzleVenusaur_1:
# 379 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 380 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE, 0
# 381 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_VENUSAUR
# 382 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 383 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleVenusaur_4
VictoryRoad_1F_EventScript_PuzzleVenusaur_3:
# 392 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleVenusaur_4:
# 384 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_VENUSAUR
# 385 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 386 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 387 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleVenusaur
# 388 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 389 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 390 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ShowClearPathToSouthWestPuzzles
	goto VictoryRoad_1F_EventScript_PuzzleVenusaur_3


VictoryRoad_1F_EventScript_ShowClearPathToSouthWestPuzzles:
# 397 "data/maps/VictoryRoad_1F/scripts.pory"
	special SpawnCameraObject
# 398 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToPathToSouthWest
# 399 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 400 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 401 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 402 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPathToSouthWestPuzzles
# 403 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 404 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 405 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToVenusaur
# 406 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 407 "data/maps/VictoryRoad_1F/scripts.pory"
	special RemoveCameraObject
	return


# 410 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToPathToSouthWest:
# 411 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 411 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 411 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 411 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 411 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 411 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 411 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 411 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 411 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 412 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
	step_end

# 415 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToVenusaur:
# 416 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 417 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 417 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 417 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 417 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 417 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 417 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 417 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 417 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 417 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
	step_end

VictoryRoad_1F_EventScript_ClearPathToSouthWestPuzzles:
# 421 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 9, 23, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 422 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 23, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 423 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 23, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 424 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 12, 23, METATILE_Lab_PuzzlePalace_TileCornerSouthEast, TRUE
# 425 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 9, 24, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 426 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 24, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 427 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 24, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 428 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 9, 25, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 429 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 25, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 430 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 25, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 431 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 9, 26, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 432 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 26, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 433 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 26, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 434 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 9, 27, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 435 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 27, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 436 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 27, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 437 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 9, 28, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 438 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 28, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 439 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 28, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 440 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 9, 29, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 441 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 29, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 442 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 29, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 443 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 9, 30, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 444 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 30, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 445 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 30, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 446 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 12, 30, METATILE_Lab_PuzzlePalace_Corner_FacingRight, TRUE
	return


VictoryRoad_1F_EventScript_PuzzleGolem::
# 450 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 451 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_LOST_WOODS, 0
# 452 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_GOLEM
# 453 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 454 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleGolem_2
VictoryRoad_1F_EventScript_PuzzleGolem_1:
# 458 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleGolem_2:
# 455 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_ImpossibleNothingHappened, MSGBOX_DEFAULT
# 456 "data/maps/VictoryRoad_1F/scripts.pory"
	closemessage
	goto VictoryRoad_1F_EventScript_PuzzleGolem_1


VictoryRoad_1F_EventScript_PuzzleMuk::
# 462 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 463 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_LOST_WOODS, 0
# 464 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_MUK
# 465 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 466 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleMuk_2
VictoryRoad_1F_EventScript_PuzzleMuk_1:
# 470 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleMuk_2:
# 467 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_ImpossibleNothingHappened, MSGBOX_DEFAULT
# 468 "data/maps/VictoryRoad_1F/scripts.pory"
	closemessage
	goto VictoryRoad_1F_EventScript_PuzzleMuk_1


VictoryRoad_1F_EventScript_PuzzleHoundoom::
# 474 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 475 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_LOST_WOODS, 0
# 476 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_HOUNDOOM
# 477 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 478 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleHoundoom_2
VictoryRoad_1F_EventScript_PuzzleHoundoom_1:
# 482 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleHoundoom_2:
# 479 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_ImpossibleNothingHappened, MSGBOX_DEFAULT
# 480 "data/maps/VictoryRoad_1F/scripts.pory"
	closemessage
	goto VictoryRoad_1F_EventScript_PuzzleHoundoom_1


VictoryRoad_1F_EventScript_PuzzlePidgeot::
# 486 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_PIDGEOT, VictoryRoad_1F_EventScript_PuzzlePidgeot_1
	return

VictoryRoad_1F_EventScript_PuzzlePidgeot_1:
# 487 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 488 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_LOST_WOODS, 0
# 489 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_PIDGEOT
# 490 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 491 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzlePidgeot_4
VictoryRoad_1F_EventScript_PuzzlePidgeot_3:
# 500 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzlePidgeot_4:
# 492 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_PIDGEOT
# 493 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 494 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 495 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzlePidgeot
# 496 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 497 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_NothingHappened, MSGBOX_DEFAULT
# 498 "data/maps/VictoryRoad_1F/scripts.pory"
	closemessage
	goto VictoryRoad_1F_EventScript_PuzzlePidgeot_3


VictoryRoad_1F_EventScript_PuzzleHitmonchan::
# 505 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_HITMONCHAN, VictoryRoad_1F_EventScript_PuzzleHitmonchan_1
	return

VictoryRoad_1F_EventScript_PuzzleHitmonchan_1:
# 506 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 507 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_LOST_WOODS, 0
# 508 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_HITMONCHAN
# 509 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 510 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleHitmonchan_4
VictoryRoad_1F_EventScript_PuzzleHitmonchan_3:
# 519 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleHitmonchan_4:
# 511 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_HITMONCHAN
# 512 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 513 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 514 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleHitmonchan
# 515 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 516 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_NothingHappened, MSGBOX_DEFAULT
# 517 "data/maps/VictoryRoad_1F/scripts.pory"
	closemessage
	goto VictoryRoad_1F_EventScript_PuzzleHitmonchan_3


VictoryRoad_1F_EventScript_PuzzleGengar::
# 524 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_GENGAR, VictoryRoad_1F_EventScript_PuzzleGengar_1
	return

VictoryRoad_1F_EventScript_PuzzleGengar_1:
# 525 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 526 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_LOST_WOODS, 0
# 527 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_GENGAR
# 528 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 529 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleGengar_4
VictoryRoad_1F_EventScript_PuzzleGengar_3:
# 538 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleGengar_4:
# 530 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_GENGAR
# 531 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 532 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 533 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleGengar
# 534 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 535 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 536 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ShowSetPuzzlesNorthWest
	goto VictoryRoad_1F_EventScript_PuzzleGengar_3


VictoryRoad_1F_EventScript_ShowSetPuzzlesNorthWest:
# 543 "data/maps/VictoryRoad_1F/scripts.pory"
	special SpawnCameraObject
# 544 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToNorthWestFromGengar
# 545 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 546 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 547 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 548 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_MASTEROFALLTRADES_PUZZLE_WALREIN, 6, 3
# 549 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_MASTEROFALLTRADES_PUZZLE_STEELIX, 10, 3
# 550 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_MASTEROFALLTRADES_PUZZLE_HERACROSS, 14, 3
# 551 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_SetPuzzlesNorthWest
# 552 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 553 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 554 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToGengar
# 555 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 556 "data/maps/VictoryRoad_1F/scripts.pory"
	special RemoveCameraObject
	return


# 559 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToNorthWestFromGengar:
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 560 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
	step_end

# 563 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToGengar:
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 564 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
	step_end

VictoryRoad_1F_EventScript_SetPuzzlesNorthWest:
# 568 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_SetPuzzleWalrein
# 569 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_SetPuzzleSteelix
# 570 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_SetPuzzleHeracross
	return


VictoryRoad_1F_EventScript_ClearPuzzlesNorthWest:
# 574 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleWalrein
# 575 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleSteelix
# 576 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleHeracross
	return


VictoryRoad_1F_EventScript_PuzzleCharizard::
# 580 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_CHARIZARD, VictoryRoad_1F_EventScript_PuzzleCharizard_1
	return

VictoryRoad_1F_EventScript_PuzzleCharizard_1:
# 581 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 582 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_LOST_WOODS, 0
# 583 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_CHARIZARD
# 584 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 585 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleCharizard_4
VictoryRoad_1F_EventScript_PuzzleCharizard_3:
# 594 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleCharizard_4:
# 586 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_CHARIZARD
# 587 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 588 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 589 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleCharizard
# 590 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 591 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 592 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ShowClearPathToNorthWestPuzzles
	goto VictoryRoad_1F_EventScript_PuzzleCharizard_3


VictoryRoad_1F_EventScript_ShowClearPathToNorthWestPuzzles:
# 599 "data/maps/VictoryRoad_1F/scripts.pory"
	special SpawnCameraObject
# 600 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToPathToNorthWest
# 601 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 602 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 603 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 604 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPathToNorthWestPuzzles
# 605 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 606 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 607 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToCharizard
# 608 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 609 "data/maps/VictoryRoad_1F/scripts.pory"
	special RemoveCameraObject
	return


# 612 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToPathToNorthWest:
# 613 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 613 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 613 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 613 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 613 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 613 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 613 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 613 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 613 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 613 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 613 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 613 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 613 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 613 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 613 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 613 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 613 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 613 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 614 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
	step_end

# 617 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToCharizard:
# 618 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 619 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 619 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 619 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 619 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 619 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 619 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 619 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 619 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 619 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 619 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 619 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 619 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 619 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 619 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 619 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 619 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 619 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 619 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
	step_end

VictoryRoad_1F_EventScript_ClearPathToNorthWestPuzzles:
# 623 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 17, 10, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 624 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 17, 11, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 625 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 17, 12, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 626 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 17, 13, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 627 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 18, 13, METATILE_Lab_PuzzlePalace_Corner_FacingRight, TRUE
	return


VictoryRoad_1F_EventScript_PuzzleSteelix::
# 631 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 632 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_DEDUCTIONS, 0
# 633 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_STEELIX
# 634 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 635 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleSteelix_2
VictoryRoad_1F_EventScript_PuzzleSteelix_1:
# 639 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleSteelix_2:
# 636 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_ImpossibleNothingHappened, MSGBOX_DEFAULT
# 637 "data/maps/VictoryRoad_1F/scripts.pory"
	closemessage
	goto VictoryRoad_1F_EventScript_PuzzleSteelix_1


VictoryRoad_1F_EventScript_PuzzleHeracross::
# 643 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 644 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_DEDUCTIONS, 0
# 645 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_HERACROSS
# 646 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 647 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleHeracross_2
VictoryRoad_1F_EventScript_PuzzleHeracross_1:
# 651 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleHeracross_2:
# 648 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_ImpossibleNothingHappened, MSGBOX_DEFAULT
# 649 "data/maps/VictoryRoad_1F/scripts.pory"
	closemessage
	goto VictoryRoad_1F_EventScript_PuzzleHeracross_1


VictoryRoad_1F_EventScript_PuzzleWalrein::
# 655 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_WALREIN, VictoryRoad_1F_EventScript_PuzzleWalrein_1
	return

VictoryRoad_1F_EventScript_PuzzleWalrein_1:
# 656 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 657 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_DEDUCTIONS, 0
# 658 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_WALREIN
# 659 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 660 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleWalrein_4
VictoryRoad_1F_EventScript_PuzzleWalrein_3:
# 669 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleWalrein_4:
# 661 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_WALREIN
# 662 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 663 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 664 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleWalrein
# 665 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 666 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 667 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ShowSetPuzzleSalamence
	goto VictoryRoad_1F_EventScript_PuzzleWalrein_3


VictoryRoad_1F_EventScript_ShowSetPuzzleSalamence:
# 674 "data/maps/VictoryRoad_1F/scripts.pory"
	special SpawnCameraObject
# 675 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToSalamence
# 676 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 677 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 678 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 679 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_MASTEROFALLTRADES_PUZZLE_SALAMENCE, 26, 6
# 680 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_SetPuzzleSalamence
# 681 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
# 682 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 683 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_1F_Movement_PanToWalrein
# 684 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 685 "data/maps/VictoryRoad_1F/scripts.pory"
	special RemoveCameraObject
	return


# 688 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToSalamence:
# 689 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 689 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 689 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_down
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
# 690 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_right
	step_end

# 693 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_PanToWalrein:
# 694 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 694 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 694 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 694 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 694 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 694 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 694 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 694 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 694 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 694 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 694 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 694 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 694 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 694 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 694 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 694 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 694 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 694 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 694 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 694 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_left
# 695 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 695 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
# 695 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_faster_up
	step_end

VictoryRoad_1F_EventScript_PuzzleSalamence::
# 699 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_SALAMENCE, VictoryRoad_1F_EventScript_PuzzleSalamence_1
	return

VictoryRoad_1F_EventScript_PuzzleSalamence_1:
# 700 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 701 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_IMPORTANT, 0
# 702 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_SALAMENCE
# 703 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 704 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleSalamence_4
VictoryRoad_1F_EventScript_PuzzleSalamence_3:
# 711 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleSalamence_4:
# 705 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_SOLVED_SALAMENCE
# 706 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 707 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 708 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPathToFinalPuzzle
# 709 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
	goto VictoryRoad_1F_EventScript_PuzzleSalamence_3


VictoryRoad_1F_EventScript_BlockPathToFinalPuzzle:
# 716 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 25, 3, METATILE_Building_Void, TRUE
# 717 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 3, METATILE_Building_Void, TRUE
# 718 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 3, METATILE_Building_Void, TRUE
# 719 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 24, 4, METATILE_Building_Void, TRUE
# 720 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 25, 4, METATILE_Building_Void, TRUE
# 721 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 4, METATILE_Building_Void, TRUE
# 722 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 4, METATILE_Building_Void, TRUE
# 723 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 4, METATILE_Building_Void, TRUE
# 724 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 24, 5, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 725 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 25, 5, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 726 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 5, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 727 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 5, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 728 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 5, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 729 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 24, 6, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 730 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 25, 6, METATILE_Lab_PuzzlePalace_SmallTree_Top_Wall_Bottom, TRUE
# 731 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 6, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 732 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 6, METATILE_Lab_PuzzlePalace_SmallTree_Top_Wall_Bottom, TRUE
# 733 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 6, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 734 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 7, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
	return


VictoryRoad_1F_EventScript_ClearPathToFinalPuzzle:
# 738 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 25, 3, METATILE_Building_Void, TRUE
# 739 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 3, METATILE_Building_Void, TRUE
# 740 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 3, METATILE_Building_Void, TRUE
# 741 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 24, 4, METATILE_Lab_PuzzlePalace_Wall_TopCornerNorthWest, TRUE
# 742 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 25, 4, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 743 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 4, METATILE_Lab_PuzzlePalace_Wall_TopPuzzle, TRUE
# 744 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 4, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 745 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 4, METATILE_Lab_PuzzlePalace_Wall_TopCornerNorthEast, TRUE
# 746 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 24, 5, METATILE_Lab_PuzzlePalace_Wall_BottomCornerSouthWest, TRUE
# 747 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 25, 5, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 748 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 5, METATILE_Lab_PuzzlePalace_Wall_BottomPuzzle, TRUE
# 749 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 5, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 750 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 5, METATILE_Lab_PuzzlePalace_Wall_BottomCornerSouthEast, TRUE
# 751 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 24, 6, METATILE_Lab_PuzzlePalace_Corner_FacingLeftShaded, TRUE
# 752 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 25, 6, METATILE_Lab_PuzzlePalace_SmallTree_TopShaded, FALSE
# 753 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 6, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 754 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 6, METATILE_Lab_PuzzlePalace_SmallTree_TopShaded, FALSE
# 755 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 28, 6, METATILE_Lab_PuzzlePalace_Corner_FacingRightShaded, TRUE
# 756 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 7, METATILE_Lab_PuzzlePalace_TileArrowUp, FALSE
	return


VictoryRoad_1F_EventScript_PuzzleNumbersMagic::
# 760 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_NUMBERS_MAGIC, VictoryRoad_1F_EventScript_PuzzleNumbersMagic_1
	return

VictoryRoad_1F_EventScript_PuzzleNumbersMagic_1:
# 761 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 762 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_PUZZLE_IMPORTANT, 0
# 763 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_MagicSquare, MSGBOX_DEFAULT
# 764 "data/maps/VictoryRoad_1F/scripts.pory"
	closemessage
# 765 "data/maps/VictoryRoad_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_NUMBERS_MAGIC
# 766 "data/maps/VictoryRoad_1F/scripts.pory"
	fadedefaultbgm
# 767 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_1F_EventScript_PuzzleNumbersMagic_4
VictoryRoad_1F_EventScript_PuzzleNumbersMagic_3:
# 774 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
	return

VictoryRoad_1F_EventScript_PuzzleNumbersMagic_4:
# 768 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag SLIDING_LAYOUT_NUMBERS_MAGIC
# 769 "data/maps/VictoryRoad_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 770 "data/maps/VictoryRoad_1F/scripts.pory"
	playse SE_UNLOCK
# 771 "data/maps/VictoryRoad_1F/scripts.pory"
	call VictoryRoad_1F_EventScript_ClearPuzzleNumbersMagic
# 772 "data/maps/VictoryRoad_1F/scripts.pory"
	special DrawWholeMapView
	goto VictoryRoad_1F_EventScript_PuzzleNumbersMagic_3


VictoryRoad_1F_EventScript_ItemSitrusBerry::
# 779 "data/maps/VictoryRoad_1F/scripts.pory"
	finditem ITEM_SITRUS_BERRY, 1
	return


VictoryRoad_1F_EventScript_ItemMasterBall::
# 783 "data/maps/VictoryRoad_1F/scripts.pory"
	finditem ITEM_MASTER_BALL, 1
	return


VictoryRoad_1F_EventScript_ClearPuzzleAlakazam:
# 787 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 23, 18, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 788 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 23, 19, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleSnorlax:
# 792 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 17, 18, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 793 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 17, 19, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleDugtrio:
# 797 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 39, 15, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 798 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 39, 16, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleRaichu:
# 802 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 41, 29, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 803 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 36, 30, METATILE_Lab_PuzzlePalace_TileCornerSouthWestShaded, TRUE
# 804 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 37, 30, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 805 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 38, 30, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 806 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 39, 30, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 807 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 40, 30, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 808 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 41, 30, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 809 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 37, 31, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 810 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 38, 31, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 811 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 39, 31, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 812 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 40, 31, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 813 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 41, 31, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 814 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 37, 32, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 815 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 38, 32, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 816 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 39, 32, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 817 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 40, 32, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 818 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 41, 32, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 819 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 37, 33, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 820 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 38, 33, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 821 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 39, 33, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 822 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 40, 33, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 823 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 41, 33, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 824 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 37, 34, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 825 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 38, 34, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 826 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 39, 34, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 827 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 40, 34, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 828 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 41, 34, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 829 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 37, 35, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 830 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 38, 35, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 831 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 39, 35, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 832 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 40, 35, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 833 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 41, 35, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 834 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 37, 36, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 835 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 38, 36, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 836 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 39, 36, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 837 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 40, 36, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 838 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 41, 36, METATILE_Lab_PuzzlePalace_Tile, FALSE
	return


VictoryRoad_1F_EventScript_SetPuzzleBlastoise:
# 842 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 18, METATILE_Lab_PuzzlePalace_Wall_TopPuzzle, TRUE
# 843 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 19, METATILE_Lab_PuzzlePalace_Wall_BottomPuzzle, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleBlastoise:
# 847 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 18, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 848 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 19, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleVenusaur:
# 852 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 11, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 853 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 11, 12, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzlePidgeot:
# 857 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 6, 29, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 858 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 6, 30, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleHitmonchan:
# 862 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 8, 38, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 863 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 8, 39, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleGengar:
# 867 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 38, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 868 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 39, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleCharizard:
# 872 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 16, 29, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 873 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 16, 30, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_SetPuzzleSteelix:
# 877 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 2, METATILE_Lab_PuzzlePalace_Wall_TopPuzzle, TRUE
# 878 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 3, METATILE_Lab_PuzzlePalace_Wall_BottomPuzzle, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleSteelix:
# 882 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 2, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 883 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 10, 3, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_SetPuzzleHeracross:
# 887 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 14, 2, METATILE_Lab_PuzzlePalace_Wall_TopPuzzle, TRUE
# 888 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 14, 3, METATILE_Lab_PuzzlePalace_Wall_BottomPuzzle, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleHeracross:
# 892 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 14, 2, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 893 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 14, 3, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_SetPuzzleWalrein:
# 897 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 6, 2, METATILE_Lab_PuzzlePalace_Wall_TopPuzzle, TRUE
# 898 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 6, 3, METATILE_Lab_PuzzlePalace_Wall_BottomPuzzle, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleWalrein:
# 902 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 6, 2, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 903 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 6, 3, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_1F_EventScript_SetPuzzleSalamence:
# 907 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 5, METATILE_Lab_PuzzlePalace_Wall_TopPuzzle, TRUE
# 908 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 6, METATILE_Lab_PuzzlePalace_Wall_BottomPuzzle, TRUE
	return


VictoryRoad_1F_EventScript_ClearPuzzleNumbersMagic:
# 912 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 25, 3, METATILE_Lab_PuzzlePalace_DoorTopLeft, TRUE
# 913 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 3, METATILE_Lab_PuzzlePalace_DoorTop, TRUE
# 914 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 3, METATILE_Lab_PuzzlePalace_DoorTopRight, TRUE
# 915 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 25, 4, METATILE_Lab_PuzzlePalace_AboveDoorLeft, TRUE
# 916 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 4, METATILE_Lab_PuzzlePalace_AboveDoor, TRUE
# 917 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 4, METATILE_Lab_PuzzlePalace_AboveDoorRight, TRUE
# 918 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 25, 5, METATILE_Lab_PuzzlePalace_DoorLeft, TRUE
# 919 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 26, 5, METATILE_Lab_PuzzlePalace_Upstairs, FALSE
# 920 "data/maps/VictoryRoad_1F/scripts.pory"
	setmetatile 27, 5, METATILE_Lab_PuzzlePalace_DoorRight, TRUE
	return

