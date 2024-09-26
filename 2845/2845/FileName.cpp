#include <stdio.h>

int main() {
	int x, y;
	int t;
	scanf_s("%d %d", &x, &y);
	t = x * y;

	int a, b, c, d, e;
	scanf_s("%d %d %d %d %d", &a, &b, &c, &d, &e);
	printf("%d %d %d %d %d", a - t, b - t, c - t, d - t, e - t);
	return 0;
}