#include <stdio.h>

int main() {
	int n;
	// ��ⷯ �������� Ǯ��� �ϴ� ����.
	while (scanf_s("%d", &n) != EOF) {
		int M = 1;
		int k = 1;
		while (M % n != 0) {
			M = (10 * M + 1) % n;
			k++;
		}
		printf("%d\n", k);
	}

	return 0;
}
