#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define n 9 //�������� ��

int main() {
	int T[n] = {};
	int sum = 0;
	int fake; // ��¥�� ã�� ���� ��
	for (int i = 0; i < n; i++) {
		scanf("%d", &T[i]);
		sum += T[i];
	}

	fake = sum - 100;
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (T[i] + T[j] == fake) {
				//printf("T[%d]=%d, T[%d]=%d\n", i, T[i], j, T[j]); //Ȯ�ο�
				T[i] = NULL;
				T[j] = NULL;
				i = n; // �Ʒ��� break �ϳ��� �߰����� ���� ���� for�� ������ ���������� ������ �ٱ��� for���� ���ư��� ������ ��� ���ư���. �ٱ��ʵ� ������������ i=n�� �߰���.
				break;
			}
		}
	}
	//printf("\nfake=%d\n", fake); //Ȯ�ο�

	//�������� ����(���� ����)
	int a;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1; j++) {
			if (T[j] > T[j + 1]) {
				a = T[j];
				T[j] = T[j + 1];
				T[j + 1] = a;
				//printf("%d<->%d\n", T[j], T[j + 1]); //Ȯ�ο�
			}
		}
	}

	for (int i = 2; i < n; i++) {
		printf("%d\n", T[i]);
	}

	return 0;
}