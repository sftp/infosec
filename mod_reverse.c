#include <stdio.h>
#include <stdlib.h>

int main (int argc,char *argv[])
{
	int a = atoi(argv[1]);
	int n = atoi(argv[2]);

	int i;

	for(i = 1; !(((a * i) % n) == 1); i++);
	printf("%d\n", i);

	return 0;
}
