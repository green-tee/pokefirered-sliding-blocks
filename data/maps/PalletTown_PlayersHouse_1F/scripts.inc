PalletTown_PlayersHouse_1F_MapScripts::
	.byte 0


PalletTown_PlayersHouse_1F_EventScript_Mom::
# 4 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayersHouse_1F_Text_TestingSlidingBlocks, MSGBOX_DEFAULT
# 5 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	closemessage
# 6 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_NUMBERS_1234
# 7 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayersHouse_1F_Text_TestingSlidingBlocksDone, MSGBOX_DEFAULT
# 8 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	closemessage
# 9 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	release
	return


PalletTown_PlayersHouse_1F_EventScript_TV::
# 12 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	lock
# 13 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayersHouse_1F_Text_TestingSlidingBlocks, MSGBOX_DEFAULT
# 14 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	closemessage
# 15 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_NUMBERS_1
# 16 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayersHouse_1F_Text_TestingSlidingBlocksDone, MSGBOX_DEFAULT
# 17 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	closemessage
# 18 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	release
	return


PalletTown_PlayersHouse_1F_EventScript_Psyduck::
# 22 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayersHouse_1F_Text_TestingSlidingBlocks, MSGBOX_DEFAULT
# 23 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	closemessage
# 24 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_NUMBERS_3X3
# 25 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayersHouse_1F_Text_TestingSlidingBlocksDone, MSGBOX_DEFAULT
# 26 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	closemessage
# 27 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	release
	return


PalletTown_PlayersHouse_1F_Text_TestingSlidingBlocks::
# 30 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	.string "Texting whether sliding blocks works.$"

PalletTown_PlayersHouse_1F_Text_TestingSlidingBlocksDone::
# 34 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	.string "Testing finished.$"
