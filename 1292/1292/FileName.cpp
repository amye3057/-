#include <stdio.h>
#define start 1

int main() {
	int a, b;
	int c = 1;
	int n = 0;
	int sum = 0;
	scanf_s("%d %d", &a, &b);

	for (int i = start + 1; i < 1002; i++) {
		for (int j = start; j < i; j++) {
			printf("%d ", c);
			n++;
			if (n >= a && n <= b) {
				sum += c;
				if (n == b)
					break;
			}
			else if (n == a && n == b) {
				sum += c;
				break;
			}
			else{}
		}
		c++;
		if (n == a - 1 && a == b) // a�� b�� ���� ��Ȳ����, �ڲ� 1 ���� break�� ������ ���������� ���� ���. 
			continue;
		if (n == b) // ������ break �Ǵ� ������ ������ų ��� for�� ��ü ����.
			break;
	}

	printf("\nsum : %d", sum);

	return 0;
}