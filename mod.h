#include "gcd.h"

int mod(long int a, int n)
{
	int ret;

	ret = a % n;
	if(ret < 0)
		ret +=n;

	return ret;
}

int mod_reverse(int a, int n)
{
	int d, x, y, ret;

	d = gcd_ext(a, n, &x, &y);

	if (d == 1) {
		if (x < 0) {
			x += n;
		}
		ret = x;
	} else {
		ret = 0;
	}

	return ret;
}
