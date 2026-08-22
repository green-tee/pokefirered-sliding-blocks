DiglettsCave_SouthEntrance_MapScripts::
	.byte 0


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp1::
# 4 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 5 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_UP_1
# 6 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp1_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp1_1:
# 10 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp1_2:
# 7 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_1, MSGBOX_DEFAULT
# 8 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp1_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp2::
# 14 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 15 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_UP_2
# 16 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp2_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp2_1:
# 20 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp2_2:
# 17 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible2, MSGBOX_DEFAULT
# 18 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp2_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp3::
# 24 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 25 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_UP_3
# 26 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp3_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp3_1:
# 30 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp3_2:
# 27 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible3, MSGBOX_DEFAULT
# 28 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp3_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp4::
# 34 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 35 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_UP_4
# 36 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp4_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp4_1:
# 40 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp4_2:
# 37 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible4, MSGBOX_DEFAULT
# 38 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp4_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp5::
# 44 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 45 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_UP_5
# 46 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp5_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp5_1:
# 50 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp5_2:
# 47 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible5, MSGBOX_DEFAULT
# 48 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp5_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp6::
# 54 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 55 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_UP_6
# 56 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp6_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp6_1:
# 60 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp6_2:
# 57 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_6, MSGBOX_DEFAULT
# 58 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp6_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown1::
# 64 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 65 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_DOWN_1
# 66 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown1_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown1_1:
# 70 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown1_2:
# 67 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible1, MSGBOX_DEFAULT
# 68 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown1_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown2::
# 74 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 75 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_DOWN_2
# 76 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown2_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown2_1:
# 80 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown2_2:
# 77 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible2, MSGBOX_DEFAULT
# 78 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown2_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown3::
# 84 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 85 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_DOWN_3
# 86 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown3_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown3_1:
# 90 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown3_2:
# 87 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_3, MSGBOX_DEFAULT
# 88 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown3_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown4::
# 94 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 95 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_DOWN_4
# 96 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown4_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown4_1:
# 100 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown4_2:
# 97 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible4, MSGBOX_DEFAULT
# 98 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown4_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown5::
# 104 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 105 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_DOWN_5
# 106 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown5_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown5_1:
# 110 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown5_2:
# 107 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible5, MSGBOX_DEFAULT
# 108 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown5_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown6::
# 114 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 115 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_DOWN_6
# 116 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown6_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown6_1:
# 120 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown6_2:
# 117 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible6, MSGBOX_DEFAULT
# 118 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown6_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft1::
# 124 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 125 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_LEFT_1
# 126 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft1_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft1_1:
# 130 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft1_2:
# 127 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible1, MSGBOX_DEFAULT
# 128 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft1_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft2::
# 134 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 135 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_LEFT_2
# 136 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft2_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft2_1:
# 140 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft2_2:
# 137 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible2, MSGBOX_DEFAULT
# 138 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft2_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft3::
# 144 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 145 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_LEFT_3
# 146 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft3_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft3_1:
# 150 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft3_2:
# 147 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible3, MSGBOX_DEFAULT
# 148 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft3_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft4::
# 154 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 155 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_LEFT_4
# 156 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft4_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft4_1:
# 160 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft4_2:
# 157 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible4, MSGBOX_DEFAULT
# 158 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft4_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft5::
# 164 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 165 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_LEFT_5
# 166 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft5_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft5_1:
# 170 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft5_2:
# 167 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_5, MSGBOX_DEFAULT
# 168 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft5_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft6::
# 174 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 175 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_LEFT_6
# 176 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft6_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft6_1:
# 180 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft6_2:
# 177 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible6, MSGBOX_DEFAULT
# 178 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft6_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight1::
# 184 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 185 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_RIGHT_1
# 186 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight1_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight1_1:
# 190 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight1_2:
# 187 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible1, MSGBOX_DEFAULT
# 188 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight1_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight2::
# 194 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 195 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_RIGHT_2
# 196 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight2_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight2_1:
# 200 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight2_2:
# 197 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_2, MSGBOX_DEFAULT
# 198 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight2_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight3::
# 204 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 205 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_RIGHT_3
# 206 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight3_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight3_1:
# 210 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight3_2:
# 207 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible3, MSGBOX_DEFAULT
# 208 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight3_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight4::
# 214 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 215 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_RIGHT_4
# 216 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight4_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight4_1:
# 220 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight4_2:
# 217 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_4, MSGBOX_DEFAULT
# 218 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight4_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight5::
# 224 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 225 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_RIGHT_5
# 226 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight5_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight5_1:
# 230 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight5_2:
# 227 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible5, MSGBOX_DEFAULT
# 228 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight5_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight6::
# 234 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 235 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_RIGHT_6
# 236 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight6_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight6_1:
# 240 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight6_2:
# 237 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible6, MSGBOX_DEFAULT
# 238 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight6_1


DiglettsCave_SouthEntrance_EventScript_LostBoy::
# 244 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_KeepGoingLeft, MSGBOX_NPC
	return

