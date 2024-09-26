#include <stdio.h>

int main() {
	int n;
	scanf_s("%d", &n);

	int x = n / 5;
	int m;

	if (n < 5) {
		if (n % 3 == 0)
			printf("%d", n / 3);
		else
			printf("-1");
		return 0;
	}

	while (x!=0) {
		m = n - 5 * x;
		m = m % 3;
		if (m == 0)
			break;
		x--;
	}

	if (m == 0) { // 조건에 맞아서 루프를 빠져나온 경우
		x = x + (n - 5 * x) / 3;
		printf("%d", x);
	}
	else {
		if (n % 3 == 0) { // 3으로만 나눠질 경우
			printf("%d", n / 3);
		}
		else // 불가능
			printf("-1");
	}

}