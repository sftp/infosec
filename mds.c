#include <stdio.h>
#include <inttypes.h>

typedef uint8_t  u8;

#define POLY 0x1b

u8 gmul(u8 a, u8 b)
{
	u8 res = 0;
	u8 pos;
	u8 of;

	for(pos = 0; pos < 8; pos++) {
		if(b & 1)
			res ^= a;

		of = a & 0x80;
		a <<= 1;

		if (of)
			a ^= POLY;

		b >>= 1;
	}

	return res;
}

int main(int argc, char *argv[])
{
	u8 i, j;

	u8 MDS[4][4] = {{2, 3, 1, 1},
			{1, 2, 3, 1},
			{1, 1, 2, 3},
			{3, 1, 1, 2}};

	u8 input[4] = {0xd4, 0xbf, 0x5d, 0x30};

	printf("poly:\t0x%02x\n\n", POLY);

	printf("MDS:\n");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			printf("\t0x%02x", MDS[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');

	printf("input:\n");
	for (i = 0; i < 4; i++)
		printf("\t0x%02x\n", input[i]);

	putchar('\n');

	u8 res[4] = {0, 0, 0, 0};

	printf("result:\n");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			res[i] ^= gmul(input[j], MDS[i][j]);
		}
		printf("\t0x%02x\n", res[i]);
	}

	return 0;
}
