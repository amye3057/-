/// 참조할 수 없는 외부 참조 뭔데. 다음에 이어서 시도하자.

#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define acceptable 1
#define unacceptable 0

int vowel(char a[], int idx, int jdx);

int istherevowel = 0;

int main() {
	char arr[1000][22] = {}; // Test Case의 최대개수가 1000개인 것으로 가정.
	// 최대 20글자가 들어가므로 마지막 공백포함 21에다가, 비밀번호로써 적합한지를 마지막에 집어넣을거라 공간 하나 더 추가해서 22.
	int i = 0;

	while (1) {
		fgets(arr[i], 21, stdin);

		if (arr[i] == "end")
			break;

		/* 1. 모음(a, e, i, o, u) 하나를 반드시 포함하여야 한다. */
		for (int j = 0; j < strlen(arr[i]); j++) {
			if (vowel(arr[i], i, j)) { // 맞나?????????????????????????????????????????????????
				istherevowel = 1;
				break; // 모음이 하나라도 있는게 확인되면 다음 단계로 넘어간다.
			}
		}
		if (istherevowel == 0) { // 모음이 하나도 없다면 2,3까지 갈 필요없으니 unacceptable 처리하고 다음 거 넘어가기.
			arr[i][21] = unacceptable;
			continue;
		}

		/* 2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다. */
		
	}

	i = 0;
	while (arr[i] != "end") {
		printf("<%s> is ", arr[i]);
		if (arr[i][22] == acceptable) {
			printf("acceptable");
		}
		else
			printf("not accpetable");
	}

	return 0;
}

int vowel(char arr[][22], int idx, int jdx) { //모음인지 판단하는 함수
	printf("vowel - arr[%d][%d] 입력 : %d\n", idx, jdx, arr[idx][jdx]); //확인용
	if (arr[idx][jdx] == 'a' || arr[idx][jdx] == 'e' || arr[idx][jdx] == 'i' || arr[idx][jdx] == 'o' || arr[idx][jdx] == 'u') {
		return 1; // 모음이 맞으면 1 반환
	}
	else
		return 0;
}