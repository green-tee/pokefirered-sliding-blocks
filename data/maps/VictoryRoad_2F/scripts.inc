VictoryRoad_2F_MapScripts::
	.byte 0


VictoryRoad_2F_EventScript_FloorSign::
# 4 "data/maps/VictoryRoad_2F/scripts.pory"
	msgbox VictoryRoad_2F_Text_FloorName, MSGBOX_SIGN
	return


VictoryRoad_2F_EventScript_PuzzleRayquaza::
# 8 "data/maps/VictoryRoad_2F/scripts.pory"
	lockall
# 9 "data/maps/VictoryRoad_2F/scripts.pory"
	playbgm MUS_PUZZLE_FINAL, 0
# 10 "data/maps/VictoryRoad_2F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_RAYQUAZA
# 11 "data/maps/VictoryRoad_2F/scripts.pory"
	fadedefaultbgm
# 12 "data/maps/VictoryRoad_2F/scripts.pory"
	releaseall
	return

