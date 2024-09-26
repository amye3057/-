#include <stdio.h>
#include <string.h>

int main() {
	char arr[101] = {};
	int result = 1;
	scanf_s("%s", arr, 101);
	int n = strlen(arr);
	for (int i = 0; i < n; i++) {
		if (arr[i] != arr[n -1- i]) {
			result = 0;
			break;
		}
	}
	printf("%d", result);
	return 0;
}