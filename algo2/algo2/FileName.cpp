#include <stdio.h>

int main() {
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int a2[3][4] = { {1,2,3,4}, {5,6,7,8},{9,10,11,12} };
	printf("(a+2)[3] = %d\n", (a + 2)[3]);
	printf("(a2+1)[1][2] = %d\n", (a2 + 1)[1][2]);
	return 0;
}