#include <stdio.h>

int main() {
	int a, b, c, d, e;
	int ans = 0;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	scanf_s("%d", &d);
	scanf_s("%d", &e);


	if (a > 0) {
		ans = (b - a) * e;
	}
	else if (a < 0) {
		ans = a * (-1) * c + b * e + d;
	}
	else {
		ans = d + b * e;
	}

	printf("%d", ans);
	return 0;

}