#include <stdio.h>
int top = 0;
char stack_arr[100000] = {};
int stack_a = 0; // stack_arr�� �ε���. �� �Ǵ� ��Ȳ������ +-�� ����ϸ� �ȵǱ� ������, + -�� ������� �迭�� �������.
void POP(int s[]);
void PUSH(int s[], int n);

int main() {
	int n; // push ������ Ƚ��
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
			if (n == 0) { // �Ұ����� ���. PUSH�� �� �� �������µ� POP�� �� �� ���� ��Ȳ.
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
		printf("���� : stack empty");
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
		printf("���� : stack full");
	else {
		top++;
		s[top] = n;
		stack_arr[stack_a] = '+';
		stack_a++;
	}
}