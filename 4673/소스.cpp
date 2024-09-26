#include <stdio.h>

int zaritsu(int a) {
	int n = 1;
	while (1) {
		if (a / n < 1) {
			return n / 10;
		}
		n = n * 10;
	}
}

int main() {
	int self_num[10000] = {};

	for (int i = 1; i < 100; i++) { //애초에 왜 1부터 시작을 안함? 미친새끼. 일단 크기 에러부터 나서 10000으로 해야하는디 100으로 줄임
		int sum = i;
		int n = zaritsu(i);
		while (n > 0) {
			sum += i / n;
			i = i % n; //여기가 문제여.. 왜 무한반복하는디
			printf("sum += %d / %d = %d\n", i, n, sum);
			n = n / 10;
		}
	}

	/*
	for (int i = 1; i < 100; i++) { //여기도 100으로 일단 줄여놓음
		if (self_num[i] == 0)
			printf("%d\n", i);
	}*/

	return 0;
}