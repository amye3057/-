#include <stdio.h>
#define yes 1
#define no 0
int istherezero = no; // 0이 입력될 경우 사용되는 변수

int binary_search(int arr[], int x);
int search(int arr[], int x, int n);
void bubble_sort(int arr[], int n);

int main() {
	int n, m;
	int arr[1000000] = {};
	int brr[100000] = {};

	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		int index;
		scanf_s("%d", &x);
		// 버블정렬이 시간초과되어서 이진트리를 만들어서 입력때부터 정렬을 해줄 것이다.
		if (0 < x) { // NULL이랑 0이랑 구분을 할 수 없어서 일단 맨 처음엔 이렇게 따로 먼저 분리.
			index = 2;
		}
		else if (0 > x)
			index = 1;
		else if (x == 0)
			istherezero = yes; // 0이 입력될 경우

		while (arr[index] != NULL) {
			if (arr[index] < x)
				index = index * 2 + 2;
			else
				index = index * 2 + 1;
		}
		arr[index] = x;
	}

	// 이진 검색을 하기 위해 오름차순으로 정렬을 해줄 것이다. (버블정렬로 구현했는데, 출력은 잘 나오지만 백준에서 시간초과라고 떠서 더 나은 시간복잡도 알고리즘을 사용해야한다.)
	//bubble_sort(arr, n);

	scanf_s("%d", &m);
	int a;
	for (int i = 0; i < m; i++) {
		scanf_s("%d", &a);
		//brr[i] = search(arr, a, n);
		brr[i] = binary_search(arr, a);
	}

	for (int i = 0; i < m; i++) {
		printf("%d ", brr[i]);
	}
	
	return 0;
}

void bubble_sort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int x = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = x;
			}
		}
	}
}

int search(int arr[], int x, int n) {
	int start = 0;
	int end = n;
	while (start != end) {
		n = (start + end) / 2;
		if (x > arr[n])
			start = n + 1;
		else if (x < arr[n])
			end = n - 1;
		else if (x = arr[n])
			return 1;
	}
	if (x == arr[end])
		return 1;
	else
		return 0;
}

int binary_search(int arr[], int x) {
	int index;
	if (0 < x)
		index = 2;
	else if (0 > x)
		index = 1;
	else if (x == 0)
		return istherezero; // 0이 입력될 경우

	while (arr[index] != NULL && arr[index]!=x) {
		if (arr[index] < x)
			index = index * 2 + 2;
		else
			index = index * 2 + 1;
	}
	
	if (arr[index] == x)
		return 1;
	else
		return 0;
}