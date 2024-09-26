#include <stdio.h>
#include <string.h>
#define SECURE_NO_WARNINGS

int main() {
	int n; //test case
	char arr[1000][168] = {}; //최대 r(반복) 횟수 8 * 최대 s(문자열) 길이 21 (20인데 \0 포함 21)
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int r;
		char s[21] = {};
		scanf("%d %s", &r, &s);
		int c = 0;
		int d = 0;
		while (d < strlen(s)*r) {
			for (int j = 0; j < r; j++) {
				arr[i][d] = s[c];
				d++;
			}
			c++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < strlen(arr[i]); j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}