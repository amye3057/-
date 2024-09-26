#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define n 9 //난쟁이의 수

int main() {
	int T[n] = {};
	int sum = 0;
	int fake; // 가짜를 찾기 위한 수
	for (int i = 0; i < n; i++) {
		scanf("%d", &T[i]);
		sum += T[i];
	}

	fake = sum - 100;
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (T[i] + T[j] == fake) {
				//printf("T[%d]=%d, T[%d]=%d\n", i, T[i], j, T[j]); //확인용
				T[i] = NULL;
				T[j] = NULL;
				i = n; // 아래에 break 하나만 추가했을 때는 안쪽 for문 루프만 빠져나오기 때문에 바깥쪽 for문이 돌아가서 루프가 계속 돌아간다. 바깥쪽도 빠져나가도록 i=n을 추가함.
				break;
			}
		}
	}
	//printf("\nfake=%d\n", fake); //확인용

	//오름차순 정렬(버블 정렬)
	int a;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1; j++) {
			if (T[j] > T[j + 1]) {
				a = T[j];
				T[j] = T[j + 1];
				T[j + 1] = a;
				//printf("%d<->%d\n", T[j], T[j + 1]); //확인용
			}
		}
	}

	for (int i = 2; i < n; i++) {
		printf("%d\n", T[i]);
	}

	return 0;
}