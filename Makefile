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

PROGS = factor coprime mod mod_reverse prime gcd gcd_stein primitive_root \
	gen_prime feistel mds

default: all
all:	$(PROGS)

factor: factor.c factor.h
	$(E) "  CC      " $@
	$(Q) ${CC} $(CFLAGS) factor.c -o factor

coprime: coprime.c factor.h
	$(E) "  CC      " $@
	$(Q) ${CC} $(CFLAGS) coprime.c -o coprime

mod: mod.c mod.h
	$(E) "  CC      " $@
	$(Q) ${CC} $(CFLAGS) mod.c -o mod

mod_reverse: mod_reverse.c mod.h
	$(E) "  CC      " $@
	$(Q) ${CC} $(CFLAGS) mod_reverse.c -o mod_reverse

prime: prime.c mpfr_prime.h
	$(E) "  CC      " $@
	$(Q) ${CC} $(CFLAGS) prime.c -o prime -lm -lgmp -lmpfr

gcd: gcd.c gcd.h
	$(E) "  CC      " $@
	$(Q) ${CC} $(CFLAGS) gcd.c -o gcd

gcd_stein: gcd_stein.c gcd.h
	$(E) "  CC      " $@
	$(Q) ${CC} $(CFLAGS) gcd_stein.c -o gcd_stein

primitive_root:	primitive_root.c
	$(E) "  CC      " $@
	$(Q) ${CC} $(CFLAGS) primitive_root.c -o primitive_root -lgmp -lmpfr

gen_prime: gen_prime.c
	$(E) "  CC      " $@
	$(Q) ${CC} $(CFLAGS) gen_prime.c -o gen_prime -lgmp -lmpfr -lrt -lm

feistel: feistel.c
	$(E) "  CC      " $@
	$(Q) ${CC} $(CFLAGS) feistel.c -o feistel

mds: mds.c
	$(E) "  CC      " $@
	$(Q) ${CC} $(CFLAGS) mds.c -o mds

clean:
	$(E) "  CLEAN   " $(PROGS)
	$(Q) rm -f $(PROGS)
