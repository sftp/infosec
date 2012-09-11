#include <stdio.h>
#include <stdlib.h>

#include "factor.h"

int main (int argc, char *argv[])
{
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	int *a_del = malloc(100 * sizeof(int));
	int *b_del = malloc(100 * sizeof(int));

	int i, j;

	int ret = 0;

	printf("%d: ", a);
	factor(a, a_del);
	for (i = 0; a_del[i] != 0; i++)
		printf("%d ", a_del[i]);
	putchar('\n');

	printf("%d: ", b);
	factor(b, b_del);
	for (i = 0; b_del[i] != 0; i++)
		printf("%d ", b_del[i]);
	putchar('\n');

	for (i = 0; a_del[i] != 0; i++) {
		for (j = 0; b_del[j] != 0; j++) {
			if (a_del[i] == b_del[j]) {
				printf("%d and %d is NOT coprime numbers\n",
				       a, b);
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
