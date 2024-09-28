#include <stdio.h>
int main() {
	int n;
	int ans = 1;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		ans *= 2;
	}
	printf("%d", ans);
	return 0;
}