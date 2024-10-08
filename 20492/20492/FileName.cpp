#include <stdio.h>

int main() {
	int n;
	scanf_s("%d", &n);
	int a = (n * (100 - 22)) / 100;
	int b = (n * 80) / 100 + (n * (100 - 80) / 100) * (100-22) / 100;
	printf("%d %d", a, b);
	return 0;
}