#include <stdio.h>
#include <stdlib.h>

int factor (int number, int dels[])
{
	int i, iter = 0;

	for (i = 2; i <= number;) {
		if (number % i == 0) {
			printf("%d ", i);
			dels[iter++] = i;
			number /= i;
		} else {
			i++;
		}
	}

	putchar('\n');
	return iter;
}
