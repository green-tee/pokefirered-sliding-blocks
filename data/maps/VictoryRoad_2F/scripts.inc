VictoryRoad_2F_MapScripts::
# 2 "data/maps/VictoryRoad_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_2F_OnLoad
# 3 "data/maps/VictoryRoad_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, VictoryRoad_2F_OnResume
	.byte 0


VictoryRoad_2F_OnLoad::
# 7 "data/maps/VictoryRoad_2F/scripts.pory"
	goto_if_unset FLAG_TEMP_1, VictoryRoad_2F_OnLoad_1
	return

VictoryRoad_2F_OnLoad_1:
# 8 "data/maps/VictoryRoad_2F/scripts.pory"
	call VictoryRoad_2F_EventScript_SetPuzzleRayquaza
	return


VictoryRoad_2F_OnResume::
# 13 "data/maps/VictoryRoad_2F/scripts.pory"
	goto_if_set FLAG_TEMP_2, VictoryRoad_2F_OnResume_1
	return

VictoryRoad_2F_OnResume_1:
# 14 "data/maps/VictoryRoad_2F/scripts.pory"
	removeobject LOCALID_RAYQUAZA_L
# 15 "data/maps/VictoryRoad_2F/scripts.pory"
	removeobject LOCALID_RAYQUAZA_R
	return


VictoryRoad_2F_EventScript_FloorSign::
# 20 "data/maps/VictoryRoad_2F/scripts.pory"
	msgbox VictoryRoad_2F_Text_FloorName, MSGBOX_SIGN
	return


VictoryRoad_2F_EventScript_CreditsSign::
# 24 "data/maps/VictoryRoad_2F/scripts.pory"
	msgbox VictoryRoad_2F_Text_Credits, MSGBOX_SIGN
	return


VictoryRoad_2F_EventScript_MasterBotTest::
# 28 "data/maps/VictoryRoad_2F/scripts.pory"
	lock
# 29 "data/maps/VictoryRoad_2F/scripts.pory"
	faceplayer
# 30 "data/maps/VictoryRoad_2F/scripts.pory"
	specialvar VAR_0x8004, CalculatePlayerPartyCount
# 31 "data/maps/VictoryRoad_2F/scripts.pory"
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
# 32 "data/maps/VictoryRoad_2F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_ge VictoryRoad_2F_EventScript_MasterBotTest_2
VictoryRoad_2F_EventScript_MasterBotTest_1:
# 38 "data/maps/VictoryRoad_2F/scripts.pory"
	release
	return

VictoryRoad_2F_EventScript_MasterBotTest_2:
# 33 "data/maps/VictoryRoad_2F/scripts.pory"
	playbgm MUS_FINAL_BATTLE, 0
# 34 "data/maps/VictoryRoad_2F/scripts.pory"
	trainerbattle_no_intro TRAINER_MASTER_BOT, VictoryRoad_2F_EventScript_MasterBotTest_Text_0
# 35 "data/maps/VictoryRoad_2F/scripts.pory"
	msgbox VictoryRoad_2F_EventScript_MasterBotTest_Text_1, MSGBOX_DEFAULT
# 36 "data/maps/VictoryRoad_2F/scripts.pory"
	closemessage
	goto VictoryRoad_2F_EventScript_MasterBotTest_1


VictoryRoad_2F_EventScript_PuzzleRayquaza::
# 42 "data/maps/VictoryRoad_2F/scripts.pory"
	lockall
# 43 "data/maps/VictoryRoad_2F/scripts.pory"
	specialvar VAR_0x8004, CalculatePlayerPartyCount
# 44 "data/maps/VictoryRoad_2F/scripts.pory"
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
# 45 "data/maps/VictoryRoad_2F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt VictoryRoad_2F_EventScript_PuzzleRayquaza_2
# 49 "data/maps/VictoryRoad_2F/scripts.pory"
	fadenewbgm MUS_PUZZLE_FINAL
# 50 "data/maps/VictoryRoad_2F/scripts.pory"
	special SpawnCameraObject
# 51 "data/maps/VictoryRoad_2F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_2F_Movement_PanCameraUp
# 52 "data/maps/VictoryRoad_2F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 53 "data/maps/VictoryRoad_2F/scripts.pory"
	msgbox VictoryRoad_2F_Text_ThisIsTheFinalPuzzle, MSGBOX_DEFAULT
# 54 "data/maps/VictoryRoad_2F/scripts.pory"
	closemessage
# 55 "data/maps/VictoryRoad_2F/scripts.pory"
	savebgm MUS_NONE
# 56 "data/maps/VictoryRoad_2F/scripts.pory"
	special RemoveCameraObject
# 57 "data/maps/VictoryRoad_2F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_RAYQUAZA
# 58 "data/maps/VictoryRoad_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne VictoryRoad_2F_EventScript_PuzzleRayquaza_5
# 88 "data/maps/VictoryRoad_2F/scripts.pory"
	fadedefaultbgm
# 89 "data/maps/VictoryRoad_2F/scripts.pory"
	special SpawnCameraObject
# 90 "data/maps/VictoryRoad_2F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_2F_Movement_PanCameraDown
# 91 "data/maps/VictoryRoad_2F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 92 "data/maps/VictoryRoad_2F/scripts.pory"
	special RemoveCameraObject
VictoryRoad_2F_EventScript_PuzzleRayquaza_1:
# 95 "data/maps/VictoryRoad_2F/scripts.pory"
	releaseall
	return

VictoryRoad_2F_EventScript_PuzzleRayquaza_2:
# 46 "data/maps/VictoryRoad_2F/scripts.pory"
	msgbox VictoryRoad_2F_Text_NeedTwoPokemon, MSGBOX_DEFAULT
# 47 "data/maps/VictoryRoad_2F/scripts.pory"
	closemessage
	goto VictoryRoad_2F_EventScript_PuzzleRayquaza_1

VictoryRoad_2F_EventScript_PuzzleRayquaza_5:
# 59 "data/maps/VictoryRoad_2F/scripts.pory"
	playbgm MUS_FINAL_BATTLE, 0
# 60 "data/maps/VictoryRoad_2F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 61 "data/maps/VictoryRoad_2F/scripts.pory"
	playse SE_UNLOCK
# 62 "data/maps/VictoryRoad_2F/scripts.pory"
	call VictoryRoad_2F_EventScript_ClearPuzzleRayquaza
# 63 "data/maps/VictoryRoad_2F/scripts.pory"
	special DrawWholeMapView
# 64 "data/maps/VictoryRoad_2F/scripts.pory"
	delay 30
# 65 "data/maps/VictoryRoad_2F/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_NORMAL
# 66 "data/maps/VictoryRoad_2F/scripts.pory"
	applymovement LOCALID_RAYQUAZA_L, VictoryRoad_2F_Movement_WalkDown
# 67 "data/maps/VictoryRoad_2F/scripts.pory"
	waitmovement LOCALID_RAYQUAZA_L
# 68 "data/maps/VictoryRoad_2F/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_NORMAL
# 69 "data/maps/VictoryRoad_2F/scripts.pory"
	applymovement LOCALID_RAYQUAZA_R, VictoryRoad_2F_Movement_WalkDown
# 70 "data/maps/VictoryRoad_2F/scripts.pory"
	waitmovement LOCALID_RAYQUAZA_R
# 71 "data/maps/VictoryRoad_2F/scripts.pory"
	delay 30
# 72 "data/maps/VictoryRoad_2F/scripts.pory"
	msgbox VictoryRoad_2F_Text_ImTheMasterBot, MSGBOX_DEFAULT
# 73 "data/maps/VictoryRoad_2F/scripts.pory"
	closemessage
# 74 "data/maps/VictoryRoad_2F/scripts.pory"
	setflag FLAG_TEMP_2
# 75 "data/maps/VictoryRoad_2F/scripts.pory"
	savebgm MUS_NONE
# 76 "data/maps/VictoryRoad_2F/scripts.pory"
	trainerbattle_no_intro TRAINER_MASTER_BOT, VictoryRoad_2F_MasterBotDefeated
# 77 "data/maps/VictoryRoad_2F/scripts.pory"
	msgbox VictoryRoad_2F_MasterBotAfterWin, MSGBOX_DEFAULT
# 78 "data/maps/VictoryRoad_2F/scripts.pory"
	closemessage
# 79 "data/maps/VictoryRoad_2F/scripts.pory"
	special SpawnCameraObject
# 80 "data/maps/VictoryRoad_2F/scripts.pory"
	applymovement LOCALID_CAMERA, VictoryRoad_2F_Movement_PanCameraDown
# 81 "data/maps/VictoryRoad_2F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 82 "data/maps/VictoryRoad_2F/scripts.pory"
	special RemoveCameraObject
# 83 "data/maps/VictoryRoad_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 84 "data/maps/VictoryRoad_2F/scripts.pory"
	msgbox VictoryRoad_2F_MasterBotCarvedName, MSGBOX_DEFAULT
# 85 "data/maps/VictoryRoad_2F/scripts.pory"
	closemessage
# 86 "data/maps/VictoryRoad_2F/scripts.pory"
	call VictoryRoad_2F_EventScript_PrepareForEndingAndRematch
	goto VictoryRoad_2F_EventScript_PuzzleRayquaza_1


# 98 "data/maps/VictoryRoad_2F/scripts.pory"
VictoryRoad_2F_Movement_PanCameraUp:
# 99 "data/maps/VictoryRoad_2F/scripts.pory"
	walk_slower_up
	step_end

# 102 "data/maps/VictoryRoad_2F/scripts.pory"
VictoryRoad_2F_Movement_PanCameraDown:
# 103 "data/maps/VictoryRoad_2F/scripts.pory"
	walk_slower_down
	step_end

# 106 "data/maps/VictoryRoad_2F/scripts.pory"
VictoryRoad_2F_Movement_WalkDown:
# 107 "data/maps/VictoryRoad_2F/scripts.pory"
	walk_down
	step_end

VictoryRoad_2F_EventScript_PrepareForEndingAndRematch:
# 111 "data/maps/VictoryRoad_2F/scripts.pory"
	call VictoryRoad_2F_EventScript_SetPuzzleRayquaza
# 112 "data/maps/VictoryRoad_2F/scripts.pory"
	addobject LOCALID_PUZZLE_RAYQUAZA
# 113 "data/maps/VictoryRoad_2F/scripts.pory"
	addobject LOCALID_RAYQUAZA_L
# 114 "data/maps/VictoryRoad_2F/scripts.pory"
	addobject LOCALID_RAYQUAZA_R
# 115 "data/maps/VictoryRoad_2F/scripts.pory"
	clearflag FLAG_TEMP_1
# 116 "data/maps/VictoryRoad_2F/scripts.pory"
	clearflag FLAG_TEMP_2
# 117 "data/maps/VictoryRoad_2F/scripts.pory"
	clearflag FLAG_TEMP_3
# 118 "data/maps/VictoryRoad_2F/scripts.pory"
	clearflag FLAG_TEMP_4
# 119 "data/maps/VictoryRoad_2F/scripts.pory"
	setobjectxyperm LOCALID_RAYQUAZA_L, 9, 16
# 120 "data/maps/VictoryRoad_2F/scripts.pory"
	setobjectxyperm LOCALID_RAYQUAZA_R, 11, 16
# 121 "data/maps/VictoryRoad_2F/scripts.pory"
	special HealPlayerParty
# 122 "data/maps/VictoryRoad_2F/scripts.pory"
	delay 30
# 123 "data/maps/VictoryRoad_2F/scripts.pory"
	savebgm MUS_PUZZLE_IMPORTANT
# 124 "data/maps/VictoryRoad_2F/scripts.pory"
	call EventScript_AskSaveGame
# 125 "data/maps/VictoryRoad_2F/scripts.pory"
	setvar VAR_MAP_SCENE_BRAINING_ISLAND, 2
# 126 "data/maps/VictoryRoad_2F/scripts.pory"
	warp MAP_SEVEN_ISLAND_TRAINER_TOWER, 24, 10
	return


VictoryRoad_2F_EventScript_SetPuzzleRayquaza:
# 130 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 7, 11, METATILE_Building_Void, TRUE
# 131 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 8, 11, METATILE_Building_Void, TRUE
# 132 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 9, 11, METATILE_Building_Void, TRUE
# 133 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 10, 11, METATILE_Building_Void, TRUE
# 134 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 11, 11, METATILE_Building_Void, TRUE
# 135 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 12, 11, METATILE_Building_Void, TRUE
# 136 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 13, 11, METATILE_Building_Void, TRUE
# 137 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 7, 12, METATILE_Building_Void, TRUE
# 138 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 8, 12, METATILE_Building_Void, TRUE
# 139 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 9, 12, METATILE_Building_Void, TRUE
# 140 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 10, 12, METATILE_Building_Void, TRUE
# 141 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 11, 12, METATILE_Building_Void, TRUE
# 142 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 12, 12, METATILE_Building_Void, TRUE
# 143 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 13, 12, METATILE_Building_Void, TRUE
# 144 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 7, 13, METATILE_Building_Void, TRUE
# 145 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 8, 13, METATILE_Building_Void, TRUE
# 146 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 9, 13, METATILE_Building_Void, TRUE
# 147 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 10, 13, METATILE_Building_Void, TRUE
# 148 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 11, 13, METATILE_Building_Void, TRUE
# 149 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 12, 13, METATILE_Building_Void, TRUE
# 150 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 13, 13, METATILE_Building_Void, TRUE
# 151 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 7, 14, METATILE_Building_Void, TRUE
# 152 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 8, 14, METATILE_Building_Void, TRUE
# 153 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 9, 14, METATILE_Building_Void, TRUE
# 154 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 10, 14, METATILE_Building_Void, TRUE
# 155 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 11, 14, METATILE_Building_Void, TRUE
# 156 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 12, 14, METATILE_Building_Void, TRUE
# 157 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 13, 14, METATILE_Building_Void, TRUE
# 158 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 7, 15, METATILE_Building_Void, TRUE
# 159 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 8, 15, METATILE_Building_Void, TRUE
# 160 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 9, 15, METATILE_Building_Void, TRUE
# 161 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 10, 15, METATILE_Building_Void, TRUE
# 162 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 11, 15, METATILE_Building_Void, TRUE
# 163 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 12, 15, METATILE_Building_Void, TRUE
# 164 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 13, 15, METATILE_Building_Void, TRUE
# 165 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 8, 16, METATILE_Building_Void, TRUE
# 166 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 9, 16, METATILE_Building_Void, TRUE
# 167 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 10, 16, METATILE_Building_Void, TRUE
# 168 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 11, 16, METATILE_Building_Void, TRUE
# 169 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 12, 16, METATILE_Building_Void, TRUE
# 170 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 8, 17, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 171 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 9, 17, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 172 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 10, 17, METATILE_Lab_PuzzlePalace_Wall_TopPuzzle, TRUE
# 173 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 11, 17, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 174 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 12, 17, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 175 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 8, 18, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 176 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 9, 18, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 177 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 10, 18, METATILE_Lab_PuzzlePalace_Wall_BottomPuzzle, TRUE
# 178 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 11, 18, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 179 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 12, 18, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return


VictoryRoad_2F_EventScript_ClearPuzzleRayquaza:
# 183 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 7, 11, METATILE_Lab_PuzzlePalace_Wall_TopCornerNorthWest, TRUE
# 184 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 8, 11, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 185 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 9, 11, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 186 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 10, 11, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 187 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 11, 11, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 188 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 12, 11, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 189 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 13, 11, METATILE_Lab_PuzzlePalace_Wall_TopCornerNorthEast, TRUE
# 190 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 7, 12, METATILE_Lab_PuzzlePalace_Wall_BottomCornerSouthWest, TRUE
# 191 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 8, 12, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 192 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 9, 12, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 193 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 10, 12, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 194 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 11, 12, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 195 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 12, 12, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 196 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 13, 12, METATILE_Lab_PuzzlePalace_Wall_BottomCornerSouthEast, TRUE
# 197 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 7, 13, METATILE_Lab_PuzzlePalace_Corner_FacingLeftShaded, TRUE
# 198 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 8, 13, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 199 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 9, 13, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 200 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 10, 13, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 201 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 11, 13, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 202 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 12, 13, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 203 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 13, 13, METATILE_Lab_PuzzlePalace_Corner_FacingRightShaded, TRUE
# 204 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 7, 14, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 205 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 8, 14, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 206 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 9, 14, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 207 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 10, 14, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 208 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 11, 14, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 209 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 12, 14, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 210 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 13, 14, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 211 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 7, 15, METATILE_Lab_PuzzlePalace_TileCornerSouthWestShaded, TRUE
# 212 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 8, 15, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 213 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 9, 15, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 214 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 10, 15, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 215 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 11, 15, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 216 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 12, 15, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 217 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 13, 15, METATILE_Lab_PuzzlePalace_TileCornerSouthEastShaded, TRUE
# 218 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 8, 16, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 219 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 9, 16, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 220 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 10, 16, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 221 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 11, 16, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 222 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 12, 16, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 223 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 8, 17, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 224 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 9, 17, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 225 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 10, 17, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 226 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 11, 17, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 227 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 12, 17, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 228 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 8, 18, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 229 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 9, 18, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 230 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 10, 18, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 231 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 11, 18, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 232 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 12, 18, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
	return


VictoryRoad_2F_EventScript_MasterBotTest_Text_0:
# 34 "data/maps/VictoryRoad_2F/scripts.pory"
	.string "Final boss test complete.$"

VictoryRoad_2F_EventScript_MasterBotTest_Text_1:
# 35 "data/maps/VictoryRoad_2F/scripts.pory"
	.string "Now release.$"
