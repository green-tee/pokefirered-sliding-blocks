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


PalletTown_PlayerHouse_1F_EventScript_ProfOak::
# 39 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	lock
# 40 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	faceplayer
# 41 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayerHouse_1F_Text_WantPokemon, MSGBOX_YESNO
# 42 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PalletTown_PlayerHouse_1F_EventScript_ProfOak_2
PalletTown_PlayerHouse_1F_EventScript_ProfOak_1:
# 47 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	closemessage
# 48 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	release
	return

PalletTown_PlayerHouse_1F_EventScript_ProfOak_2:
# 43 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayerHouse_1F_Text_HereYouAre, MSGBOX_DEFAULT
# 44 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	givemon SPECIES_ABSOL, 35
# 45 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
	goto PalletTown_PlayerHouse_1F_EventScript_ProfOak_1


PalletTown_PlayersHouse_1F_Text_TestingSlidingBlocks::
# 30 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	.string "Texting whether sliding blocks works.$"

PalletTown_PlayersHouse_1F_Text_TestingSlidingBlocksDone::
# 34 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	.string "Testing finished.$"

PalletTown_PlayerHouse_1F_Text_WantPokemon::
# 51 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	.string "Do you want a Pokémon?$"

PalletTown_PlayerHouse_1F_Text_HereYouAre::
# 55 "data/maps/PalletTown_PlayersHouse_1F/scripts.pory"
	.string "OK, here you are.$"
