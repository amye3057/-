#include <stdio.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);

	printf("%d", t->tm_year + 1900);

	// 2024-7-24 출력이 틀렸단다. 왜냐했더니 2024-07-24여야함. 그래서 걍 1자리 수면 앞에 0 붙게함.
	if (t->tm_mon < 10) {
		printf("-0%d", t->tm_mon + 1);
	}
	else
		printf("-%d", t->tm_mon + 1);


	if (t->tm_mday < 10) {
		printf("-0%d", t->tm_mday);
	}
	else
		printf("-%d", t->tm_mday);

	return 0;
}