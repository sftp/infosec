#include <stdio.h>
#include <stdlib.h>

#include "factor.h"

int main (int argc, char *argv[])
{
	int number = atoi(argv[1]);
	int i;

	int *deviders = calloc(100, sizeof(int));

	printf("%d: ", number);
	factor(number, deviders);
	for (i = 0; deviders[i] != 0; i++)
		printf("%d ", deviders[i]);
	putchar('\n');

	return 0;
}
