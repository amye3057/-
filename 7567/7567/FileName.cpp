#include <stdio.h>
#include <string.h>
#define CRT_SECURE_NO_WARNINGS

int main() {
	char arr[51] = {};
	int sum = 10; // ù��° �׸��� ������ 10�� �������Ƿ�.
	scanf("%s", &arr);
	for (int i = 1; i < strlen(arr); i++) {
		if (arr[i] != arr[i - 1]) {
			sum += 10;
		}
		else
			sum += 5;
	}
	printf("%d", sum);
	return 0;
}