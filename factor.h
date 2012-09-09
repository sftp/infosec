#include <stdio.h>
#include <stdlib.h>

void factor (int number, int dels[])
{
	int i, iter = 0;

	for (i = 2; i <= number;) {
		if (number % i == 0) {
			dels[iter++] = i;
			number /= i;
		} else {
			i++;
		}
	}

	dels[iter] = 0;
}
