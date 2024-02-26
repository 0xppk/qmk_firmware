SRC += minwhee.c

ifeq ($(strip $(MINWHEE_HHKB)), yes)
	SRC += hhkb/hhkb.c
endif

ifeq ($(strip $(MINWHEE_MINIMI)), yes)
	SRC += minimi/minimi.c
endif

KEY_OVERRIDE_ENABLE = yes
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
CAPS_WORD_ENABLE = yes
MOUSEKEY_ENABLE = no


