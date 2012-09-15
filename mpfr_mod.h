#include <gmp.h>
#include <mpfr.h>

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
