#include <stdio.h>

int main() {
	int a, b, c;
	scanf_s("%d %d %d", &a, &b, &c);
	int d = a * b - c;
	if (d < 0)
		d = 0;
	printf("%d", d);
	return 0;
}