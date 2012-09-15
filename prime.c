#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include "mpfr_prime.h"

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
