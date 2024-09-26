#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	char a[9] = {};
	char b[9] = {};
	char c[9] = {};
	int d;
	scanf("%s", &a);
	scanf("%s", &b);
	scanf("%s", &c);
	printf("%s %s %s", a, b, c); //확인용
	
	if (c == "Fizz" || c == "Buzz" || c == "FizzBuzz") { // 여기에 마지막 FizzBuzz 이거 왜.. 얘가 인식을 못하지.
		if (b == "Fizz" || b == "Buzz" || b == "FizzBuzz") {
			if (a == "Fizz" || a == "Buzz" || a == "FizzBuzz") { // a가 숫자일 경우
				d = atoi(a) + 3;
			}
			else {
				// 3개의 연속된 문자열이 모두 문자인 경우. (가 있..진 않겠지? 잘 몰라서 일단 이렇게 해둠)
			}
		}
		else { // b가 숫자일 경우
			d = atoi(b) + 2;
			printf("d = %d\n", d); //확인용
		}
	}
	else { // c가 숫자일 경우
		printf("c 값이 왜 이러지 %s\n", c); // 확인용
		// c+1을 다음에 출력하도록.
		d = atoi(c) + 1;
		printf("d = %d\n", d); //확인용
	}

	if (d % 3 == 0) {
		if (d % 5 == 0)
			printf("FizzBuzz");
		else
			printf("Fizz");
	}
	else if (d % 5 == 0) {
		printf("Buzz");
	}
	else
		printf("%d", d);

	return 0;
}