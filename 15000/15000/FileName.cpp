#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	char arr[1000000] = {};
	scanf("%s", arr);
	for (int i = 0; i < strlen(arr); i++) {
		printf("%c", arr[i] - 32);
	}
	return 0;
}