#include <stdio.h>
#include <string.h>
#define CRT_SECURE_NO_WARNINGS

int main() {
	int n;
	char arr[100000][51] = {};
	scanf("%d", &n);
	getchar(); // �̰� �� ������ ù��° ������ ������ ��.
	for (int i = 0; i < n; i++) {
		fgets(arr[i], 52, stdin); // �̰� 52�� �ٲٴϱ� �ذ��. ����!!!

		//�� �� \n�� �����ִ� �۾�.
		int length = strlen(arr[i]) - 1;
		printf("����:%d\n", length);
		if (arr[i][length] == '\n') {
			arr[i][length] = '\0';
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d. %s\n", i+1, arr[i]);
	}
	return 0;
}