SevenIsland_TrainerTower_MapScripts::
# 9 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_TrainerTower_OnTransition
# 2 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SevenIsland_TrainerTower_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 6 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SevenIsland_TrainerTower_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

SevenIsland_TrainerTower_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	map_script_2 VAR_MAP_SCENE_BRAINING_ISLAND, 0, SevenIsland_TrainerTower_EventScript_Intro
# 4 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	map_script_2 VAR_MAP_SCENE_BRAINING_ISLAND, 2, SevenIsland_TrainerTower_EventScript_Ending
	.2byte 0

SevenIsland_TrainerTower_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 7 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	map_script_2 VAR_MAP_SCENE_BRAINING_ISLAND, 0, SevenIsland_TrainerTower_EventScript_TurnPlayerNorth
	.2byte 0


SevenIsland_TrainerTower_OnTransition::
# 13 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	setrespawn HEAL_LOCATION_SEVEN_ISLAND_TRAINER_TOWER
	return


SevenIsland_TrainerTower_EventScript_PalaceSign::
# 17 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	msgbox SevenIsland_TrainerTower_Text_PuzzlePalace, MSGBOX_SIGN
	return


SevenIsland_TrainerTower_EventScript_TurnPlayerNorth::
# 21 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	return


SevenIsland_TrainerTower_EventScript_Intro::
# 25 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	lockall
# 26 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	delay 30
# 27 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	msgbox SevenIsland_TrainerTower_Text_WelcomeToBrainingIsland, MSGBOX_DEFAULT
# 28 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	closemessage
# 29 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	playmoncry SPECIES_HO_OH, CRY_MODE_NORMAL
# 30 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	applymovement LOCALID_HO_OH, SevenIsland_TrainerTower_Movement_WalkDown
# 31 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	waitmovement LOCALID_HO_OH
# 32 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	msgbox SevenIsland_TrainerTower_Text_HoOh, MSGBOX_DEFAULT
# 33 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	closemessage
# 34 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	applymovement LOCALID_HO_OH, SevenIsland_TrainerTower_Movement_WalkDown
# 35 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	waitmovement LOCALID_HO_OH
# 36 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	removeobject LOCALID_HO_OH
# 37 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	givemon SPECIES_HO_OH, 50, ITEM_SMOKE_BALL
# 38 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 39 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 40 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SevenIsland_TrainerTower_EventScript_Intro_2
SevenIsland_TrainerTower_EventScript_Intro_1:
# 44 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	giveitem ITEM_ITEMFINDER
# 45 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	msgbox SevenIsland_TrainerTower_DoYourBest, MSGBOX_DEFAULT
# 46 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	closemessage
# 47 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	addvar VAR_MAP_SCENE_BRAINING_ISLAND, 1
# 48 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	releaseall
	return

SevenIsland_TrainerTower_EventScript_Intro_2:
# 41 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 42 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	call EventScript_ChangePokemonNickname
	goto SevenIsland_TrainerTower_EventScript_Intro_1


# 51 "data/maps/SevenIsland_TrainerTower/scripts.pory"
SevenIsland_TrainerTower_Movement_WalkDown:
# 52 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	walk_down
	step_end

SevenIsland_TrainerTower_EventScript_Ending::
# 56 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	lockall
# 57 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	delay 30
# 58 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	msgbox SevenIsland_TrainerTower_ThankYouForPlaying, MSGBOX_DEFAULT
# 59 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	closemessage
# 60 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	delay 30
# 61 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	applymovement LOCALID_PLAYER, SevenIsland_TrainerTower_Movement_WalkAway1
# 62 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	waitmovement LOCALID_PLAYER
# 63 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	applymovement LOCALID_PLAYER, SevenIsland_TrainerTower_Movement_WalkAway2
# 64 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 16
# 65 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	waitmovement LOCALID_PLAYER
# 66 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	fadeoutbgm 0
# 67 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	delay 120
# 68 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	special DoSoftReset
# 69 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	delay 30
# 70 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	releaseall
	return


# 73 "data/maps/SevenIsland_TrainerTower/scripts.pory"
SevenIsland_TrainerTower_Movement_WalkAway1:
# 74 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	walk_down
# 74 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	walk_down
# 74 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	walk_down
# 74 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	walk_down
# 74 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	walk_down
# 74 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	walk_down
	step_end

# 77 "data/maps/SevenIsland_TrainerTower/scripts.pory"
SevenIsland_TrainerTower_Movement_WalkAway2:
# 78 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	walk_down
# 78 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	walk_down
# 78 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	walk_down
# 78 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	walk_down
# 78 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	walk_down
# 78 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	walk_down
# 78 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	walk_down
# 78 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	walk_down
# 78 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	walk_down
# 78 "data/maps/SevenIsland_TrainerTower/scripts.pory"
	walk_down
	step_end
