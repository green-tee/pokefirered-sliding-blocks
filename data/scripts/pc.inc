EventScript_PC::
# 2 "data/scripts/pc.pory"
	lockall
# 6 "data/scripts/pc.pory"
	special AnimatePcTurnOn
# 7 "data/scripts/pc.pory"
	playse SE_PC_ON
# 8 "data/scripts/pc.pory"
	msgbox Text_BootedUpPC, MSGBOX_DEFAULT
# 9 "data/scripts/pc.pory"
	msgbox Text_OpenedPkmnStorage, MSGBOX_DEFAULT
# 10 "data/scripts/pc.pory"
	special ShowPokemonStorageSystemPC
# 11 "data/scripts/pc.pory"
	waitstate
# 15 "data/scripts/pc.pory"
	playse SE_PC_OFF
# 16 "data/scripts/pc.pory"
	special AnimatePcTurnOff
# 18 "data/scripts/pc.pory"
	releaseall
	return

