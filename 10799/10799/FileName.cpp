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
		printf("arr[%d] = %d", i, arr[i]); //�����
		if (arr[i] == '(' && arr[i + 1] == ')') { // laser Ž��
			if (left != 0) // () �������� ��ȣ �ȿ� �� ���. ()�� �޶� ���� ���� �׳� �����ص� �ȴ�
				laser++;
			i++;
			printf("�����a\n");
			continue;
		}
		else if (arr[i] == ')') { // ��ȣ ) Ž��
			printf("�����b\n");
			right++;
		}
		else { // ��ȣ ( Ž��
			printf("�����c\n");
			left++;
		}

		if (left == right) { // ��ȣ �ϳ� �Ϸ�
			sum += 2 * left * laser - left; // (��ȣ�� ����)*2*(������ ����) - ��ȣ�� ����*1
			printf("sum += 2*%d*%d - %d -> sum = %d\n", left, laser, right, sum);
			laser = 0; // ������ ��, ��ȣ ���� ī��Ʈ �ʱ�ȭ
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