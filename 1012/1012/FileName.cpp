#include <stdio.h>
#include <stdlib.h>

int check(int arr[][50], int x, int y, int n);

int main() {
	int t;
	int x, y, n; //����, ����, ���� ����
	int a, b;
	int arr[50][50] = {};
	scanf("%d", &t); //test case ����
	int* test = (int*)malloc(sizeof(int) * t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d %d", &x, &y, &n);
		for (int j = 0; j < n; j++) {
			scanf("%d %d", &a, &b);
			arr[a][b] = 1;
		}

		test[i] = check(arr, x, y, n); //����..
	}

	for (int i = 0; i < t; i++) {
		printf("%d\n", test[i]);
	}

}

int check(int arr[], int x, int y, int n) {
	//�̰�.. ����Լ��� ���� �����Ϸ��� �ߴµ� ��ƴ�
}
