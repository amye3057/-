#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	char arr[501] = {};
	int start;
	scanf("%[^END]s", arr); ////////////////// ���ã�� �س��� C��� ���� �� 2�� �����ϱ� �װ� ���鼭.. Ǯ�� �� �߰���. 
	printf("%d", strlen(arr)); // Ȯ�ο�
	
	for (int i = strlen(arr) - 2; i >= 0; i--) { // strlen(arr)-1�� ������ ���ڿ��� ������ ���� \0�� ���� ������ -2�� ����.
		printf("%c %c %c", arr[i], arr[i - 1], arr[i - 2]); // Ȯ�ο�
		if (arr[i] == 'D' && arr[i-1]=='N' && arr[i-2]=='E') {  // �ڿ������� ����. END�� ������ DNE���� �����̴�.
			start = i - 3;
			break;
		}
	}
	
	for (int i = start; i >= 0; i--) {
		printf("%c", arr[i]);
	}
	return 0;
}