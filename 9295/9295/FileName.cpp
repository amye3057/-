#include <stdio.h>

int main() {
	int t;
	int arr[1000] = {}; // 대충  Test Case 최대 개수가 1000개인걸로 가정.
	scanf_s("%d", &t);
	for (int i = 0; i < t; i++) {
		int a, b;
		scanf_s("%d %d", &a, &b);
		arr[i] = a + b;
	}
	for (int i = 0; i < t; i++) {
		printf("Case %d: %d\n", i + 1, arr[i]);
	}
	return 0;
}