/// ������ �� ���� �ܺ� ���� ����. ������ �̾ �õ�����.

#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define acceptable 1
#define unacceptable 0

int vowel(char a[], int idx, int jdx);

int istherevowel = 0;

int main() {
	char arr[1000][22] = {}; // Test Case�� �ִ밳���� 1000���� ������ ����.
	// �ִ� 20���ڰ� ���Ƿ� ������ �������� 21���ٰ�, ��й�ȣ�ν� ���������� �������� ��������Ŷ� ���� �ϳ� �� �߰��ؼ� 22.
	int i = 0;

	while (1) {
		fgets(arr[i], 21, stdin);

		if (arr[i] == "end")
			break;

		/* 1. ����(a, e, i, o, u) �ϳ��� �ݵ�� �����Ͽ��� �Ѵ�. */
		for (int j = 0; j < strlen(arr[i]); j++) {
			if (vowel(arr[i], i, j)) { // �³�?????????????????????????????????????????????????
				istherevowel = 1;
				break; // ������ �ϳ��� �ִ°� Ȯ�εǸ� ���� �ܰ�� �Ѿ��.
			}
		}
		if (istherevowel == 0) { // ������ �ϳ��� ���ٸ� 2,3���� �� �ʿ������ unacceptable ó���ϰ� ���� �� �Ѿ��.
			arr[i][21] = unacceptable;
			continue;
		}

		/* 2. ������ 3�� Ȥ�� ������ 3�� �������� ���� �� �ȴ�. */
		
	}

	i = 0;
	while (arr[i] != "end") {
		printf("<%s> is ", arr[i]);
		if (arr[i][22] == acceptable) {
			printf("acceptable");
		}
		else
			printf("not accpetable");
	}

	return 0;
}

int vowel(char arr[][22], int idx, int jdx) { //�������� �Ǵ��ϴ� �Լ�
	printf("vowel - arr[%d][%d] �Է� : %d\n", idx, jdx, arr[idx][jdx]); //Ȯ�ο�
	if (arr[idx][jdx] == 'a' || arr[idx][jdx] == 'e' || arr[idx][jdx] == 'i' || arr[idx][jdx] == 'o' || arr[idx][jdx] == 'u') {
		return 1; // ������ ������ 1 ��ȯ
	}
	else
		return 0;
}