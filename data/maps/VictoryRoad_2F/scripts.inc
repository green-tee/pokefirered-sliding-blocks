VictoryRoad_2F_MapScripts::
	.byte 0


VictoryRoad_2F_EventScript_FloorSign::
# 4 "data/maps/VictoryRoad_2F/scripts.pory"
	msgbox VictoryRoad_2F_Text_FloorName, MSGBOX_SIGN
	return


VictoryRoad_2F_EventScript_CreditsSign::
# 8 "data/maps/VictoryRoad_2F/scripts.pory"
	msgbox VictoryRoad_2F_Text_Credits, MSGBOX_SIGN
	return


VictoryRoad_2F_EventScript_MasterBotTest::
# 12 "data/maps/VictoryRoad_2F/scripts.pory"
	lock
# 13 "data/maps/VictoryRoad_2F/scripts.pory"
	faceplayer
# 14 "data/maps/VictoryRoad_2F/scripts.pory"
	specialvar VAR_0x8004, CalculatePlayerPartyCount
# 15 "data/maps/VictoryRoad_2F/scripts.pory"
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
# 16 "data/maps/VictoryRoad_2F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_ge VictoryRoad_2F_EventScript_MasterBotTest_2
VictoryRoad_2F_EventScript_MasterBotTest_1:
# 22 "data/maps/VictoryRoad_2F/scripts.pory"
	release
	return

VictoryRoad_2F_EventScript_MasterBotTest_2:
# 17 "data/maps/VictoryRoad_2F/scripts.pory"
	playbgm MUS_FINAL_BATTLE, 0
# 18 "data/maps/VictoryRoad_2F/scripts.pory"
	trainerbattle_no_intro TRAINER_MASTER_BOT, VictoryRoad_2F_EventScript_MasterBotTest_Text_0
# 19 "data/maps/VictoryRoad_2F/scripts.pory"
	msgbox VictoryRoad_2F_EventScript_MasterBotTest_Text_1, MSGBOX_DEFAULT
# 20 "data/maps/VictoryRoad_2F/scripts.pory"
	closemessage
	goto VictoryRoad_2F_EventScript_MasterBotTest_1


VictoryRoad_2F_EventScript_PuzzleRayquaza::
# 26 "data/maps/VictoryRoad_2F/scripts.pory"
	lockall
# 27 "data/maps/VictoryRoad_2F/scripts.pory"
	playbgm MUS_PUZZLE_FINAL, 0
# 28 "data/maps/VictoryRoad_2F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_RAYQUAZA
# 29 "data/maps/VictoryRoad_2F/scripts.pory"
	fadedefaultbgm
# 30 "data/maps/VictoryRoad_2F/scripts.pory"
	releaseall
	return


VictoryRoad_2F_EventScript_MasterBotTest_Text_0:
# 18 "data/maps/VictoryRoad_2F/scripts.pory"
	.string "Final boss test complete.$"

VictoryRoad_2F_EventScript_MasterBotTest_Text_1:
# 19 "data/maps/VictoryRoad_2F/scripts.pory"
	.string "Now release.$"
