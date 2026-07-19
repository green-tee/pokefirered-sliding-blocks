PalletTown_PlayersHouse_2F_MapScripts::
# 2 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_PlayersHouse_2F_OnTransition
# 3 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_PlayersHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

PalletTown_PlayersHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 4 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 0, PalletTown_PlayersHouse_2F_FirstWarpIn
	.2byte 0


PalletTown_PlayersHouse_2F_OnTransition::
# 9 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	compare VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 0
	goto_if_eq PalletTown_PlayersHouse_2F_OnTransition_1
	return

PalletTown_PlayersHouse_2F_OnTransition_1:
# 10 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	setrespawn HEAL_LOCATION_PALLET_TOWN
	return


PalletTown_PlayersHouse_2F_FirstWarpIn::
# 15 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 16 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 1
	return


PalletTown_PlayersHouse_2F_EventScript_NES::
# 20 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	lock
# 21 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	msgbox PalletTown_PlayersHouse_2F_Text_TestingSlidingBlocks, MSGBOX_DEFAULT
# 22 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	closemessage
# 23 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_VOLTORB
# 24 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	msgbox PalletTown_PlayersHouse_2F_Text_TestingSlidingBlocksDone, MSGBOX_DEFAULT
# 25 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	closemessage
# 26 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	release
	return


PalletTown_PlayersHouse_2F_EventScript_PC::
# 38 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	lock
# 39 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	msgbox PalletTown_PlayersHouse_2F_Text_TestingSlidingBlocks, MSGBOX_DEFAULT
# 40 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	closemessage
# 41 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_TEST_HO_OH
# 42 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	msgbox PalletTown_PlayersHouse_2F_Text_TestingSlidingBlocksDone, MSGBOX_DEFAULT
# 43 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	closemessage
# 44 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	release
	return


PalletTown_PlayersHouse_2F_EventScript_Sign::
# 48 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	lock
# 49 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	msgbox PalletTown_PlayersHouse_2F_Text_TestingSlidingBlocks, MSGBOX_DEFAULT
# 50 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	closemessage
# 51 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ELECTRODE
# 52 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	msgbox PalletTown_PlayersHouse_2F_Text_TestingSlidingBlocksDone, MSGBOX_DEFAULT
# 53 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	closemessage
# 54 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	release
	return


PalletTown_PlayersHouse_2F_Text_TestingSlidingBlocks::
# 29 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	.string "Texting whether sliding blocks works.$"

PalletTown_PlayersHouse_2F_Text_TestingSlidingBlocksDone::
# 33 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	.string "Testing finished.$"
