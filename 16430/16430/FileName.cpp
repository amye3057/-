#include <stdio.h>
int main() {
	int a, b;
	scanf_s("%d %d", &a, &b);
	printf("%d %d", b - a, b);
	return 0;
}