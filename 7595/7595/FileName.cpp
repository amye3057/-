#include <stdio.h>
int main() {
	int arr[10000] = {}; // 입력이 최대 10000개 들어간다고 가정했다.
	int n = 0;
	while (1) {
		scanf_s("%d", &arr[n]);
		if (arr[n] == 0)
			break;
		n++;
	}
	n++; // 입력된 수의 개수

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < arr[i]; j++) {
			for (int k = 0; k < j + 1; k++) {
				printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}