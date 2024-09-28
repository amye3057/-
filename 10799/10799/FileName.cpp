#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

char stack[100000] = {};
void put(char a);
int pop();

int tail = 0;

int main() {
	char arr[100000] = {};
	scanf("%s", &arr);

	int len = strlen(arr);
	int left = 0;
	int right = 0;
	int laser = 0;
	int sum = 0;

	for (int i = 0; i < len; i++) {
		printf("arr[%d] = %d", i, arr[i]); //실험용
		if (arr[i] == '(' && arr[i + 1] == ')') { // laser 탐지
			if (left != 0) // () 레이저가 괄호 안에 들어간 경우. ()만 달랑 있을 경우는 그냥 무시해도 된다
				laser++;
			i++;
			printf("실험용a\n");
			continue;
		}
		else if (arr[i] == ')') { // 괄호 ) 탐지
			printf("실험용b\n");
			right++;
		}
		else { // 괄호 ( 탐지
			printf("실험용c\n");
			left++;
		}

		if (left == right) { // 괄호 하나 완료
			sum += 2 * left * laser - left; // (괄호의 개수)*2*(레이저 개수) - 괄호의 개수*1
			printf("sum += 2*%d*%d - %d -> sum = %d\n", left, laser, right, sum);
			laser = 0; // 레이저 값, 괄호 개수 카운트 초기화
			left = 0;
			right = 0;
		}
	}
	printf("%d", sum);

	return 0;
}

void put(int a) {
	stack[tail] = a;
	tail++;
}

int pop() {
	return stack[tail--];
}