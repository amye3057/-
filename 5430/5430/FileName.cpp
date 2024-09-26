#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

void ROLL(char arr[]);
void DROP(char arr[]);

int HEAD; // ����Ʈ���� ���� ���ŵ� ������ �� ���� ��ġ�� �ٲ��ֱ� ���� ������ ����. [ ������ ���� ���� ����Ų��.
int TAIL; // ] ������ ���� ���� ����Ų��.

int main() {
	int T;

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		char RD[100001] = {};
		int n;
		char arr[201] = {}; // �ִ� �Է��� 100�̸� -> �Է°� 100�� + ��ǥ�� 99�� + ��ȣ 2�� = 201��
		scanf("%s", RD);
		scanf("%d", &n);
		scanf("%s", arr);

		HEAD = 1;
		TAIL = strlen(arr) - 2; // -1�̸� ]�� ����Ű�Ƿ� 

		if (n == 0) { // n==0�̸� ����
			printf("error\n");
			continue;
		}

		//printf("HEAD = %d, TAIL = %d\n", HEAD, TAIL); //Ȯ�ο�///////////////////////

		for (int j = 0; j < strlen(RD); j++) {
			if (RD[j] == 'R') {
				if (RD[j + 1] == 'R') { // R�� 2�� �������� ������ ��ȯ ���� ����.
					j++;
					continue;
				}
				else { // �׷��� �ʴٸ� ��ȯ.
					ROLL(arr);
				}
			}
			else if (RD[j] == 'D') {
				if (n == 0) { // �迭�� ����ִ� ���¸�
					printf("error\n");
					continue;
				}
				else { // ������� �ʴٸ� �����.
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

void ROLL(char arr[]) { // �迭�� �ִ� ���� ������ ������ �Լ�
	//printf("HEAD = %d, TAIL = %d\n", HEAD, TAIL); //Ȯ�ο�///////////////////////
	int start = HEAD;
	int end = TAIL;
	int x;
	while (start < end) {
		x = arr[start];
		arr[start] = arr[end];
		arr[end] = x;

		// ��ǥ �ǳʶپ�� �ؼ� 1ĭ�� �ƴ� 2ĭ�� �̵�.
		start += 2;
		end -= 2;
	}
	/*
	printf("\nȮ�ο�\n");
	for (int i = start; i < end; i++) { // Ȯ�ο�
		printf("%c ", arr[i]);
	}
	printf("\n");*/
}

void DROP(char arr[]) { // ù ��° ���� ������ �Լ�
	/*
	arr[HEAD] = NULL;
	arr[HEAD + 1] = NULL;*/
	// ��� �ٵ� �� ������ ��� ������.. �ϴ� �� �ּ�ó�� �س���.
	HEAD += 2; // ��ǥ �ǳʶٱ�
}