#include <stdio.h>

int main() {
	int t;
	int arr[1000] = {}; // ����  Test Case �ִ� ������ 1000���ΰɷ� ����.
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