#include <stdio.h>
#include <stdlib.h>

#include "mod.h"

int main(int argc, char *argv[])
{
	int a = atoi(argv[1]);
	int n = atoi(argv[2]);

	printf("%d\n", mod(a, n));

	return 0;
}
