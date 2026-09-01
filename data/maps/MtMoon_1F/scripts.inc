MtMoon_1F_MapScripts::
# 2 "data/maps/MtMoon_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MtMoon_1F_OnLoad
	.byte 0


MtMoon_1F_OnLoad::
# 6 "data/maps/MtMoon_1F/scripts.pory"
	goto_if_set FLAG_SOLVED_NUMBERS_1, MtMoon_1F_OnLoad_2
MtMoon_1F_OnLoad_1:
# 9 "data/maps/MtMoon_1F/scripts.pory"
	goto_if_set FLAG_SOLVED_NUMBERS_1234, MtMoon_1F_OnLoad_5
MtMoon_1F_OnLoad_4:
# 12 "data/maps/MtMoon_1F/scripts.pory"
	goto_if_set FLAG_SOLVED_NUMBERS_3X3, MtMoon_1F_OnLoad_8
MtMoon_1F_OnLoad_7:
# 15 "data/maps/MtMoon_1F/scripts.pory"
	goto_if_set FLAG_SOLVED_NUMBERS_REDS_ROUND, MtMoon_1F_OnLoad_11
MtMoon_1F_OnLoad_10:
# 18 "data/maps/MtMoon_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_NUMBERS_69, MtMoon_1F_OnLoad_13
	return

MtMoon_1F_OnLoad_2:
# 7 "data/maps/MtMoon_1F/scripts.pory"
	call MtMoon_1F_EventScript_ClearPuzzleNumbers1
	goto MtMoon_1F_OnLoad_1

MtMoon_1F_OnLoad_5:
# 10 "data/maps/MtMoon_1F/scripts.pory"
	call MtMoon_1F_EventScript_ClearPuzzleNumbers1234
	goto MtMoon_1F_OnLoad_4

MtMoon_1F_OnLoad_8:
# 13 "data/maps/MtMoon_1F/scripts.pory"
	call MtMoon_1F_EventScript_ClearPuzzleNumbers3x3
	goto MtMoon_1F_OnLoad_7

MtMoon_1F_OnLoad_11:
# 16 "data/maps/MtMoon_1F/scripts.pory"
	call MtMoon_1F_EventScript_ClearPuzzleNumbersRedsRound
	goto MtMoon_1F_OnLoad_10

MtMoon_1F_OnLoad_13:
# 19 "data/maps/MtMoon_1F/scripts.pory"
	call MtMoon_1F_EventScript_SetPuzzleNumbers69
	return


MtMoon_1F_EventScript_FloorSign::
# 24 "data/maps/MtMoon_1F/scripts.pory"
	msgbox MtMoon_1F_Text_FloorName, MSGBOX_SIGN
	return


MtMoon_1F_EventScript_PuzzleNumbers1::
# 28 "data/maps/MtMoon_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_NUMBERS_1, MtMoon_1F_EventScript_PuzzleNumbers1_1
	return

MtMoon_1F_EventScript_PuzzleNumbers1_1:
# 29 "data/maps/MtMoon_1F/scripts.pory"
	lockall
# 30 "data/maps/MtMoon_1F/scripts.pory"
	msgbox MtMoon_1F_Text_UseDPad, MSGBOX_DEFAULT
# 31 "data/maps/MtMoon_1F/scripts.pory"
	closemessage
# 32 "data/maps/MtMoon_1F/scripts.pory"
	playbgm MUS_PUZZLE_TUTORIAL, 0
# 33 "data/maps/MtMoon_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_NUMBERS_1
# 34 "data/maps/MtMoon_1F/scripts.pory"
	fadedefaultbgm
# 35 "data/maps/MtMoon_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne MtMoon_1F_EventScript_PuzzleNumbers1_4
MtMoon_1F_EventScript_PuzzleNumbers1_3:
# 42 "data/maps/MtMoon_1F/scripts.pory"
	releaseall
	return

MtMoon_1F_EventScript_PuzzleNumbers1_4:
# 36 "data/maps/MtMoon_1F/scripts.pory"
	setflag FLAG_SOLVED_NUMBERS_1
# 37 "data/maps/MtMoon_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 38 "data/maps/MtMoon_1F/scripts.pory"
	playse SE_UNLOCK
# 39 "data/maps/MtMoon_1F/scripts.pory"
	call MtMoon_1F_EventScript_ClearPuzzleNumbers1
# 40 "data/maps/MtMoon_1F/scripts.pory"
	special DrawWholeMapView
	goto MtMoon_1F_EventScript_PuzzleNumbers1_3


MtMoon_1F_EventScript_PuzzleNumbers1234::
# 47 "data/maps/MtMoon_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_NUMBERS_1234, MtMoon_1F_EventScript_PuzzleNumbers1234_1
	return

MtMoon_1F_EventScript_PuzzleNumbers1234_1:
# 48 "data/maps/MtMoon_1F/scripts.pory"
	lockall
# 49 "data/maps/MtMoon_1F/scripts.pory"
	msgbox MtMoon_1F_Text_CantMoveBorderedBlocks, MSGBOX_DEFAULT
# 50 "data/maps/MtMoon_1F/scripts.pory"
	closemessage
# 51 "data/maps/MtMoon_1F/scripts.pory"
	playbgm MUS_PUZZLE_TUTORIAL, 0
# 52 "data/maps/MtMoon_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_NUMBERS_1234
# 53 "data/maps/MtMoon_1F/scripts.pory"
	fadedefaultbgm
# 54 "data/maps/MtMoon_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne MtMoon_1F_EventScript_PuzzleNumbers1234_4
MtMoon_1F_EventScript_PuzzleNumbers1234_3:
# 61 "data/maps/MtMoon_1F/scripts.pory"
	releaseall
	return

MtMoon_1F_EventScript_PuzzleNumbers1234_4:
# 55 "data/maps/MtMoon_1F/scripts.pory"
	setflag FLAG_SOLVED_NUMBERS_1234
# 56 "data/maps/MtMoon_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 57 "data/maps/MtMoon_1F/scripts.pory"
	playse SE_UNLOCK
# 58 "data/maps/MtMoon_1F/scripts.pory"
	call MtMoon_1F_EventScript_ClearPuzzleNumbers1234
# 59 "data/maps/MtMoon_1F/scripts.pory"
	special DrawWholeMapView
	goto MtMoon_1F_EventScript_PuzzleNumbers1234_3


MtMoon_1F_EventScript_PuzzleNumbers3x3::
# 66 "data/maps/MtMoon_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_NUMBERS_3X3, MtMoon_1F_EventScript_PuzzleNumbers3x3_1
	return

MtMoon_1F_EventScript_PuzzleNumbers3x3_1:
# 67 "data/maps/MtMoon_1F/scripts.pory"
	lockall
# 68 "data/maps/MtMoon_1F/scripts.pory"
	msgbox MtMoon_1F_Text_Complete3x3, MSGBOX_DEFAULT
# 69 "data/maps/MtMoon_1F/scripts.pory"
	closemessage
# 70 "data/maps/MtMoon_1F/scripts.pory"
	playbgm MUS_PUZZLE_TUTORIAL, 0
# 71 "data/maps/MtMoon_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_NUMBERS_3X3
# 72 "data/maps/MtMoon_1F/scripts.pory"
	fadedefaultbgm
# 73 "data/maps/MtMoon_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne MtMoon_1F_EventScript_PuzzleNumbers3x3_4
MtMoon_1F_EventScript_PuzzleNumbers3x3_3:
# 80 "data/maps/MtMoon_1F/scripts.pory"
	releaseall
	return

MtMoon_1F_EventScript_PuzzleNumbers3x3_4:
# 74 "data/maps/MtMoon_1F/scripts.pory"
	setflag FLAG_SOLVED_NUMBERS_3X3
# 75 "data/maps/MtMoon_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 76 "data/maps/MtMoon_1F/scripts.pory"
	playse SE_UNLOCK
# 77 "data/maps/MtMoon_1F/scripts.pory"
	call MtMoon_1F_EventScript_ClearPuzzleNumbers3x3
# 78 "data/maps/MtMoon_1F/scripts.pory"
	special DrawWholeMapView
	goto MtMoon_1F_EventScript_PuzzleNumbers3x3_3


MtMoon_1F_EventScript_PuzzleNumbersRedsRound::
# 85 "data/maps/MtMoon_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_NUMBERS_REDS_ROUND, MtMoon_1F_EventScript_PuzzleNumbersRedsRound_1
	return

MtMoon_1F_EventScript_PuzzleNumbersRedsRound_1:
# 86 "data/maps/MtMoon_1F/scripts.pory"
	lockall
# 87 "data/maps/MtMoon_1F/scripts.pory"
	msgbox MtMoon_1F_Text_CanRotateRoundedBlocks, MSGBOX_DEFAULT
# 88 "data/maps/MtMoon_1F/scripts.pory"
	closemessage
# 89 "data/maps/MtMoon_1F/scripts.pory"
	playbgm MUS_PUZZLE_TUTORIAL, 0
# 90 "data/maps/MtMoon_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_NUMBERS_REDS_ROUND
# 91 "data/maps/MtMoon_1F/scripts.pory"
	fadedefaultbgm
# 92 "data/maps/MtMoon_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne MtMoon_1F_EventScript_PuzzleNumbersRedsRound_4
MtMoon_1F_EventScript_PuzzleNumbersRedsRound_3:
# 99 "data/maps/MtMoon_1F/scripts.pory"
	releaseall
	return

MtMoon_1F_EventScript_PuzzleNumbersRedsRound_4:
# 93 "data/maps/MtMoon_1F/scripts.pory"
	setflag FLAG_SOLVED_NUMBERS_REDS_ROUND
# 94 "data/maps/MtMoon_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 95 "data/maps/MtMoon_1F/scripts.pory"
	playse SE_UNLOCK
# 96 "data/maps/MtMoon_1F/scripts.pory"
	call MtMoon_1F_EventScript_ClearPuzzleNumbersRedsRound
# 97 "data/maps/MtMoon_1F/scripts.pory"
	special DrawWholeMapView
	goto MtMoon_1F_EventScript_PuzzleNumbersRedsRound_3


MtMoon_1F_EventScript_PuzzleNumbers69::
# 104 "data/maps/MtMoon_1F/scripts.pory"
	goto_if_unset FLAG_SOLVED_NUMBERS_69, MtMoon_1F_EventScript_PuzzleNumbers69_1
	return

MtMoon_1F_EventScript_PuzzleNumbers69_1:
# 105 "data/maps/MtMoon_1F/scripts.pory"
	lockall
# 106 "data/maps/MtMoon_1F/scripts.pory"
	msgbox MtMoon_1F_Text_ImpossiblePuzzles, MSGBOX_DEFAULT
# 107 "data/maps/MtMoon_1F/scripts.pory"
	closemessage
# 108 "data/maps/MtMoon_1F/scripts.pory"
	playbgm MUS_PUZZLE_TUTORIAL, 0
# 109 "data/maps/MtMoon_1F/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_NUMBERS_69
# 110 "data/maps/MtMoon_1F/scripts.pory"
	fadedefaultbgm
# 111 "data/maps/MtMoon_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne MtMoon_1F_EventScript_PuzzleNumbers69_4
MtMoon_1F_EventScript_PuzzleNumbers69_3:
# 118 "data/maps/MtMoon_1F/scripts.pory"
	releaseall
	return

MtMoon_1F_EventScript_PuzzleNumbers69_4:
# 112 "data/maps/MtMoon_1F/scripts.pory"
	setflag FLAG_SOLVED_NUMBERS_69
# 113 "data/maps/MtMoon_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 114 "data/maps/MtMoon_1F/scripts.pory"
	playse SE_UNLOCK
# 115 "data/maps/MtMoon_1F/scripts.pory"
	call MtMoon_1F_EventScript_ClearPuzzleNumbers69
# 116 "data/maps/MtMoon_1F/scripts.pory"
	special DrawWholeMapView
	goto MtMoon_1F_EventScript_PuzzleNumbers69_3


MtMoon_1F_EventScript_ClearPuzzleNumbers1:
# 123 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 2, 27, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 124 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 3, 27, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 125 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 4, 27, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 126 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 2, 28, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 127 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 3, 28, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 128 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 4, 28, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 129 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 2, 29, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 130 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 3, 29, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 131 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 4, 29, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 132 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 2, 30, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 133 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 3, 30, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 134 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 4, 30, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 135 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 5, 30, METATILE_Lab_PuzzlePalace_Corner_FacingRight, TRUE
	return


MtMoon_1F_EventScript_ClearPuzzleNumbers1234:
# 139 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 2, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 140 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 3, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 141 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 4, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 142 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 2, 21, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 143 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 3, 21, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 144 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 4, 21, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 145 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 2, 22, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 146 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 3, 22, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 147 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 4, 22, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 148 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 2, 23, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 149 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 3, 23, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 150 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 4, 23, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 151 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 5, 23, METATILE_Lab_PuzzlePalace_Corner_FacingRight, TRUE
	return


MtMoon_1F_EventScript_ClearPuzzleNumbers3x3:
# 155 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 27, 18, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 156 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 28, 18, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 157 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 29, 18, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 158 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 27, 19, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 159 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 28, 19, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 160 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 29, 19, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 161 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 27, 20, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 162 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 28, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 163 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 29, 20, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 164 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 27, 21, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 165 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 28, 21, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 166 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 29, 21, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 167 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 27, 22, METATILE_Lab_PuzzlePalace_TileShaded, FALSE
# 168 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 28, 22, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 169 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 29, 22, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 170 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 30, 22, METATILE_Lab_PuzzlePalace_Corner_FacingRight, TRUE
	return


MtMoon_1F_EventScript_ClearPuzzleNumbersRedsRound:
# 174 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 28, 13, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 175 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 28, 14, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 176 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 28, 15, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 177 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 28, 16, METATILE_Lab_PuzzlePalace_Tile, FALSE
# 178 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 29, 16, METATILE_Lab_PuzzlePalace_Corner_FacingRight, TRUE
	return


MtMoon_1F_EventScript_ClearPuzzleNumbers69:
# 182 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 27, 1, METATILE_Lab_PuzzlePalace_DoorTopLeft, TRUE
# 183 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 28, 1, METATILE_Lab_PuzzlePalace_DoorTop, TRUE
# 184 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 29, 1, METATILE_Lab_PuzzlePalace_DoorTopRight, TRUE
# 185 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 27, 2, METATILE_Lab_PuzzlePalace_AboveDoorLeft, TRUE
# 186 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 28, 2, METATILE_Lab_PuzzlePalace_AboveDoor, TRUE
# 187 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 29, 2, METATILE_Lab_PuzzlePalace_AboveDoorRight, TRUE
# 188 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 27, 3, METATILE_Lab_PuzzlePalace_DoorLeft, TRUE
# 189 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 28, 3, METATILE_Lab_PuzzlePalace_Upstairs, FALSE
# 190 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 29, 3, METATILE_Lab_PuzzlePalace_DoorRight, TRUE
	return


MtMoon_1F_EventScript_SetPuzzleNumbers69:
# 194 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 27, 1, METATILE_Building_Void, TRUE
# 195 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 28, 1, METATILE_Building_Void, TRUE
# 196 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 29, 1, METATILE_Building_Void, TRUE
# 197 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 27, 2, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 198 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 28, 2, METATILE_Lab_PuzzlePalace_Wall_TopPuzzle, TRUE
# 199 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 29, 2, METATILE_Lab_PuzzlePalace_Wall_Top, TRUE
# 200 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 27, 3, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
# 201 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 28, 3, METATILE_Lab_PuzzlePalace_Wall_BottomPuzzle, TRUE
# 202 "data/maps/MtMoon_1F/scripts.pory"
	setmetatile 29, 3, METATILE_Lab_PuzzlePalace_Wall_Bottom, TRUE
	return

