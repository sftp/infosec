#include <stdio.h>
#include <stdlib.h>

#include "gcd.h"

int main (int argc,char *argv[])
{
	int a = atoi(argv[1]);
	int n = atoi(argv[2]);

	int d, x, y;

	d = gcd_ext(a, n, &x, &y);

	if (d == 1) {
		if (x < 0) {
			x += n;
		}
		printf("%d\n", x);
	} else {
		printf("%d\n", 0);
	}

	return 0;
}
