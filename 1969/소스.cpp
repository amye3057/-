#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b;
	scanf_s("%d %d", &a, &b);
	int** c = (int**)calloc(a, sizeof(int));
	for (int i = 0; i < a; i++) {
		c[i] = (int*)calloc(b, sizeof(int));
		for (int j = 0; j < b; j++) {
			scanf_s("%s", c[i][j]);
		}
	}

	for (int i = 0; i < b; i++) {
		for (int j = 0; j < a; j++) { //4���� ���� T,C,G,A�� �̷���� �� �ִ�. �� ������ ���ڿ� �´� ��ȣ �ƽ�Ű�ڵ�.. �迭 �ȿ� ���� ���� �ؼ� ���� ���� �� ��÷.

		}
	}
	
}