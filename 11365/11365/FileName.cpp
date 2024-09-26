#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	char arr[501] = {};
	int start;
	scanf("%[^END]s", arr); ////////////////// 즐겨찾기 해놓은 C언어 폴더 글 2개 있으니까 그거 보면서.. 풀어 난 잘거임. 
	printf("%d", strlen(arr)); // 확인용
	
	for (int i = strlen(arr) - 2; i >= 0; i--) { // strlen(arr)-1은 어차피 문자열의 마지막 끝인 \0이 들어가기 때문에 -2로 써줌.
		printf("%c %c %c", arr[i], arr[i - 1], arr[i - 2]); // 확인용
		if (arr[i] == 'D' && arr[i-1]=='N' && arr[i-2]=='E') {  // 뒤에서부터 읽자. END를 뒤집은 DNE부터 시작이다.
			start = i - 3;
			break;
		}
	}
	
	for (int i = start; i >= 0; i--) {
		printf("%c", arr[i]);
	}
	return 0;
}