#include <stdio.h>
int change_min_index_to_minus1(int arr[], int sum); // �ּҰ��� -1�� �ٲ㼭 ��¿��� ���ܽ�Ű��.

int main() {
	int arr[8] = {};
	int min = 999;
	int sum = 0;
	int M;
	// ���� �� 3���� ���� ��, �³׸� �� 0���� ���� ���� 0�� �ƴ� �ε����� ������� ����ϰ� �ϴ� �� ȿ������ ��.
	for (int i = 0; i < 8; i++) {
		scanf_s("%d", &arr[i]);
		sum += arr[i];
		if (arr[i] < min) {
			min = arr[i];
			M = i;
		}
	}
	// sum���� ��� ������ �� ������ �ְ� �ּҰ����� 3�� ã�Ƽ� ���� ���̴�.
	sum -= min;
	arr[M] = '-1';

	sum = change_min_index_to_minus1(arr, sum);
	sum = change_min_index_to_minus1(arr, sum);

	printf("%d\n", sum);
	for (int i = 0; i < 8; i++) {
		if (arr[i] != '-1')
			printf("%d ", i + 1);
	}
	return 0;
}

int change_min_index_to_minus1(int arr[], int sum) {
	int min = 999;
	int M;
	for (int i = 0; i < 8; i++) {
		if (arr[i] < min && arr[i] != '-1') {
			min = arr[i];
			M = i;
		}
	}
	sum -= min;
	//printf("min = %d, sum=%d\n", min, sum); //Ȯ��
	arr[M] = '-1';
	return sum;
}