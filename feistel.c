#include <stdio.h>
#include <inttypes.h>

#include <stdlib.h>

#define ROUNDS 2

/* subkeys */
#define K1 0xaa /* 1010 1010 */
#define K2 0xf0 /* 1111 0000 */

/* subblocks */
#define DATA1 0xbcaf /*1011 1100 1010 1111 */
#define DATA2 0xe6b9

typedef uint8_t  u8;
typedef uint16_t u16;

/* for rounds 1 .. (n-1) */


void rounds(u8 *l, u8 *r, u8 k)
{
	u8 tmp;
	tmp = *r;
	*r = *l ^ *r ^ k;
	*l = tmp;
}

/* for round n (final round) */
void final(u8 *l, u8 *r, u8 k)
{
        u8 tmp;

	tmp = *r;

	*l = *l ^ *r ^ k;
	*r = tmp;
}

void feistel(u16 *data, u8 count, u8 k[])
{
	u8 l = (u8) (*data >> 8);
	u8 r = (u8) *data;

	u8 i;

	printf("---\n");
	printf("l   = 0x%02x\n", l);
	printf("r   = 0x%02x\n", r);

	for (i = 0; i < count-1; i++)
	{
		printf("key = 0x%02x\n", k[i]);

		rounds(&l, &r, k[i]);

		printf("l   = 0x%02x\n", l);
		printf("r   = 0x%02x\n", r);
		printf("---\n");
	}

	printf("key = 0x%02x\n", k[i]);

	final(&l, &r, k[i]);

	printf("l   = 0x%02x\n", l);
	printf("r   = 0x%02x\n", r);

	u16 cipher = (l << 8) | r;

	printf("c   = 0x%04x (%d)\n", cipher, cipher);
}

int main(int argc, char *argv[])
{
	if (argc != 3 || (*argv[1] != 'd' && *argv[1] != 'e') ) {
		printf("usege: %s [ed]\n", argv[0]);
		
		return -1;
	}

	u16 data = (u16) atol(argv[2]);

	if (*argv[1] == 'e') {
		u8 keys[2] = {K1, K2};
		
		printf("data = 0x%02x  (%d)\n", data, data);
		printf("k1   = 0x%02x\n", keys[0]);
		printf("k2   = 0x%02x\n", keys[1]);
		
		feistel(&data, ROUNDS, keys);
	} else {
		u8 keys[2] = {K2, K1};
			
		printf("data = 0x%02x (%d)\n", data, data);
		printf("k1   = 0x%02x\n", keys[0]);
		printf("k2   = 0x%02x\n", keys[1]);
		
		feistel(&data, ROUNDS, keys);
	}
	
	return 0;
}
