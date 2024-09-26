#include <stdio.h>

int main() {
	long long int a, b;
	scanf_s("%lld %lld", &a, &b);
	printf("%lld\n%lld", a / b, a % b);
	return 0;
}