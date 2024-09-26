#include <stdio.h>
#include <stdlib.h>

int main() {
	unsigned int x = 0x00FF;
	if ((*(unsigned char*)&x == 0xFF))
		printf("little endian");
	else
		printf("big endian");

	return 0;
}