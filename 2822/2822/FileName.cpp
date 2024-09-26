#include <stdio.h>
int change_min_index_to_minus1(int arr[], int sum); // 최소값을 -1로 바꿔서 출력에서 제외시키기.

int main() {
	int arr[8] = {};
	int min = 999;
	int sum = 0;
	int M;
	// 작은 거 3개를 구한 뒤, 걔네를 다 0으로 만든 다음 0이 아닌 인덱스만 순서대로 출력하게 하는 게 효율적일 듯.
	for (int i = 0; i < 8; i++) {
		scanf_s("%d", &arr[i]);
		sum += arr[i];
		if (arr[i] < min) {
			min = arr[i];
			M = i;
		}
	}
	// sum에는 모든 점수가 다 더해져 있고 최소값들을 3개 찾아서 빼줄 것이다.
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
	//printf("min = %d, sum=%d\n", min, sum); //확인
	arr[M] = '-1';
	return sum;
}