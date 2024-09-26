#include <stdio.h>
#include <string.h>
#define CRT_SECURE_NO_WARNINGS

int main() {
	char arr[51] = {};
	int sum = 10; // 첫번째 그릇은 무조건 10을 가져가므로.
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