#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	char arr[101] = {};
	int alphabet[26] = {};
	scanf("%s", &arr);
	for (int i = 0; i < strlen(arr); i++) {
		alphabet[arr[i]-97]++; // ���ĺ� �ҹ��� �ƽ�Ű�ڵ� ���� 97~122
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", alphabet[i]);
	}
	return 0;
}