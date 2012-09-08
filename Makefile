V =
ifeq ($(strip $(V)),)
	E = @echo
	Q = @
else
	E = @\#
	Q =
endif
export E Q

WARNINGS = -Wall -Wstrict-prototypes
CC = gcc
CFLAGS = -O2 $(WARNINGS)

PROGS = factor coprime mod mod_reverse prime

default: all
all:	$(PROGS)

factor:	factor.c
	$(E) "  CC      " $@
	$(Q) ${CC} $(CFLAGS) factor.c -o factor

coprime:	coprime.c
	$(E) "  CC      " $@
	$(Q) ${CC} $(CFLAGS) coprime.c -o coprime

mod:	mod.c
	$(E) "  CC      " $@
	$(Q) ${CC} $(CFLAGS) mod.c -o mod

mod_reverse:	mod_reverse.c
	$(E) "  CC      " $@
	$(Q) ${CC} $(CFLAGS) mod_reverse.c -o mod_reverse

prime:	prime.c
	$(E) "  CC      " $@
	$(Q) ${CC} $(CFLAGS) prime.c -o prime -lm -lgmp -lmpfr

clean:
	$(E) "  CLEAN   " $(PROGS)
	$(Q) rm -f $(PROGS)
