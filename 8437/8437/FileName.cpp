#include <stdio.h>

int main() {
	int a, b;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	printf("%d\n%d", (a - b) / 2 + b, (a - b) / 2);
	return 0;
}