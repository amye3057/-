#include <stdio.h>
int main() {
	int arr[10000] = {}; // �Է��� �ִ� 10000�� ���ٰ� �����ߴ�.
	int n = 0;
	while (1) {
		scanf_s("%d", &arr[n]);
		if (arr[n] == 0)
			break;
		n++;
	}
	n++; // �Էµ� ���� ����

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