#include <stdio.h>
#include <stdint.h>

int main_a() {
	uint64_t x, y;
	//scanf ±ÍÂúÀº²² ÀÏ´Ü ³Ö´Â´Ù
	x = 523456789012345;
	y = 543210987654321;

	printf("x : %llx\ny : %llx\n", x, y);
	printf("x<<8 : %llx\n", x << 8);
	printf("x>>8 : %llx\n", x >> 8);
	printf("x&y : %llx\n", x & y);
	printf("x|y : %llx\n", x | y);
	printf("x&!y : %llx\n", x &! y);
	printf("x&&y : %d\n", x && y);
	printf("x||y : %d\n", x || y);
	printf("x&&~y : %d\n\n", x && ~y);

	char* p = (char*)&x;
	for (int i = 0; i < sizeof(x); i++) {
		printf("%02x ", p[i]&0x000000FF);
	}
	printf("\nx >> 8 :\n");
	uint64_t x1 = x >> 8;
	p = (char*)&x1;
	for (int i = 0; i < sizeof(x); i++) {
		printf("%02x ", p[i] & 0x000000FF);
	}
	printf("\nx << 8 :\n");
	uint64_t x2 = x << 8;
	p = (char*)&x2;
	for (int i = 0; i < sizeof(x); i++) {
		printf("%02x ", p[i] & 0x000000FF);
	}
	//printf("");
	return 0;
}