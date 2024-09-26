#include <stdio.h>
void put_tree(int a, int b, int arr[][2]);
void print_tree(int arr[][2], int n);

int istherezerozero = 0; // (0,0)좌표가 있을 경우

int main() {
	int n;
	int arr[1000000][2] = {};
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf_s("%d %d", &a, &b);
		put_tree(a, b, arr);
	}

	print_tree(arr, n);

	return 0;
}

void put_tree(int a, int b, int arr[][2]) {
	if (a == 0 && b == 0) {
		istherezerozero = 1;
	}
	else {
		int i = 0;
		while (arr[i][0] != 0 && arr[i][1] != 0) {
			if (a > arr[i][0]) {
				i = i * 2 + 2;
			}
			else if (a < arr[i][0]) {
				i = i * 2 + 1;
			}
			// a가 같을 경우
			else if (b > arr[i][1]) {
				i = i * 2 + 2;
			}
			else if (b < arr[i][1]) {
				i = i * 2 + 1;
			}
		}
		arr[i][0] = a;
		arr[i][1] = b;
		printf("arr[%d][0] = %d, arr[%d][1] = %d\n", i, a, i, b); //확인용
	}
}

void print_tree(int arr[][2], int n) {
	int i = 0;
	if (istherezerozero == 1)
		printf("0 0\n");
	// 트리 중위순회 해야함. 그래야 작은 것부터 순서대로 출력
	// 스택을 만들어야하나? 어우 쉬운 건 줄 알았는디..

}