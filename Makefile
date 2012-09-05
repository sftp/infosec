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

PROGS = factor coprime

default: all
all:	$(PROGS)

factor:	factor.c
	$(E) "  CC      " $@
	$(Q) ${CC} $(CFLAGS) factor.c -o factor

coprime:	coprime.c
	$(E) "  CC      " $@
	$(Q) ${CC} $(CFLAGS) coprime.c -o coprime

clean:
	$(E) "  CLEAN   " $(PROGS)
	$(Q) rm -f $(PROGS)
