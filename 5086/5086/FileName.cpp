#include <stdio.h>

int main() {
	int a, b;
	while (1) {
		scanf_s("%d %d", &a, &b);
		if (a == 0 && b == 0)
			break;
		else if (a < b && b % a == 0) {
			printf("factor");
		}
		else if (a > b && a % b == 0) {
			printf("multiple");
		}
		else
			printf("neither");
		printf("\n");
	}
	return 0;
}