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

	Play(arr, 0, 0); // 시작 지점 설정. arr[0][0]
	if (END == 1)
		printf("HaruHaru");
	else
		printf("Hing");
	
	return 0;
}

int Play(int arr[][3], int i, int j) {
	printf("\nPlay(%d,%d)\n", i, j); // 확인용
	if (i == N - 1 && j == N - 1) {
		END = 1;
		return 0;
	}
	goRight(arr, i, j);
	goDown(arr, i, j);
}

int goRight(int arr[][3], int i, int j) {
	int move = j + arr[i][j];
	printf("오른쪽 : move = %d. arr[%d][%d] = %d\n", move, i, j, arr[i][j]); // 확인용
	if (move >= N || arr[i][j] == 0) // 해당 칸 수가 0이면 이동 불가.
		return 0;
	Play(arr, i, move);
}

int goDown(int arr[][3], int i, int j) {
	int move = i + arr[i][j];
	printf("아래 : move = %d. arr[%d][%d] = %d\n", move, i,j,arr[i][j]); // 확인용
	if (move >= N || arr[i][j]==0) // 오른쪽으로 이동한 좌표가 범위를 넘어선 경우
		return 0; // 함수 종료 (아랫쪽으로 이동하는 함수가 실행됨). return 0을 주기 위해 함수반환을 void에서 int로 바꿨다.
	Play(arr, move, j);
}

