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


VictoryRoad_2F_EventScript_PuzzleRayquaza::
# 12 "data/maps/VictoryRoad_2F/scripts.pory"
	lockall
# 13 "data/maps/VictoryRoad_2F/scripts.pory"
	playbgm MUS_PUZZLE_FINAL, 0
# 14 "data/maps/VictoryRoad_2F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_RAYQUAZA
# 15 "data/maps/VictoryRoad_2F/scripts.pory"
	fadedefaultbgm
# 16 "data/maps/VictoryRoad_2F/scripts.pory"
	releaseall
	return

