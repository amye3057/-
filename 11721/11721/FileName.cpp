#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	char arr[101] = {};
	scanf("%s", arr);
	int n = 0;
	while (arr[n] != NULL) {
		for (int i = 0; i < 10; i++) {
			if (arr[n] == NULL)
				break;
			printf("%c", arr[n]);
			n++;
		}
		printf("\n");
	}
	return 0;
}