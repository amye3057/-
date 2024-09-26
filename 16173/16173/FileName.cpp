#include <stdio.h>
#define MMS 3 // Map Max Size

int Play(int arr[][3], int i, int j);
int goRight(int arr[][3], int i, int j);
int goDown(int arr[][3], int i, int j);

int N; // MapSize (2~3)
int END = 0;

int main() {
	int arr[MMS][MMS] = {};

	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%d", &arr[i][j]);
		}
	}

	Play(arr, 0, 0); // ���� ���� ����. arr[0][0]
	if (END == 1)
		printf("HaruHaru");
	else
		printf("Hing");
	
	return 0;
}

int Play(int arr[][3], int i, int j) {
	printf("\nPlay(%d,%d)\n", i, j); // Ȯ�ο�
	if (i == N - 1 && j == N - 1) {
		END = 1;
		return 0;
	}
	goRight(arr, i, j);
	goDown(arr, i, j);
}

int goRight(int arr[][3], int i, int j) {
	int move = j + arr[i][j];
	printf("������ : move = %d. arr[%d][%d] = %d\n", move, i, j, arr[i][j]); // Ȯ�ο�
	if (move >= N || arr[i][j] == 0) // �ش� ĭ ���� 0�̸� �̵� �Ұ�.
		return 0;
	Play(arr, i, move);
}

int goDown(int arr[][3], int i, int j) {
	int move = i + arr[i][j];
	printf("�Ʒ� : move = %d. arr[%d][%d] = %d\n", move, i,j,arr[i][j]); // Ȯ�ο�
	if (move >= N || arr[i][j]==0) // ���������� �̵��� ��ǥ�� ������ �Ѿ ���
		return 0; // �Լ� ���� (�Ʒ������� �̵��ϴ� �Լ��� �����). return 0�� �ֱ� ���� �Լ���ȯ�� void���� int�� �ٲ��.
	Play(arr, move, j);
}

