VictoryRoad_2F_MapScripts::
	.byte 0


VictoryRoad_2F_EventScript_PuzzleRayquaza::
# 4 "data/maps/VictoryRoad_2F/scripts.pory"
	lockall
# 5 "data/maps/VictoryRoad_2F/scripts.pory"
	playbgm MUS_FINAL_BATTLE, 0
# 6 "data/maps/VictoryRoad_2F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_RAYQUAZA
# 7 "data/maps/VictoryRoad_2F/scripts.pory"
	fadedefaultbgm
# 8 "data/maps/VictoryRoad_2F/scripts.pory"
	releaseall
	return

