#include <stdio.h>
#include <string.h>
#define SECURE_NO_WARNINGS

int main() {
	char arr[1000001] = {};
	scanf("%[^\n]s", &arr, 1000001);
	int i = 0;
	int g = 0;
	int len = strlen(arr);

	if (len == 0) { //아무것도 입력하지 않을 시
		printf("0");
		return 0;
	}

	while (arr[i] == ' ') { //앞의 공백 무시
		i++;
	}

	if (i != len) { //전부 공백일 시 i=len가 된다. 나는 단어의 수를 어떻게 구했냐면 공백의 수+1로 구했기에, 전부 공백이 아닐 시 1을 더하도록 해주었음.
		g++;
	}

	while (i < len) {
		if (arr[i] == ' ' && (arr[i + 1] == ' ' || i + 1 == len)) //현재 공백인 상태에서 1.뒤에 또 공백이 오거나 2.문자열의 끝인 경우 -> 더 이상 뒤에 카운트 하지 않음
			break;
		if (arr[i] == ' ')
			g++;
		i++;
	}
	
	printf("%d", g);
	return 0;
}