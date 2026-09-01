SevenIsland_TrainerTower_MapScripts::
# 2 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SevenIsland_TrainerTower_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 5 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SevenIsland_TrainerTower_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

SevenIsland_TrainerTower_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	map_script_2 VAR_MAP_SCENE_BRAINING_ISLAND, 0, SevenIsland_TrainerTower_EventScript_Intro
	.2byte 0

SevenIsland_TrainerTower_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 6 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	map_script_2 VAR_MAP_SCENE_BRAINING_ISLAND, 0, SevenIsland_TrainerTower_EventScript_TurnPlayerNorth
	.2byte 0


SevenIsland_TrainerTower_EventScript_PalaceSign::
# 11 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	msgbox SevenIsland_TrainerTower_Text_PuzzlePalace, MSGBOX_SIGN
	return


SevenIsland_TrainerTower_EventScript_TurnPlayerNorth::
# 15 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	return


SevenIsland_TrainerTower_EventScript_Intro::
# 19 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	lockall
# 20 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	delay 30
# 21 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	msgbox SevenIsland_TrainerTower_Text_WelcomeToBrainingIsland, MSGBOX_DEFAULT
# 22 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	closemessage
# 23 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	playmoncry SPECIES_HO_OH, CRY_MODE_NORMAL
# 24 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	applymovement LOCALID_HO_OH, SevenIsland_TrainerTower_Movement_WalkDown
# 25 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	waitmovement LOCALID_HO_OH
# 26 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	msgbox SevenIsland_TrainerTower_Text_HoOh, MSGBOX_DEFAULT
# 27 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	closemessage
# 28 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	applymovement LOCALID_HO_OH, SevenIsland_TrainerTower_Movement_WalkDown
# 29 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	waitmovement LOCALID_HO_OH
# 30 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	removeobject LOCALID_HO_OH
# 31 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	givemon SPECIES_HO_OH, 50, ITEM_SHELL_BELL
# 32 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 33 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 34 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SevenIsland_TrainerTower_EventScript_Intro_2
SevenIsland_TrainerTower_EventScript_Intro_1:
# 38 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	giveitem ITEM_ITEMFINDER
# 39 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	msgbox SevenIsland_TrainerTower_DoYourBest, MSGBOX_DEFAULT
# 40 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	closemessage
# 41 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	addvar VAR_MAP_SCENE_BRAINING_ISLAND, 1
# 42 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	releaseall
	return

SevenIsland_TrainerTower_EventScript_Intro_2:
# 35 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 36 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	call EventScript_ChangePokemonNickname
	goto SevenIsland_TrainerTower_EventScript_Intro_1


# 45 "data/maps/SevenIsland_TrainerTower/scripts.pory"
SevenIsland_TrainerTower_Movement_WalkDown:
# 46 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	walk_down
	step_end

SevenIsland_TrainerTower_EventScript_Nurse::
# 50 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	lockall
# 51 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 52 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	waitmovement 0
# 53 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	call EventScript_BrainingIslandNurse
# 54 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	releaseall
	return

