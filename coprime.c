#include <stdio.h>
#include <stdlib.h>

#include "factor.h"

int main (int argc, char *argv[])
{
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	int *a_del = calloc(100, sizeof(int));
	int *b_del = calloc(100, sizeof(int));

	int i, j;
	int a_i, b_i;

	int ret = 0;

	printf("%d: ", a);
	a_i = factor(a, a_del);

	printf("%d: ", b);
	b_i = factor(b, b_del);

	for (i = 0; i < a_i; i++) {
		for (j = 0; j < b_i; j++) {
			if (a_del[i] == b_del[j]) {
				printf("%d and %d is NOT coprime numbers\n", a, b);
				ret = 1;
				goto exit;
			}
		}
	}

	printf("%d and %d is coprime numbers\n", a, b);

exit:
	free(a_del);
	free(b_del);

	return ret;
}
