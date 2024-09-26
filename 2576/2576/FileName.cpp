#include <stdio.h>

int main() {
	int minimum = 100;
	int sum = 0;
	for (int i = 0; i < 7; i++) {
		int a;
		scanf_s("%d", &a);
		if (a % 2 != 0) {
			sum += a;
			if (a < minimum)
				minimum = a;
		}
	}
	if (sum == 0)
		printf("-1");
	else
		printf("%d\n%d", sum, minimum);
}