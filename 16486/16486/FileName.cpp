#include <stdio.h>
#define pi 3.141592

int main() {
	int d, r;
	scanf_s("%d", &d);
	scanf_s("%d", &r);
	printf("%lf", 2 * d + 2 * pi * r);
	return 0;
}