#include <stdio.h>

int main() {
	int a;
	int x;
	scanf_s("%d", &a);

	if (a < 1) {
		printf("0");
		return 0;
	}

	while (a > 1) {
		if (a % 2 != 0) {
			x = 0;
			break;
		}
		a /= 2;
	}

	if (a == 1)
		x = 1;

	printf("%d", x);
	return 0;
}