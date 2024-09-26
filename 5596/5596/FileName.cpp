#include <stdio.h>

int main() {
	int a, b, c, d;
	int min, man;
	scanf_s("%d %d %d %d", &a, &b, &c, &d);
	min = a + b + c + d;
	scanf_s("%d %d %d %d", &a, &b, &c, &d);
	man = a + b + c + d;
	if (min >= man)
		printf("%d", min);
	else
		printf("%d", man);
	return 0;
}