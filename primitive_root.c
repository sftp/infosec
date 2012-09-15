#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <gmp.h>
#include <mpfr.h>

#include "factor.h"

unsigned long int mpfr_mod(mpfr_t a, mpfr_t n)
{
	mpfr_t res;
	mpfr_init2(res, 512);
	mpfr_set_ui(res, 0, GMP_RNDD);

	long int ret;
	unsigned long num;

	mpfr_remainder(a, a, n, GMP_RNDN);
	ret = mpfr_get_si(a, GMP_RNDN);
	num = mpfr_get_ui(n, GMP_RNDN);

	if(ret < 0)
		ret += num;

	return (unsigned long int) ret;
}

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);

	mpfr_t num, res;

	mpfr_init2(num, 512);
	mpfr_set_si(num, n, GMP_RNDN);

	mpfr_init2(res, 512);
	mpfr_set_ui(res, 0, GMP_RNDD);

	int i, j, ret;
	int *deviders = calloc(100, sizeof(int));

	factor(n - 1, deviders);

	/*
	 * i^((n-1)/2) mod n
	 */
	for(i = 1; i < n; i++) {
		ret = 0;

		for(j = 0; deviders[j] && ret != 1; j++) {
			mpfr_ui_pow_ui(res, i, (n - 1) / deviders[j], GMP_RNDN);
			ret = mpfr_mod(res, num);

			if(ret == 1)
				break;
		}

		if(ret != 1)
			printf("%d ", i);
	}
	
	putchar('\n');

	return 0;
}
