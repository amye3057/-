#include <stdio.h>

int zaritsu(int a) {
	int n = 1;
	while (1) {
		if (a / n < 1) {
			return n / 10;
		}
		n = n * 10;
	}
}

int main() {
	int self_num[10000] = {};

	for (int i = 1; i < 100; i++) { //���ʿ� �� 1���� ������ ����? ��ģ����. �ϴ� ũ�� �������� ���� 10000���� �ؾ��ϴµ� 100���� ����
		int sum = i;
		int n = zaritsu(i);
		while (n > 0) {
			sum += i / n;
			i = i % n; //���Ⱑ ������.. �� ���ѹݺ��ϴµ�
			printf("sum += %d / %d = %d\n", i, n, sum);
			n = n / 10;
		}
	}

	/*
	for (int i = 1; i < 100; i++) { //���⵵ 100���� �ϴ� �ٿ�����
		if (self_num[i] == 0)
			printf("%d\n", i);
	}*/

	return 0;
}