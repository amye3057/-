#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int sumL = 0, sumR = 0;
	int a;
	int size_a = 0; // a�� �ڸ���
	int sa10 = 1; // a�� �ڸ�����ŭ 10 ���Ѱ�

	scanf("%d", &a);
	int aa = a;

	while (aa != 0) {
		aa /= 10;
		size_a++;
		sa10 *= 10;
	}
	//printf("size_a : %d\n", size_a); // Ȯ�ο�
	sa10 /= 10; // �ڸ�����ŭ 10�� ���߱� ������ �� �� ������� ��. ex) 10�̸� 2�ڸ� ���ϱ� 10�� �ι� ���ؼ� 100�� ��. �ѹ� �����ش�. sa10�� 0.1�� ���ʿ� ������ �Ǳ� ������ ���������� �����ϱ� ���ؼ�..
	int mid = size_a / 2;

	for (int i = 0; i < mid; i++) {
		sumL += a / sa10;
		a %= sa10;
		sa10 /= 10;
	}

	for (int i = 0; i < mid; i++) {
		sumR += a / sa10;
		a %= sa10;
		sa10 /= 10;
	}

	//printf("sumL = %d, sumR = %d\n", sumL, sumR); // Ȯ�ο�

	if (sumL == sumR)
		printf("LUCKY");
	else
		printf("READY");
	return 0;
}