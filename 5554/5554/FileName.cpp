#include <stdio.h>

int main() {
	int a, b, c, d;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	scanf_s("%d", &d);

	int sum = a + b + c + d;
	int minute = sum / 60;
	int second = sum % 60;
	printf("%d\n%d", minute, second);
	return 0;
}