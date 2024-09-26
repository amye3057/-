#include <stdio.h>
#include <string.h>
#define SECURE_NO_WARNINGS

int main() {
	int n;
	scanf("%d", &n);
	char arr[10][2] = {};

	for (int i = 0; i < n; i++) {
		char a[1000] = {};
		scanf("%s", &a);
		arr[i][0] = a[0];
		arr[i][1] = a[strlen(a)-1];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}