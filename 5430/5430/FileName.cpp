#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

void ROLL(char arr[]);
void DROP(char arr[]);

int HEAD; // 리스트에서 수가 제거될 때마다 맨 앞의 위치를 바꿔주기 위해 선언한 변수. [ 다음에 오는 수를 가리킨다.
int TAIL; // ] 이전에 오는 수를 가리킨다.

int main() {
	int T;

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		char RD[100001] = {};
		int n;
		char arr[201] = {}; // 최대 입력이 100이면 -> 입력값 100개 + 쉼표값 99개 + 괄호 2개 = 201개
		scanf("%s", RD);
		scanf("%d", &n);
		scanf("%s", arr);

		HEAD = 1;
		TAIL = strlen(arr) - 2; // -1이면 ]를 가리키므로 

		if (n == 0) { // n==0이면 에러
			printf("error\n");
			continue;
		}

		//printf("HEAD = %d, TAIL = %d\n", HEAD, TAIL); //확인용///////////////////////

		for (int j = 0; j < strlen(RD); j++) {
			if (RD[j] == 'R') {
				if (RD[j + 1] == 'R') { // R이 2번 연속으로 나오면 교환 과정 생략.
					j++;
					continue;
				}
				else { // 그렇지 않다면 교환.
					ROLL(arr);
				}
			}
			else if (RD[j] == 'D') {
				if (n == 0) { // 배열이 비어있는 상태면
					printf("error\n");
					continue;
				}
				else { // 비어있지 않다면 지우기.
					DROP(arr);
					n--;
				}
			}
		}

		if (n != 0) {
			printf("[");
			for (int i = HEAD; i < TAIL + 1; i++) {
				printf("%c", arr[i]);
			}
			printf("]\n");
		}
	}
	return 0;
}

void ROLL(char arr[]) { // 배열에 있는 수의 순서를 뒤집는 함수
	//printf("HEAD = %d, TAIL = %d\n", HEAD, TAIL); //확인용///////////////////////
	int start = HEAD;
	int end = TAIL;
	int x;
	while (start < end) {
		x = arr[start];
		arr[start] = arr[end];
		arr[end] = x;

		// 쉼표 건너뛰어야 해서 1칸이 아닌 2칸씩 이동.
		start += 2;
		end -= 2;
	}
	/*
	printf("\n확인용\n");
	for (int i = start; i < end; i++) { // 확인용
		printf("%c ", arr[i]);
	}
	printf("\n");*/
}

void DROP(char arr[]) { // 첫 번째 수를 버리는 함수
	/*
	arr[HEAD] = NULL;
	arr[HEAD + 1] = NULL;*/
	// 사실 근데 안 버려도 상관 없긴함.. 일단 걍 주석처리 해놓음.
	HEAD += 2; // 쉼표 건너뛰기
}