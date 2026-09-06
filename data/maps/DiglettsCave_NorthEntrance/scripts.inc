DiglettsCave_NorthEntrance_MapScripts::
# 2 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, DiglettsCave_NorthEntrance_OnLoad
	.byte 0


DiglettsCave_NorthEntrance_OnLoad::
# 6 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	goto_if_set FLAG_SOLVED_WHIRLPOOL_ISLANDS, DiglettsCave_NorthEntrance_OnLoad_2
DiglettsCave_NorthEntrance_OnLoad_1:
# 9 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	goto_if_set FLAG_SOLVED_EUSINE, DiglettsCave_NorthEntrance_OnLoad_5
DiglettsCave_NorthEntrance_OnLoad_4:
# 12 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	goto_if_unset FLAG_SOLVED_LUGIA, DiglettsCave_NorthEntrance_OnLoad_7
	return

DiglettsCave_NorthEntrance_OnLoad_2:
# 7 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	call DiglettsCave_NorthEntrance_EventScript_ClearPuzzleWhirlpoolIslands
	goto DiglettsCave_NorthEntrance_OnLoad_1

DiglettsCave_NorthEntrance_OnLoad_5:
# 10 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	call DiglettsCave_NorthEntrance_EventScript_ClearPuzzleEusine
	goto DiglettsCave_NorthEntrance_OnLoad_4

DiglettsCave_NorthEntrance_OnLoad_7:
# 13 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	call DiglettsCave_NorthEntrance_EventScript_SetPuzzleLugia
	return


DiglettsCave_NorthEntrance_EventScript_FloorSign::
# 18 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	msgbox DiglettsCave_NorthEntrance_Text_FloorName, MSGBOX_NPC
	return


DiglettsCave_NorthEntrance_EventScript_PuzzleWhirlpoolIslands::
# 22 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	goto_if_unset FLAG_SOLVED_WHIRLPOOL_ISLANDS, DiglettsCave_NorthEntrance_EventScript_PuzzleWhirlpoolIslands_1
	return

DiglettsCave_NorthEntrance_EventScript_PuzzleWhirlpoolIslands_1:
# 23 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	lockall
# 24 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	playbgm MUS_PUZZLE, 0
# 25 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_WHIRLPOOL_ISLANDS
# 26 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	fadedefaultbgm
# 27 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_NorthEntrance_EventScript_PuzzleWhirlpoolIslands_4
DiglettsCave_NorthEntrance_EventScript_PuzzleWhirlpoolIslands_3:
# 34 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_NorthEntrance_EventScript_PuzzleWhirlpoolIslands_4:
# 28 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setflag FLAG_SOLVED_WHIRLPOOL_ISLANDS
# 29 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	removeobject VAR_LAST_TALKED
# 30 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	playse SE_UNLOCK
# 31 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	call DiglettsCave_NorthEntrance_EventScript_ClearPuzzleWhirlpoolIslands
# 32 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	special DrawWholeMapView
	goto DiglettsCave_NorthEntrance_EventScript_PuzzleWhirlpoolIslands_3


DiglettsCave_NorthEntrance_EventScript_Eusine::
# 39 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	lock
# 40 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	faceplayer
# 41 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	msgbox DiglettsCave_NorthEntrance_Text_HowAboutABattle, MSGBOX_YESNO
# 42 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq DiglettsCave_NorthEntrance_EventScript_Eusine_2
# 60 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	msgbox DiglettsCave_NorthEntrance_Text_ComeBackIfYouCangeYourMind, MSGBOX_DEFAULT
# 61 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	closemessage
DiglettsCave_NorthEntrance_EventScript_Eusine_1:
# 63 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	release
	return

DiglettsCave_NorthEntrance_EventScript_Eusine_2:
# 43 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	msgbox DiglettsCave_NorthEntrance_Text_LetsGo, MSGBOX_DEFAULT
# 44 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	closemessage
# 45 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	playbgm MUS_BATTLE, 0
# 46 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	trainerbattle_no_intro TRAINER_EUSINE, DiglettsCave_NorthEntrance_Text_YouWinThisOne
# 47 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	specialvar VAR_RESULT, GetPartyAndPCCount
# 48 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	compare VAR_RESULT, 10
	goto_if_lt DiglettsCave_NorthEntrance_EventScript_Eusine_6
# 53 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	msgbox DiglettsCave_NorthEntrance_Text_TakeSitrusBerry, MSGBOX_DEFAULT
# 54 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	closemessage
# 55 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	giveitem ITEM_SITRUS_BERRY, 1
DiglettsCave_NorthEntrance_EventScript_Eusine_5:
# 57 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	msgbox DiglettsCave_NorthEntrance_Text_IllBattleYouAgain, MSGBOX_DEFAULT
# 58 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_NorthEntrance_EventScript_Eusine_1

DiglettsCave_NorthEntrance_EventScript_Eusine_6:
# 49 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	msgbox DiglettsCave_NorthEntrance_Text_TakeMasterBall, MSGBOX_DEFAULT
# 50 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	closemessage
# 51 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	giveitem ITEM_MASTER_BALL, 1
	goto DiglettsCave_NorthEntrance_EventScript_Eusine_5


DiglettsCave_NorthEntrance_EventScript_Boy::
# 67 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	goto_if_set FLAG_SOLVED_WHIRLPOOL_ISLANDS, DiglettsCave_NorthEntrance_EventScript_Boy_1
# 70 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	msgbox DiglettsCave_NorthEntrance_Text_ThisOneIsHard, MSGBOX_NPC
	return

DiglettsCave_NorthEntrance_EventScript_Boy_1:
# 68 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	msgbox DiglettsCave_NorthEntrance_Text_IllHaveToSolveItMyself, MSGBOX_NPC
	return


DiglettsCave_NorthEntrance_EventScript_PuzzleEusine::
# 75 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	goto_if_unset FLAG_SOLVED_EUSINE, DiglettsCave_NorthEntrance_EventScript_PuzzleEusine_1
	return

DiglettsCave_NorthEntrance_EventScript_PuzzleEusine_1:
# 76 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	lockall
# 77 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	playbgm MUS_PUZZLE, 0
# 78 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_EUSINE
# 79 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	fadedefaultbgm
# 80 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_NorthEntrance_EventScript_PuzzleEusine_4
DiglettsCave_NorthEntrance_EventScript_PuzzleEusine_3:
# 87 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_NorthEntrance_EventScript_PuzzleEusine_4:
# 81 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setflag FLAG_SOLVED_EUSINE
# 82 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	removeobject VAR_LAST_TALKED
# 83 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	playse SE_UNLOCK
# 84 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	call DiglettsCave_NorthEntrance_EventScript_ClearPuzzleEusine
# 85 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	special DrawWholeMapView
	goto DiglettsCave_NorthEntrance_EventScript_PuzzleEusine_3


DiglettsCave_NorthEntrance_EventScript_PuzzleLugia::
# 92 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	goto_if_unset FLAG_SOLVED_LUGIA, DiglettsCave_NorthEntrance_EventScript_PuzzleLugia_1
	return

DiglettsCave_NorthEntrance_EventScript_PuzzleLugia_1:
# 93 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	lockall
# 94 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	playbgm MUS_PUZZLE, 0
# 95 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_LUGIA
# 96 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	fadedefaultbgm
# 97 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_NorthEntrance_EventScript_PuzzleLugia_4
DiglettsCave_NorthEntrance_EventScript_PuzzleLugia_3:
# 104 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_NorthEntrance_EventScript_PuzzleLugia_4:
# 98 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setflag FLAG_SOLVED_LUGIA
# 99 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	removeobject VAR_LAST_TALKED
# 100 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	playse SE_UNLOCK
# 101 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	call DiglettsCave_NorthEntrance_EventScript_ClearPuzzleLugia
# 102 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	special DrawWholeMapView
	goto DiglettsCave_NorthEntrance_EventScript_PuzzleLugia_3


DiglettsCave_NorthEntrance_EventScript_ItemSitrusBerry::
# 109 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	finditem ITEM_SITRUS_BERRY, 1
	return


DiglettsCave_NorthEntrance_EventScript_ClearPuzzleWhirlpoolIslands::
# 113 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 38, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 114 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 38, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 115 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 38, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 116 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 39, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 117 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 39, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 118 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 39, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 119 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 40, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 120 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 40, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 121 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 40, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 122 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 41, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 123 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 41, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 124 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 41, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 125 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 22, 41, METATILE_Lab_PuzzlePalace_Corner_FacingRight, TRUE
	return


DiglettsCave_NorthEntrance_EventScript_ClearPuzzleEusine::
# 129 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 19, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 130 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 19, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 131 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 19, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 132 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 133 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 134 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 135 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 21, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 136 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 21, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 137 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 21, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 138 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 22, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 139 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 22, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 140 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 22, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 141 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 22, 22, METATILE_Lab_PuzzlePalace_Corner_FacingRight, TRUE
	return


DiglettsCave_NorthEntrance_EventScript_ClearPuzzleLugia::
# 145 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 1, METATILE_Lab_PuzzlePalace_DoorTopLeft, TRUE
# 146 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 1, METATILE_Lab_PuzzlePalace_DoorTop, TRUE
# 147 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 1, METATILE_Lab_PuzzlePalace_DoorTopRight, TRUE
# 148 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 2, METATILE_Lab_PuzzlePalace_AboveDoorLeft, TRUE
# 149 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 2, METATILE_Lab_PuzzlePalace_AboveDoor, TRUE
# 150 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 2, METATILE_Lab_PuzzlePalace_AboveDoorRight, TRUE
# 151 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 3, METATILE_Lab_PuzzlePalace_DoorLeft, TRUE
# 152 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 3, METATILE_Lab_PuzzlePalace_Upstairs, FALSE
# 153 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 3, METATILE_Lab_PuzzlePalace_DoorRight, TRUE
	return


DiglettsCave_NorthEntrance_EventScript_SetPuzzleLugia::
# 157 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 1, METATILE_Building_Void, TRUE
# 158 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 1, METATILE_Building_Void, TRUE
# 159 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 1, METATILE_Building_Void, TRUE
# 160 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 2, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 161 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 2, METATILE_Lab_PuzzlePalace_Wall_TopPuzzle, TRUE
# 162 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 2, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 163 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 19, 3, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 164 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 20, 3, METATILE_Lab_PuzzlePalace_Wall_BottomPuzzle, TRUE
# 165 "data/maps/DiglettsCave_NorthEntrance/scripts.pory"
	setmetatile 21, 3, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return

