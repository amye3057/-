#include <stdio.h>
int top = 0;
char stack_arr[100000] = {};
int stack_a = 0; // stack_arr의 인덱스. 안 되는 상황에서는 +-를 출력하면 안되기 때문에, + -를 집어넣을 배열을 만들었다.
void POP(int s[]);
void PUSH(int s[], int n);

int main() {
	int n; // push 가능한 횟수
	int arr[100000] = {};
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	int stack[100000] = {};


	int x = 0;
	int count = 1;
	for (int i = 0; i < n * 2; i++) {

		if (arr[x] != stack[top]) {
			if (n == 0) { // 불가능한 경우. PUSH할 건 다 떨어졌는데 POP을 할 수 없는 상황.
				printf("NO");
				return 0;
			}
			PUSH(stack, count);
			count++;
			n--;
		}
		else {
			POP(stack);
			x++;
		}
	}
	for (int i = 0; i < n * 2; i++) {
		printf("%c\n", stack_arr[i]);
	}

	return 0;
}

void POP(int s[]) {
	if (top == 0)
		printf("실패 : stack empty");
	else {
		s[top] = 0;
		top--;
		//printf("pop! s[%d] = %d\n", top, s[top]);
		stack_arr[stack_a] = '-';
		stack_a++;
	}
}

void PUSH(int s[], int n) {
	if (top == 99999)
		printf("실패 : stack full");
	else {
		top++;
		s[top] = n;
		stack_arr[stack_a] = '+';
		stack_a++;
	}
}