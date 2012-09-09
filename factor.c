#include <stdio.h>
#include <stdlib.h>

#include "factor.h"

int main (int argc, char **argv)
{
	int number = atoi(argv[1]);
	int i;

	int *deviders = calloc(100, sizeof(int));

	printf("%d: ", number);
	i = factor(number, deviders);
	
	return 0;
}
