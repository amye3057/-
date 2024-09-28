#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char pw[21] = {};
		scanf("%s", &pw);
		int len = strlen(pw);
		if (len >= 6 && len <= 9)
			printf("yes\n");
		else
			printf("no\n");
		//getchar();
	}
	return 0;
}