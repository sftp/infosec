#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <time.h>

#include "mpfr_prime.h"

int main (int argc, char *argv[])
{
	struct timespec time;
	unsigned char rnd;
	int res = 0;

	clock_gettime(CLOCK_MONOTONIC, &time);
	srand(time.tv_nsec);

	do {
		rnd = (unsigned char) rand();
		printf("Random number is: %d\n", rnd);
	      
		rnd |= 0x81;
		printf("Set high and low bits to 1: %d\n", rnd);

		res = is_prime(rnd);

		printf("Check %d with Lehmann test... ", rnd);
		if(res) {
			printf("Passed.\n"
			       "Number maybe prime "
			       "(probability >= 1/2^%d = %f)\n",
			       res, 1 - 1 / (pow(2, res)));
		} else {
			printf("Failed\n\n");
		}
	} while (!res);

	return 0;
}
