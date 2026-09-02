SevenIsland_TrainerTower_MapScripts::
# 8 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_TrainerTower_OnTransition
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


SevenIsland_TrainerTower_OnTransition::
# 12 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	setrespawn HEAL_LOCATION_SEVEN_ISLAND_TRAINER_TOWER
	return


SevenIsland_TrainerTower_EventScript_PalaceSign::
# 16 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	msgbox SevenIsland_TrainerTower_Text_PuzzlePalace, MSGBOX_SIGN
	return


SevenIsland_TrainerTower_EventScript_TurnPlayerNorth::
# 20 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	return


SevenIsland_TrainerTower_EventScript_Intro::
# 24 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	lockall
# 25 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	delay 30
# 26 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	msgbox SevenIsland_TrainerTower_Text_WelcomeToBrainingIsland, MSGBOX_DEFAULT
# 27 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	closemessage
# 28 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	playmoncry SPECIES_HO_OH, CRY_MODE_NORMAL
# 29 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	applymovement LOCALID_HO_OH, SevenIsland_TrainerTower_Movement_WalkDown
# 30 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	waitmovement LOCALID_HO_OH
# 31 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	msgbox SevenIsland_TrainerTower_Text_HoOh, MSGBOX_DEFAULT
# 32 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	closemessage
# 33 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	applymovement LOCALID_HO_OH, SevenIsland_TrainerTower_Movement_WalkDown
# 34 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	waitmovement LOCALID_HO_OH
# 35 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	removeobject LOCALID_HO_OH
# 36 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	givemon SPECIES_HO_OH, 50, ITEM_SMOKE_BALL
# 37 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 38 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 39 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SevenIsland_TrainerTower_EventScript_Intro_2
SevenIsland_TrainerTower_EventScript_Intro_1:
# 43 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	giveitem ITEM_ITEMFINDER
# 44 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	msgbox SevenIsland_TrainerTower_DoYourBest, MSGBOX_DEFAULT
# 45 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	closemessage
# 46 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	addvar VAR_MAP_SCENE_BRAINING_ISLAND, 1
# 47 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	releaseall
	return

SevenIsland_TrainerTower_EventScript_Intro_2:
# 40 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 41 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	call EventScript_ChangePokemonNickname
	goto SevenIsland_TrainerTower_EventScript_Intro_1


# 50 "data/maps/SevenIsland_TrainerTower/scripts.pory"
SevenIsland_TrainerTower_Movement_WalkDown:
# 51 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	walk_down
	step_end

SevenIsland_TrainerTower_EventScript_Nurse::
# 55 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	lockall
# 56 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 57 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	waitmovement 0
# 58 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	call EventScript_BrainingIslandNurse
# 59 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	releaseall
	return

