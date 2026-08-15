# 1 "data/scripts/field_moves.pory"

# 2 "data/scripts/field_moves.pory"
EventScript_CutTree::
# 3 "data/scripts/field_moves.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 4 "data/scripts/field_moves.pory"
	lockall
# 5 "data/scripts/field_moves.pory"
	goto_if_unset FLAG_BADGE02_GET, EventScript_CantCutTree
# 6 "data/scripts/field_moves.pory"
	checkpartymove MOVE_CUT
# 7 "data/scripts/field_moves.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantCutTree
# 8 "data/scripts/field_moves.pory"
	setfieldeffectargument 0, VAR_RESULT
# 9 "data/scripts/field_moves.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 10 "data/scripts/field_moves.pory"
	buffermovename STR_VAR_2, MOVE_CUT
# 11 "data/scripts/field_moves.pory"
	msgbox Text_CutTreeDown, MSGBOX_YESNO
# 12 "data/scripts/field_moves.pory"
	goto_if_eq VAR_RESULT, NO, EventScript_DontCutTree
# 13 "data/scripts/field_moves.pory"
	msgbox Text_MonUsedMove
# 14 "data/scripts/field_moves.pory"
	closemessage
# 15 "data/scripts/field_moves.pory"
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
# 16 "data/scripts/field_moves.pory"
	waitstate
# 17 "data/scripts/field_moves.pory"
	goto EventScript_CutTreeDown
# 18 "data/scripts/field_moves.pory"
	end
# 19 "data/scripts/field_moves.pory"

# 20 "data/scripts/field_moves.pory"
EventScript_FldEffCut::
# 21 "data/scripts/field_moves.pory"
	lockall
# 22 "data/scripts/field_moves.pory"
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
# 23 "data/scripts/field_moves.pory"
	waitstate
# 24 "data/scripts/field_moves.pory"
	goto EventScript_CutTreeDown
# 25 "data/scripts/field_moves.pory"
	end
# 26 "data/scripts/field_moves.pory"

# 27 "data/scripts/field_moves.pory"
EventScript_CutTreeDown::
# 28 "data/scripts/field_moves.pory"
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
# 29 "data/scripts/field_moves.pory"
	waitmovement 0
# 30 "data/scripts/field_moves.pory"
	removeobject VAR_LAST_TALKED
# 31 "data/scripts/field_moves.pory"
	releaseall
# 32 "data/scripts/field_moves.pory"
	end
# 33 "data/scripts/field_moves.pory"

# 34 "data/scripts/field_moves.pory"
Movement_CutTreeDown::
# 35 "data/scripts/field_moves.pory"
	cut_tree
# 36 "data/scripts/field_moves.pory"
	step_end
# 37 "data/scripts/field_moves.pory"

# 38 "data/scripts/field_moves.pory"
EventScript_CantCutTree::
# 39 "data/scripts/field_moves.pory"
	msgbox Text_TreeCanBeCutDown, MSGBOX_SIGN
# 40 "data/scripts/field_moves.pory"
	releaseall
# 41 "data/scripts/field_moves.pory"
	end
# 42 "data/scripts/field_moves.pory"

# 43 "data/scripts/field_moves.pory"
EventScript_DontCutTree::
# 44 "data/scripts/field_moves.pory"
	closemessage
# 45 "data/scripts/field_moves.pory"
	releaseall
# 46 "data/scripts/field_moves.pory"
	end
# 47 "data/scripts/field_moves.pory"

# 48 "data/scripts/field_moves.pory"
Text_CutTreeDown::
# 49 "data/scripts/field_moves.pory"
	.string "This tree looks like it can be CUT\n"
# 50 "data/scripts/field_moves.pory"
	.string "down!\p"
# 51 "data/scripts/field_moves.pory"
	.string "Would you like to CUT it?$"
# 52 "data/scripts/field_moves.pory"

# 53 "data/scripts/field_moves.pory"
Text_MonUsedMove::
# 54 "data/scripts/field_moves.pory"
	.string "{STR_VAR_1} used {STR_VAR_2}!$"
# 55 "data/scripts/field_moves.pory"

# 56 "data/scripts/field_moves.pory"
Text_TreeCanBeCutDown::
# 57 "data/scripts/field_moves.pory"
	.string "This tree looks like it can be CUT\n"
# 58 "data/scripts/field_moves.pory"
	.string "down!$"
# 59 "data/scripts/field_moves.pory"

# 60 "data/scripts/field_moves.pory"
EventScript_RockSmash::
# 61 "data/scripts/field_moves.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 62 "data/scripts/field_moves.pory"
	lockall
# 63 "data/scripts/field_moves.pory"
	goto_if_unset FLAG_BADGE06_GET, EventScript_CantSmashRock
# 64 "data/scripts/field_moves.pory"
	checkpartymove MOVE_ROCK_SMASH
# 65 "data/scripts/field_moves.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSmashRock
# 66 "data/scripts/field_moves.pory"
	setfieldeffectargument 0, VAR_RESULT
# 67 "data/scripts/field_moves.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 68 "data/scripts/field_moves.pory"
	buffermovename STR_VAR_2, MOVE_ROCK_SMASH
# 69 "data/scripts/field_moves.pory"
	msgbox Text_UseRockSmash, MSGBOX_YESNO
# 70 "data/scripts/field_moves.pory"
	goto_if_eq VAR_RESULT, NO, EventScript_DontSmashRock
# 71 "data/scripts/field_moves.pory"
	msgbox Text_MonUsedMove
# 72 "data/scripts/field_moves.pory"
	closemessage
# 73 "data/scripts/field_moves.pory"
	dofieldeffect FLDEFF_USE_ROCK_SMASH
# 74 "data/scripts/field_moves.pory"
	waitstate
# 75 "data/scripts/field_moves.pory"
	goto EventScript_UseRockSmash
# 76 "data/scripts/field_moves.pory"
	end
# 77 "data/scripts/field_moves.pory"

# 78 "data/scripts/field_moves.pory"
EventScript_FldEffRockSmash::
# 79 "data/scripts/field_moves.pory"
	lockall
# 80 "data/scripts/field_moves.pory"
	dofieldeffect FLDEFF_USE_ROCK_SMASH
# 81 "data/scripts/field_moves.pory"
	waitstate
# 82 "data/scripts/field_moves.pory"
	goto EventScript_UseRockSmash
# 83 "data/scripts/field_moves.pory"
	end
# 84 "data/scripts/field_moves.pory"

# 85 "data/scripts/field_moves.pory"
EventScript_UseRockSmash::
# 86 "data/scripts/field_moves.pory"
	applymovement VAR_LAST_TALKED, Movement_BreakRock
# 87 "data/scripts/field_moves.pory"
	waitmovement 0
# 88 "data/scripts/field_moves.pory"
	removeobject VAR_LAST_TALKED
# 89 "data/scripts/field_moves.pory"
	special RockSmashWildEncounter
# 90 "data/scripts/field_moves.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_RockSmashNoEncounter
# 91 "data/scripts/field_moves.pory"
	waitstate
# 92 "data/scripts/field_moves.pory"
	releaseall
# 93 "data/scripts/field_moves.pory"
	end
# 94 "data/scripts/field_moves.pory"

# 95 "data/scripts/field_moves.pory"
EventScript_RockSmashNoEncounter::
# 96 "data/scripts/field_moves.pory"
	releaseall
# 97 "data/scripts/field_moves.pory"
	end
# 98 "data/scripts/field_moves.pory"

# 99 "data/scripts/field_moves.pory"
Movement_BreakRock::
# 100 "data/scripts/field_moves.pory"
	rock_smash_break
# 101 "data/scripts/field_moves.pory"
	step_end
# 102 "data/scripts/field_moves.pory"

# 103 "data/scripts/field_moves.pory"
EventScript_CantSmashRock::
# 104 "data/scripts/field_moves.pory"
	msgbox Text_MonMaySmashRock, MSGBOX_SIGN
# 105 "data/scripts/field_moves.pory"
	end
# 106 "data/scripts/field_moves.pory"

# 107 "data/scripts/field_moves.pory"
EventScript_DontSmashRock::
# 108 "data/scripts/field_moves.pory"
	closemessage
# 109 "data/scripts/field_moves.pory"
	releaseall
# 110 "data/scripts/field_moves.pory"
	end
# 111 "data/scripts/field_moves.pory"

# 112 "data/scripts/field_moves.pory"
Text_UseRockSmash::
# 113 "data/scripts/field_moves.pory"
	.string "This rock appears to be breakable.\n"
# 114 "data/scripts/field_moves.pory"
	.string "Would you like to use ROCK SMASH?$"
# 115 "data/scripts/field_moves.pory"

# 116 "data/scripts/field_moves.pory"
Text_MonMaySmashRock::
# 117 "data/scripts/field_moves.pory"
	.string "It's a rugged rock, but a POKéMON\n"
# 118 "data/scripts/field_moves.pory"
	.string "may be able to smash it.$"
# 119 "data/scripts/field_moves.pory"

# 120 "data/scripts/field_moves.pory"
EventScript_FldEffStrength::
# 121 "data/scripts/field_moves.pory"
	lockall
# 122 "data/scripts/field_moves.pory"
	dofieldeffect FLDEFF_USE_STRENGTH
# 123 "data/scripts/field_moves.pory"
	waitstate
# 124 "data/scripts/field_moves.pory"
	goto EventScript_UseStrength
# 125 "data/scripts/field_moves.pory"
	end
# 126 "data/scripts/field_moves.pory"

# 127 "data/scripts/field_moves.pory"
EventScript_UseStrength::
# 128 "data/scripts/field_moves.pory"
	setflag FLAG_SYS_USE_STRENGTH
# 129 "data/scripts/field_moves.pory"
	msgbox Text_MonUsedStrengthCanMoveBoulders, MSGBOX_SIGN
# 130 "data/scripts/field_moves.pory"
	end
# 131 "data/scripts/field_moves.pory"

# 132 "data/scripts/field_moves.pory"
EventScript_CantMoveBoulder::
# 133 "data/scripts/field_moves.pory"
	msgbox Text_MonMayPushBoulder, MSGBOX_SIGN
# 134 "data/scripts/field_moves.pory"
	end
# 135 "data/scripts/field_moves.pory"

# 136 "data/scripts/field_moves.pory"
EventScript_AlreadyUsedStrength::
# 137 "data/scripts/field_moves.pory"
	msgbox Text_StrengthMadeMovingBouldersPossible, MSGBOX_SIGN
# 138 "data/scripts/field_moves.pory"
	end
# 139 "data/scripts/field_moves.pory"

# 140 "data/scripts/field_moves.pory"
EventScript_DontUseStrength::
# 141 "data/scripts/field_moves.pory"
	closemessage
# 142 "data/scripts/field_moves.pory"
	releaseall
# 143 "data/scripts/field_moves.pory"
	end
# 144 "data/scripts/field_moves.pory"

# 145 "data/scripts/field_moves.pory"
Text_UseStrength::
# 146 "data/scripts/field_moves.pory"
	.string "It's a big boulder, but a POKéMON\n"
# 147 "data/scripts/field_moves.pory"
	.string "may be able to push it aside.\p"
# 148 "data/scripts/field_moves.pory"
	.string "Would you like to use STRENGTH?$"
# 149 "data/scripts/field_moves.pory"

# 150 "data/scripts/field_moves.pory"
Text_MonUsedStrengthCanMoveBoulders::
# 151 "data/scripts/field_moves.pory"
	.string "{STR_VAR_1} used STRENGTH!\p"
# 152 "data/scripts/field_moves.pory"
	.string "{STR_VAR_1}'s STRENGTH made it\n"
# 153 "data/scripts/field_moves.pory"
	.string "possible to move boulders around!$"
# 154 "data/scripts/field_moves.pory"

# 155 "data/scripts/field_moves.pory"
Text_MonMayPushBoulder::
# 156 "data/scripts/field_moves.pory"
	.string "It's a big boulder, but a POKéMON\n"
# 157 "data/scripts/field_moves.pory"
	.string "may be able to push it aside.$"
# 158 "data/scripts/field_moves.pory"

# 159 "data/scripts/field_moves.pory"
Text_StrengthMadeMovingBouldersPossible::
# 160 "data/scripts/field_moves.pory"
	.string "STRENGTH made it possible to move\n"
# 161 "data/scripts/field_moves.pory"
	.string "boulders around.$"
# 162 "data/scripts/field_moves.pory"

# 163 "data/scripts/field_moves.pory"
EventScript_Waterfall::
# 164 "data/scripts/field_moves.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 165 "data/scripts/field_moves.pory"
	lockall
# 166 "data/scripts/field_moves.pory"
	checkpartymove MOVE_WATERFALL
# 167 "data/scripts/field_moves.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_WaterCrashingDown
# 168 "data/scripts/field_moves.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 169 "data/scripts/field_moves.pory"
	setfieldeffectargument 0, VAR_RESULT
# 170 "data/scripts/field_moves.pory"
	msgbox Text_UseWaterfall, MSGBOX_YESNO
# 171 "data/scripts/field_moves.pory"
	goto_if_eq VAR_RESULT, NO, EventScript_EndWaterfall
# 172 "data/scripts/field_moves.pory"
	msgbox Text_MonUsedWaterfall
# 173 "data/scripts/field_moves.pory"
	dofieldeffect FLDEFF_USE_WATERFALL
# 174 "data/scripts/field_moves.pory"
	goto EventScript_EndWaterfall
# 175 "data/scripts/field_moves.pory"

# 176 "data/scripts/field_moves.pory"
EventScript_CantUseWaterfall::
# 177 "data/scripts/field_moves.pory"
	lockall
# 178 "data/scripts/field_moves.pory"
EventScript_WaterCrashingDown:
# 179 "data/scripts/field_moves.pory"
	msgbox Text_WallOfWaterCrashingDown
# 180 "data/scripts/field_moves.pory"
EventScript_EndWaterfall:
# 181 "data/scripts/field_moves.pory"
	releaseall
# 182 "data/scripts/field_moves.pory"
	end
# 183 "data/scripts/field_moves.pory"

# 184 "data/scripts/field_moves.pory"
Text_WallOfWaterCrashingDown::
# 185 "data/scripts/field_moves.pory"
	.string "A wall of water is crashing down\n"
# 186 "data/scripts/field_moves.pory"
	.string "with a mighty roar.$"
# 187 "data/scripts/field_moves.pory"

# 188 "data/scripts/field_moves.pory"
Text_UseWaterfall::
# 189 "data/scripts/field_moves.pory"
	.string "It's a large waterfall.\n"
# 190 "data/scripts/field_moves.pory"
	.string "Would you like to use WATERFALL?$"
# 191 "data/scripts/field_moves.pory"

# 192 "data/scripts/field_moves.pory"
Text_MonUsedWaterfall::
# 193 "data/scripts/field_moves.pory"
	.string "{STR_VAR_1} used WATERFALL.$"
# 194 "data/scripts/field_moves.pory"

# 195 "data/scripts/field_moves.pory"
@ Unused leftover from R/S
# 196 "data/scripts/field_moves.pory"
EventScript_DeepWater::
# 197 "data/scripts/field_moves.pory"
	lockall
# 198 "data/scripts/field_moves.pory"
	checkpartymove MOVE_DIVE
# 199 "data/scripts/field_moves.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_MayGoUnderwater
# 200 "data/scripts/field_moves.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 201 "data/scripts/field_moves.pory"
	setfieldeffectargument 0, VAR_RESULT
# 202 "data/scripts/field_moves.pory"
	setfieldeffectargument 1, 1
# 203 "data/scripts/field_moves.pory"
	msgbox Text_SeaIsDeepUseDive, MSGBOX_YESNO
# 204 "data/scripts/field_moves.pory"
	goto_if_eq VAR_RESULT, NO, EventScript_EndDive
# 205 "data/scripts/field_moves.pory"
	msgbox Text_MonUsedDive
# 206 "data/scripts/field_moves.pory"
	dofieldeffect FLDEFF_USE_DIVE
# 207 "data/scripts/field_moves.pory"
	goto EventScript_EndDive
# 208 "data/scripts/field_moves.pory"

# 209 "data/scripts/field_moves.pory"
EventScript_CantDive::
# 210 "data/scripts/field_moves.pory"
	lockall
# 211 "data/scripts/field_moves.pory"
EventScript_MayGoUnderwater:
# 212 "data/scripts/field_moves.pory"
	msgbox Text_MonMayGoUnderwater
# 213 "data/scripts/field_moves.pory"
EventScript_EndDive:
# 214 "data/scripts/field_moves.pory"
	releaseall
# 215 "data/scripts/field_moves.pory"
	end
# 216 "data/scripts/field_moves.pory"

# 217 "data/scripts/field_moves.pory"
EventScript_TrySurface::
# 218 "data/scripts/field_moves.pory"
	lockall
# 219 "data/scripts/field_moves.pory"
	checkpartymove MOVE_DIVE
# 220 "data/scripts/field_moves.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSurface
# 221 "data/scripts/field_moves.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 222 "data/scripts/field_moves.pory"
	setfieldeffectargument 0, VAR_RESULT
# 223 "data/scripts/field_moves.pory"
	setfieldeffectargument 1, 1
# 224 "data/scripts/field_moves.pory"
	msgbox Text_LightFilteringUseDive, MSGBOX_YESNO
# 225 "data/scripts/field_moves.pory"
	goto_if_eq VAR_RESULT, NO, EventScript_EndSurface
# 226 "data/scripts/field_moves.pory"
	msgbox Text_MonUsedDive
# 227 "data/scripts/field_moves.pory"
	dofieldeffect FLDEFF_USE_DIVE
# 228 "data/scripts/field_moves.pory"
	goto EventScript_EndSurface
# 229 "data/scripts/field_moves.pory"

# 230 "data/scripts/field_moves.pory"
EventScript_CantSurface::
# 231 "data/scripts/field_moves.pory"
	lockall
# 232 "data/scripts/field_moves.pory"
	msgbox Text_MonMaySurface
# 233 "data/scripts/field_moves.pory"
	goto EventScript_EndSurface
# 234 "data/scripts/field_moves.pory"

# 235 "data/scripts/field_moves.pory"
EventScript_ObstacleCantSurface::
# 236 "data/scripts/field_moves.pory"
	lockall
# 237 "data/scripts/field_moves.pory"
	msgbox Text_DiveCantBeUsedHere
# 238 "data/scripts/field_moves.pory"
EventScript_EndSurface:
# 239 "data/scripts/field_moves.pory"
	releaseall
# 240 "data/scripts/field_moves.pory"
	end
# 241 "data/scripts/field_moves.pory"

# 242 "data/scripts/field_moves.pory"
Text_MonMayGoUnderwater::
# 243 "data/scripts/field_moves.pory"
	.string "The sea is deep here. A POKéMON\n"
# 244 "data/scripts/field_moves.pory"
	.string "may be able to go underwater.$"
# 245 "data/scripts/field_moves.pory"

# 246 "data/scripts/field_moves.pory"
Text_SeaIsDeepUseDive::
# 247 "data/scripts/field_moves.pory"
	.string "The sea is deep here.\n"
# 248 "data/scripts/field_moves.pory"
	.string "Would you like to use DIVE?$"
# 249 "data/scripts/field_moves.pory"

# 250 "data/scripts/field_moves.pory"
Text_MonUsedDive::
# 251 "data/scripts/field_moves.pory"
	.string "{STR_VAR_1} used DIVE.$"
# 252 "data/scripts/field_moves.pory"

# 253 "data/scripts/field_moves.pory"
Text_MonMaySurface::
# 254 "data/scripts/field_moves.pory"
	.string "Light is filtering down from above.\n"
# 255 "data/scripts/field_moves.pory"
	.string "A POKéMON may be able to surface.$"
# 256 "data/scripts/field_moves.pory"

# 257 "data/scripts/field_moves.pory"
Text_LightFilteringUseDive::
# 258 "data/scripts/field_moves.pory"
	.string "Light is filtering down from above.\n"
# 259 "data/scripts/field_moves.pory"
	.string "Would you like to use DIVE?$"
# 260 "data/scripts/field_moves.pory"

# 261 "data/scripts/field_moves.pory"
Text_DiveCantBeUsedHere::
# 262 "data/scripts/field_moves.pory"
	.string "There is an obstacle above.\n"
# 263 "data/scripts/field_moves.pory"
	.string "DIVE can't be used here.$"
# 264 "data/scripts/field_moves.pory"

# 265 "data/scripts/field_moves.pory"
EventScript_FailSweetScent::
# 266 "data/scripts/field_moves.pory"
	msgbox Text_LooksLikeNothingHere, MSGBOX_SIGN
# 267 "data/scripts/field_moves.pory"
	end
# 268 "data/scripts/field_moves.pory"

# 269 "data/scripts/field_moves.pory"
Text_LooksLikeNothingHere::
# 270 "data/scripts/field_moves.pory"
	.string "Looks like there's nothing here…$"

EventScript_StrengthBoulder::
# 274 "data/scripts/field_moves.pory"
	lockall
# 275 "data/scripts/field_moves.pory"
	msgbox Text_CanMoveBoulders, MSGBOX_DEFAULT
# 276 "data/scripts/field_moves.pory"
	closemessage
# 277 "data/scripts/field_moves.pory"
	releaseall
	return


Text_CanMoveBoulders::
# 280 "data/scripts/field_moves.pory"
	.string "Boulders like this one can be\n"
	.string "pushed around by walking into them.$"
