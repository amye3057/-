#include <stdio.h>

int main() {
	int n;
	int a;
	int arr[2] = {};
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a);
		arr[a]++;
	}
	if (arr[0] > arr[1]) {
		printf("Junhee is not cute!");
	}
	else
		printf("Junhee is cute!");
	return 0;
}