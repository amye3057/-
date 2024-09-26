#include <stdio.h>

int main() {

	int a[31] = {};
	int b;

	for (int i = 0; i < 28; i++) {
		scanf_s("%d", &b);
		a[b]++;
	}

	for (int i = 1; i < 31; i++) {
		if (a[i] == 0)
			printf("%d\n", i);
	}
	return 0;
}

