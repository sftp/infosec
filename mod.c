#include <stdio.h>
#include <stdlib.h>

int mod(long int a, int n)
{
	int ret;
	ret = a % n;
	if(ret < 0)
		ret +=n;

	return ret;
}

int main(int argc, char *argv[])
{
	int a = atoi(argv[1]);
	int n = atoi(argv[2]);

	printf("%d\n", mod(a, n));

	return 0;
}
