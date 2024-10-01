#include <stdio.h>

int main() {
	int a, b, c;
	int sum;
	scanf_s("%d", &a);
	scanf_s("%d %d", &b, &c);

	sum = b / 2 + c;
	if (sum > a)
		sum = a;

	printf("%d", sum);
	return 0;
}