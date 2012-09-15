#include <gmp.h>
#include <mpfr.h>

#include "mpfr_mod.h"

int is_prime(unsigned long int n)
{
	unsigned long int i, l, res, power;
	mpfr_t tmp, num;

	mpfr_init2(tmp, 512);
	mpfr_set_ui(tmp, 0, GMP_RNDD);

	mpfr_init2(num, 512);
	mpfr_set_ui(num, n, GMP_RNDD);

	l = (n < 10) ? n : 10;

	power = (n - 1) / 2;

	for(i = 2; i < l; i++) {
		mpfr_ui_pow_ui(tmp, i, power, GMP_RNDN);

		res = mpfr_mod(tmp, num);

		if (!((res == 1) || (res == n - 1))) {
			return 0;
		}
	}

	return l - 2; /* for probability estimate */
}
