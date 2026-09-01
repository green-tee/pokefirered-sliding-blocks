# 1 "data/scripts/pkmn_center_nurse.pory"

# 2 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse::
# 3 "data/scripts/pkmn_center_nurse.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 4 "data/scripts/pkmn_center_nurse.pory"
	message Text_WelcomeWantToHealPkmn
# 5 "data/scripts/pkmn_center_nurse.pory"
	waitmessage
# 6 "data/scripts/pkmn_center_nurse.pory"
	multichoice 19, 8, MULTICHOICE_YES_NO, FALSE | (TRUE << 1)
# 7 "data/scripts/pkmn_center_nurse.pory"
	switch VAR_RESULT
# 8 "data/scripts/pkmn_center_nurse.pory"
	case 0, EventScript_PkmnCenterNurse_HealPkmn
# 9 "data/scripts/pkmn_center_nurse.pory"
	case 1 EventScript_PkmnCenterNurse_Goodbye
# 10 "data/scripts/pkmn_center_nurse.pory"
	case SCR_MENU_CANCEL, EventScript_PkmnCenterNurse_Goodbye
# 11 "data/scripts/pkmn_center_nurse.pory"
	end
# 12 "data/scripts/pkmn_center_nurse.pory"

# 13 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_HealPkmn::
# 14 "data/scripts/pkmn_center_nurse.pory"
	incrementgamestat GAME_STAT_USED_POKECENTER
# 15 "data/scripts/pkmn_center_nurse.pory"
	message Text_TakeYourPkmnForFewSeconds
# 16 "data/scripts/pkmn_center_nurse.pory"
	waitmessage
# 17 "data/scripts/pkmn_center_nurse.pory"
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
# 18 "data/scripts/pkmn_center_nurse.pory"
	special SetUsedPkmnCenterQuestLogEvent
# 19 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_CheckTrainerTowerAndUnionRoom
# 20 "data/scripts/pkmn_center_nurse.pory"
	end
# 21 "data/scripts/pkmn_center_nurse.pory"

# 22 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_TakeAndHealPkmn::
# 23 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterLeft
# 24 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 25 "data/scripts/pkmn_center_nurse.pory"
	dofieldeffect FLDEFF_POKECENTER_HEAL
# 26 "data/scripts/pkmn_center_nurse.pory"
	waitfieldeffect FLDEFF_POKECENTER_HEAL
# 27 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 28 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 29 "data/scripts/pkmn_center_nurse.pory"
	special HealPlayerParty
# 30 "data/scripts/pkmn_center_nurse.pory"
	return
# 31 "data/scripts/pkmn_center_nurse.pory"

# 32 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_CheckTrainerTowerAndUnionRoom::
# 33 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_RESULT, IsPlayerNotInTrainerTowerLobby
# 34 "data/scripts/pkmn_center_nurse.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_PkmnCenterNurse_ReturnPkmn
# 35 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_RESULT, BufferUnionRoomPlayerName
# 36 "data/scripts/pkmn_center_nurse.pory"
	copyvar VAR_0x8008, VAR_RESULT
# 37 "data/scripts/pkmn_center_nurse.pory"
	goto_if_eq VAR_0x8008, 0, EventScript_PkmnCenterNurse_ReturnPkmn
# 38 "data/scripts/pkmn_center_nurse.pory"
	goto_if_eq VAR_0x8008, 1, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom
# 39 "data/scripts/pkmn_center_nurse.pory"
	end
# 40 "data/scripts/pkmn_center_nurse.pory"

# 41 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_ReturnPkmn::
# 42 "data/scripts/pkmn_center_nurse.pory"
	message Text_RestoredPkmnToFullHealth
# 43 "data/scripts/pkmn_center_nurse.pory"
	waitmessage
# 44 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_LAST_TALKED, Movement_Bow
# 45 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 46 "data/scripts/pkmn_center_nurse.pory"
	msgbox Text_WeHopeToSeeYouAgain
# 47 "data/scripts/pkmn_center_nurse.pory"
	return
# 48 "data/scripts/pkmn_center_nurse.pory"

# 49 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom::
# 50 "data/scripts/pkmn_center_nurse.pory"
	goto_if_set FLAG_SYS_INFORMED_OF_LOCAL_WIRELESS_PLAYER, EventScript_PkmnCenterNurse_ReturnPkmn
# 51 "data/scripts/pkmn_center_nurse.pory"
	msgbox Text_RestoredPkmnToFullHealth
# 52 "data/scripts/pkmn_center_nurse.pory"
	setflag FLAG_SYS_INFORMED_OF_LOCAL_WIRELESS_PLAYER
# 53 "data/scripts/pkmn_center_nurse.pory"
	message Text_PlayerIsPlayingRightNowGoForIt
# 54 "data/scripts/pkmn_center_nurse.pory"
	waitmessage
# 55 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_LAST_TALKED, Movement_Bow
# 56 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 57 "data/scripts/pkmn_center_nurse.pory"
	msgbox Text_WeHopeToSeeYouAgain
# 58 "data/scripts/pkmn_center_nurse.pory"
	return
# 59 "data/scripts/pkmn_center_nurse.pory"

# 60 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_Goodbye::
# 61 "data/scripts/pkmn_center_nurse.pory"
	msgbox Text_WeHopeToSeeYouAgain
# 62 "data/scripts/pkmn_center_nurse.pory"
	return
# 63 "data/scripts/pkmn_center_nurse.pory"

# 64 "data/scripts/pkmn_center_nurse.pory"
Movement_Bow::
# 65 "data/scripts/pkmn_center_nurse.pory"
	nurse_joy_bow
# 66 "data/scripts/pkmn_center_nurse.pory"
	delay_4
# 67 "data/scripts/pkmn_center_nurse.pory"
	step_end

EventScript_BrainingIslandNurse::
# 71 "data/scripts/pkmn_center_nurse.pory"
	message Text_HowMayIhelpYou
# 72 "data/scripts/pkmn_center_nurse.pory"
	waitmessage
# 73 "data/scripts/pkmn_center_nurse.pory"
	call EventScript_BrainingIslandNurse_MainLoop
	return


EventScript_BrainingIslandNurse_MainLoop:
# 77 "data/scripts/pkmn_center_nurse.pory"
	multichoice 16, 4, MULTICHOICE_NURSE, FALSE
# 78 "data/scripts/pkmn_center_nurse.pory"
	switch VAR_RESULT
# 79 "data/scripts/pkmn_center_nurse.pory"
	case 0, EventScript_BrainingIslandNurse_MainLoop_2
# 86 "data/scripts/pkmn_center_nurse.pory"
	case 1, EventScript_BrainingIslandNurse_MainLoop_3
# 105 "data/scripts/pkmn_center_nurse.pory"
	case 2, EventScript_BrainingIslandNurse_MainLoop_4
# 120 "data/scripts/pkmn_center_nurse.pory"
	msgbox Text_WeHopeToSeeYouAgain, MSGBOX_DEFAULT
# 121 "data/scripts/pkmn_center_nurse.pory"
	closemessage
	return

EventScript_BrainingIslandNurse_MainLoop_2:
# 81 "data/scripts/pkmn_center_nurse.pory"
	special HealPlayerParty
# 82 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_HEAL
# 83 "data/scripts/pkmn_center_nurse.pory"
	waitfanfare
# 84 "data/scripts/pkmn_center_nurse.pory"
	msgbox Text_RestoredPkmnToFullHealth, MSGBOX_DEFAULT
# 85 "data/scripts/pkmn_center_nurse.pory"
	call EventScript_BrainingIslandNurse_RepeatLoop
	return

EventScript_BrainingIslandNurse_MainLoop_3:
# 88 "data/scripts/pkmn_center_nurse.pory"
	msgbox Text_WhichShouldRelarn, MSGBOX_DEFAULT
# 89 "data/scripts/pkmn_center_nurse.pory"
	closemessage
# 90 "data/scripts/pkmn_center_nurse.pory"
	special ChooseMonForMoveRelearner
# 91 "data/scripts/pkmn_center_nurse.pory"
	waitstate
# 92 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_0x8004, PARTY_SIZE
	goto_if_lt EventScript_BrainingIslandNurse_MainLoop_7
EventScript_BrainingIslandNurse_MainLoop_6:
# 104 "data/scripts/pkmn_center_nurse.pory"
	call EventScript_BrainingIslandNurse_RepeatLoop
	return

EventScript_BrainingIslandNurse_MainLoop_4:
# 107 "data/scripts/pkmn_center_nurse.pory"
	msgbox Text_NicknameWhichMon, MSGBOX_DEFAULT
# 108 "data/scripts/pkmn_center_nurse.pory"
	closemessage
# 109 "data/scripts/pkmn_center_nurse.pory"
	special ChoosePartyMon
# 110 "data/scripts/pkmn_center_nurse.pory"
	waitstate
# 111 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_0x8004, PARTY_SIZE
	goto_if_lt EventScript_BrainingIslandNurse_MainLoop_10
EventScript_BrainingIslandNurse_MainLoop_9:
# 117 "data/scripts/pkmn_center_nurse.pory"
	call EventScript_BrainingIslandNurse_RepeatLoop
	return

EventScript_BrainingIslandNurse_MainLoop_7:
# 93 "data/scripts/pkmn_center_nurse.pory"
	special IsSelectedMonEgg
# 94 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_BrainingIslandNurse_MainLoop_12
	goto EventScript_BrainingIslandNurse_MainLoop_6

EventScript_BrainingIslandNurse_MainLoop_10:
# 112 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_RESULT, GetPartyMonSpecies
# 113 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_ne EventScript_BrainingIslandNurse_MainLoop_14
	goto EventScript_BrainingIslandNurse_MainLoop_9

EventScript_BrainingIslandNurse_MainLoop_12:
# 95 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_0x8005, 0
	goto_if_eq EventScript_BrainingIslandNurse_MainLoop_16
# 99 "data/scripts/pkmn_center_nurse.pory"
	special TeachMoveRelearnerMove
# 100 "data/scripts/pkmn_center_nurse.pory"
	waitstate
	goto EventScript_BrainingIslandNurse_MainLoop_6

EventScript_BrainingIslandNurse_MainLoop_14:
# 114 "data/scripts/pkmn_center_nurse.pory"
	call EventScript_ChangePokemonNickname
	goto EventScript_BrainingIslandNurse_MainLoop_9

EventScript_BrainingIslandNurse_MainLoop_16:
# 96 "data/scripts/pkmn_center_nurse.pory"
	msgbox Text_MonCantRelearn, MSGBOX_DEFAULT
# 97 "data/scripts/pkmn_center_nurse.pory"
	closemessage
	goto EventScript_BrainingIslandNurse_MainLoop_6


EventScript_BrainingIslandNurse_RepeatLoop:
# 126 "data/scripts/pkmn_center_nurse.pory"
	message Text_WhatElseCanIDo
# 127 "data/scripts/pkmn_center_nurse.pory"
	waitmessage
# 128 "data/scripts/pkmn_center_nurse.pory"
	call EventScript_BrainingIslandNurse_MainLoop
	return

