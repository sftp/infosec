#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <gmp.h>
#include <mpfr.h>

unsigned long int mpfr_modulus(mpfr_t a, mpfr_t n)
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

int is_prime(unsigned long int n)
{
	unsigned long int i, l, res;
	mpfr_t tmp, num, power;

	mpfr_init2(tmp, 512);
	mpfr_set_ui(tmp, 0, GMP_RNDD);

 	mpfr_init2(num, 512);
	mpfr_set_ui(num, n, GMP_RNDD);

	mpfr_init2(power, 256);

	l = (n < 10) ? n : 10;

	/*
	 * power = (n-1)/2
	 */
	mpfr_add_si(power, num, -1, GMP_RNDN);
	mpfr_div_ui (power, power, 2, GMP_RNDN);
	
	for(i = 2; i < l; i++) {
		mpfr_ui_pow(tmp, i, power, GMP_RNDN);

		res = mpfr_modulus(tmp, num);

		if (!((res == 1) || (res == n - 1))) {
			return 0;
		}
	}

	return l - 2; /* for probability estimate */
}

int main(int argc, char *argv[])
{
	unsigned long int num;
	int result;

	num = atoi(argv[1]);

	if(num % 2 == 0) {
		goto nonprime;
	} else {
		result = is_prime(num);
		if(result) {
			printf("Number %lu maybe prime "
			       "(probability >= 1/2^%d = %f)\n",
			       num, result, 1 - 1 / (pow(2, result)));
			goto exit;
		}
	}

nonprime:
	printf("%lu isn't prime\n", num);

exit:
	return result;
}
