#include <stdio.h>

int main() {
	int n;
	int max = 0;
	//int arr[500001] = {};
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf_s("%d", &x);
		if (x > max)
			max = x;
	}
	printf("%d", max);
	return 0;
}