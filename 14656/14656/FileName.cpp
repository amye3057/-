#include <stdio.h>

int main() {
	int a;
	int sum = 0;
	scanf_s("%d", &a);
	for (int i = 1; i < a + 1; i++) {
		int b;
		scanf_s("%d", &b);
		if (b != i)
			sum++;
	}
	printf("%d", sum);
	return 0;
}