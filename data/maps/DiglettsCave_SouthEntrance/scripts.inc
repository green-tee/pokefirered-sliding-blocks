DiglettsCave_SouthEntrance_MapScripts::
	.byte 0


DiglettsCave_SouthEntrance_EventScript_FloorSign::
# 4 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_FloorName, MSGBOX_SIGN
	return


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp1::
# 8 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 9 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_UP_1
# 10 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp1_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp1_1:
# 14 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp1_2:
# 11 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_1, MSGBOX_DEFAULT
# 12 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp1_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp2::
# 18 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 19 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_UP_2
# 20 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp2_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp2_1:
# 24 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp2_2:
# 21 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible2, MSGBOX_DEFAULT
# 22 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp2_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp3::
# 28 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 29 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_UP_3
# 30 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp3_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp3_1:
# 34 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp3_2:
# 31 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible3, MSGBOX_DEFAULT
# 32 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp3_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp4::
# 38 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 39 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_UP_4
# 40 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp4_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp4_1:
# 44 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp4_2:
# 41 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible4, MSGBOX_DEFAULT
# 42 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp4_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp5::
# 48 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 49 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_UP_5
# 50 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp5_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp5_1:
# 54 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp5_2:
# 51 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible5, MSGBOX_DEFAULT
# 52 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp5_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp6::
# 58 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 59 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_UP_6
# 60 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp6_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp6_1:
# 64 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp6_2:
# 61 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_6, MSGBOX_DEFAULT
# 62 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowUp6_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown1::
# 68 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 69 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_DOWN_1
# 70 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown1_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown1_1:
# 74 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown1_2:
# 71 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible1, MSGBOX_DEFAULT
# 72 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown1_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown2::
# 78 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 79 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_DOWN_2
# 80 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown2_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown2_1:
# 84 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown2_2:
# 81 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible2, MSGBOX_DEFAULT
# 82 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown2_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown3::
# 88 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 89 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_DOWN_3
# 90 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown3_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown3_1:
# 94 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown3_2:
# 91 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_3, MSGBOX_DEFAULT
# 92 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown3_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown4::
# 98 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 99 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_DOWN_4
# 100 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown4_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown4_1:
# 104 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown4_2:
# 101 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible4, MSGBOX_DEFAULT
# 102 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown4_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown5::
# 108 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 109 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_DOWN_5
# 110 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown5_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown5_1:
# 114 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown5_2:
# 111 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible5, MSGBOX_DEFAULT
# 112 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown5_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown6::
# 118 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 119 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_DOWN_6
# 120 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown6_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown6_1:
# 124 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown6_2:
# 121 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible6, MSGBOX_DEFAULT
# 122 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowDown6_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft1::
# 128 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 129 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_LEFT_1
# 130 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft1_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft1_1:
# 134 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft1_2:
# 131 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible1, MSGBOX_DEFAULT
# 132 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft1_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft2::
# 138 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 139 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_LEFT_2
# 140 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft2_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft2_1:
# 144 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft2_2:
# 141 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible2, MSGBOX_DEFAULT
# 142 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft2_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft3::
# 148 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 149 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_LEFT_3
# 150 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft3_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft3_1:
# 154 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft3_2:
# 151 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible3, MSGBOX_DEFAULT
# 152 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft3_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft4::
# 158 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 159 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_LEFT_4
# 160 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft4_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft4_1:
# 164 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft4_2:
# 161 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible4, MSGBOX_DEFAULT
# 162 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft4_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft5::
# 168 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 169 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_LEFT_5
# 170 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft5_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft5_1:
# 174 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft5_2:
# 171 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_5, MSGBOX_DEFAULT
# 172 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft5_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft6::
# 178 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 179 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_LEFT_6
# 180 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft6_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft6_1:
# 184 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft6_2:
# 181 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible6, MSGBOX_DEFAULT
# 182 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowLeft6_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight1::
# 188 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 189 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_RIGHT_1
# 190 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight1_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight1_1:
# 194 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight1_2:
# 191 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible1, MSGBOX_DEFAULT
# 192 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight1_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight2::
# 198 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 199 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_RIGHT_2
# 200 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight2_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight2_1:
# 204 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight2_2:
# 201 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_2, MSGBOX_DEFAULT
# 202 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight2_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight3::
# 208 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 209 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_RIGHT_3
# 210 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight3_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight3_1:
# 214 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight3_2:
# 211 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible3, MSGBOX_DEFAULT
# 212 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight3_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight4::
# 218 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 219 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_RIGHT_4
# 220 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight4_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight4_1:
# 224 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight4_2:
# 221 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_4, MSGBOX_DEFAULT
# 222 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight4_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight5::
# 228 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 229 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_RIGHT_5
# 230 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight5_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight5_1:
# 234 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight5_2:
# 231 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible5, MSGBOX_DEFAULT
# 232 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight5_1


DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight6::
# 238 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	lockall
# 239 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	playslidingblocks SLIDING_LAYOUT_ARROW_RIGHT_6
# 240 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight6_2
DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight6_1:
# 244 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	releaseall
	return

DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight6_2:
# 241 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_Impossible6, MSGBOX_DEFAULT
# 242 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	closemessage
	goto DiglettsCave_SouthEntrance_EventScript_PuzzleArrowRight6_1


DiglettsCave_SouthEntrance_EventScript_LostBoy::
# 248 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_KeepGoingLeft, MSGBOX_NPC
	return


DiglettsCave_SouthEntrance_EventScript_Grunt1::
# 252 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	trainerbattle_single TRAINER_BOT_GRUNT_1, DiglettsCave_SouthEntrance_Text_GruntIntroM, DiglettsCave_SouthEntrance_Text_GruntDefeatedM
# 253 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_ThePuzzlesAreClues, MSGBOX_NPC
	return


DiglettsCave_SouthEntrance_EventScript_Grunt2::
# 257 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	trainerbattle_single TRAINER_BOT_GRUNT_2, DiglettsCave_SouthEntrance_Text_GruntIntroF, DiglettsCave_SouthEntrance_Text_GruntDefeatedF
# 258 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_RememberToGoLeft, MSGBOX_NPC
	return


DiglettsCave_SouthEntrance_EventScript_Grunt3::
# 262 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	trainerbattle_single TRAINER_BOT_GRUNT_3, DiglettsCave_SouthEntrance_Text_GruntIntroM, DiglettsCave_SouthEntrance_Text_GruntDefeatedM
# 263 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_ThePuzzlesAreClues, MSGBOX_NPC
	return


DiglettsCave_SouthEntrance_EventScript_Grunt4::
# 267 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	trainerbattle_single TRAINER_BOT_GRUNT_4, DiglettsCave_SouthEntrance_Text_GruntIntroF, DiglettsCave_SouthEntrance_Text_GruntDefeatedF
# 268 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_RememberToGoLeft, MSGBOX_NPC
	return


DiglettsCave_SouthEntrance_EventScript_Grunt5::
# 272 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	trainerbattle_single TRAINER_BOT_GRUNT_5, DiglettsCave_SouthEntrance_Text_GruntIntroM, DiglettsCave_SouthEntrance_Text_GruntDefeatedM
# 273 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_ThePuzzlesAreClues, MSGBOX_NPC
	return


DiglettsCave_SouthEntrance_EventScript_Grunt6::
# 277 "data/maps/DiglettsCave_SouthEntrance/scripts.pory"
	msgbox DiglettsCave_SouthEntrance_Text_RememberToGoLeft, MSGBOX_NPC
	return

