#include <stdio.h>

int main() {
	int n;
	int arr[500000] = {};
	int brr[500000] = {};
	int locate_i;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	/* 수정을 해봤는데.. 이러면 9 7 3 6 8 에서 제대로 될 수가 없음. 
	8보다 큰 거 까지 쭉 이동 -> 9임. 8부터 중간까지 다 9의 위치인 1을 넣었는데 이러면 73 저 부분이 문제가 생기니까, 앞뒤비교를 추가해서 73처럼 걸리는 부분은 제외하려고 했음.
	근데 생각해보니 근접해있는 앞뒤만 비교하면 안됨. 7 6도 문제가 발생. 하...
	시간 초과 때문에 수정한 건데 지금 답이 없음. 일단 패스
	*/

	for (int i = n - 1; i > 0; i--) {
		int ok = 0;
		for (int j = i - 1; j >= 0; j--) {
			printf("arr[%d] = %d, arr[%d] = %d\n", i, arr[i], j, arr[j]);
			if (ok != 1 && j != 0 && arr[j] < arr[j - 1]) { // 1 2 3 5 4 6 과 같이 중간에 저런 경우 처리. j가 0이면 j-1에서 에러가 생길 수 있어서 제외. 
				locate_i = j;
				printf("locate_i = %d\n", locate_i);
				ok = 1; // 한번만 실행해야해서 변수 ok 추가
			}
			if (arr[i] < arr[j]) {
				for (int k = i; k > locate_i; k--) { // 중간에 끼인 것들까지 한번에 처리. 
					brr[k] = j + 1; // 배열 [0]이 첫번째라 +1 해줌
					printf("brr[%d] = %d\n", k, j + 1);
				}
				if(brr[0]!=NULL) //brr이 다 찰때까지 반복. 이 조건이 없으면 아래에서 i가 계속 1이 더해지면서 무한루프를 돈다. 
					i = locate_i + 1;
				break;
			}
			if (j == 0) { // 레이저 신호를 수신하는 탑이 존재하지 않으면 0
				arr[i] = 0;
			}
		}
	}
	brr[0] = 0;

	for (int i = 0; i < n; i++) {
		printf("%d ", brr[i]);
	}
	return 0;
}