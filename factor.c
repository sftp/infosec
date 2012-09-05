#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	int number = atoi(argv[1]);
	int i;

	printf("%d: ", number);

	for (i = 2; i <= number;) {
		if (number % i == 0) {
			printf("%d ", i);
			number /= i;
		} else {
			i++;
		}
	}

	putchar('\n');
	
	return 0;
}
