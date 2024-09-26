#include <stdio.h>

int main() {
	int n;
	// 모듈러 연산으로 풀어야 하는 문제.
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
