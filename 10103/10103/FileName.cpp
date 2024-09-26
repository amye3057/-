#include <stdio.h>

int main() {
	int a, b;
	int CY = 100, SD = 100; // changyoung, sangduck
	int n;

	scanf_s("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf_s("%d %d", &a, &b);
		if (a > b)
			SD -= a;
		else if (a < b)
			CY -= b;
	}

	printf("%d\n%d", CY, SD);
	return 0;
}