#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	char arr[100000] = {};
	char brr[100000] = {};
	long long sum = 0;

	scanf("%s", &arr);
	scanf("%s", &brr);

	for (int i = 0; i < strlen(arr); i++) {
		for (int j = 0; j < strlen(brr); j++) {
			sum += (arr[i]-'0') * (brr[j] - '0'); // atoi를 쓰려고 했는데 char가 아닌 *char를 형변환시키는 용이었다. 그래서 배열의 한 부분만 형변환하는 방법을 찾아보니 이런 게 있었다.
			/* 숫자의 아스키 값은 48번부터 0~9를 할당하고 있으므로, char형 '1'은 정수값 49를 가진다.
			따라서 0의 아스키 값인 48을 char형의 값에서 빼주면 순수한 숫자를 얻어낼 수 있다. 근데 -48을 넣으면 코드를 읽기 어려움. (갑자기 48이 왜 나와? 이렇게 되니까)
			그래서 그냥 '0'을 빼준거다. */
		}
	}
	printf("%lld", sum);
	return 0;
}