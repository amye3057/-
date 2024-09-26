#include <stdio.h>
#include <string.h>

int main() {
	int t;
	int n = 0; //그룹단어의 개수
	scanf_s("%d", &t);
	for (int i = 0; i < t; i++) {
		int ok = 1;
		char arr[101] = {};
		int alphabet[26] = {}; //97~122 //여기 단순빼기로 25 했더니 스택 오버플로우 에러 떴었음
		scanf_s("%s", arr, 101);
		for (int j = 0; j < strlen(arr); j++) {
			//printf("%d 현상태 : %d\n", arr[j], alphabet[arr[j]-97]);
			if (alphabet[arr[j] - 97] == 1) {
				ok = 0;
				break;
			}
			if (arr[j] != arr[j + 1]) {
				alphabet[arr[j] - 97]++;
				//printf("alphabet[%d]++\n", arr[j]);
			}
		}
		if (ok == 1)
			n++;
	}
	printf("%d", n);
	return 0;
}