#include <stdio.h>

int main() {
	int t;
	scanf_s("%d", &t);
	int y = 0;
	int k = 0;
	for (int i = 0; i < 9; i++) {
		int a, b;
		scanf_s("%d %d", &a, &b);
		y += a;
		k += b;
	}

	for (int i = 0; i < t; i++) {
		if (y > k)
			printf("Yonsei\n");
		else if (y < k)
			printf("Korea\n");
		else
			printf("Draw\n");
	}
	return 0;
}