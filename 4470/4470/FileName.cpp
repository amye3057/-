#include <stdio.h>
#include <string.h>
#define CRT_SECURE_NO_WARNINGS

int main() {
	int n;
	char arr[100000][51] = {};
	scanf("%d", &n);
	getchar(); // 이거 안 넣으면 첫번째 문장은 공백이 됨.
	for (int i = 0; i < n; i++) {
		fgets(arr[i], 52, stdin); // 이걸 52로 바꾸니까 해결됨. 으아!!!

		//맨 뒤 \n을 없애주는 작업.
		int length = strlen(arr[i]) - 1;
		printf("길이:%d\n", length);
		if (arr[i][length] == '\n') {
			arr[i][length] = '\0';
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d. %s\n", i+1, arr[i]);
	}
	return 0;
}