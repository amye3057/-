#include <stdio.h>

int main() {
	int a;
	int sum = 0;
	scanf_s("%d", &a);
	if (a % 5 == 0) {
		sum += a / 5;
	}
	else if ((a / 5) != 0 && (a / 5) % 3 == 0) {
		sum += a / 5;
		a = a % 5;
		sum += a / 3;
	}
	else if ((a / 3) != 0 && (a / 3) % 5 == 0) {
		sum += a / 3;
		a = a % 3;
		sum += a / 5;
	}
	else if (a % 3 == 0) {
		sum += a / 3;
	}
	else
		sum = -1;

	printf("%d", sum);

	return 0;
}