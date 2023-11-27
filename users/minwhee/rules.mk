SRC += minwhee.c

KEY_OVERRIDE_ENABLE = yes
TAP_DANCE_ENABLE = yes
CAPS_WORD_ENABLE = yes


ifeq ($(strip $(MINWHEE_HHKB)), yes)
	SRC += hhkb/hhkb.c
	OPT_DEFS += -DHHKB_ENABLE
endif