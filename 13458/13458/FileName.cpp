#include <stdio.h>
int main() {
	int n;
	int a[1000000] = {};
	int b, c;
	long long int sum; // 출력이 잘 되는데 무슨 문제가 있나 했더니, 너무 큰 값들이 입력되어서 sum의 크기가 커지면서 오버플로우가 남. sum의 자료형을 바꿔주고 출력도 %lld로 바꾸니 성공.

	scanf_s("%d", &n);
	sum = n; // 총감독관은 무조건 한명이 필요함
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}
	scanf_s("%d %d", &b, &c);

	for (int i = 0; i < n; i++) {
		a[i] -= b; // 총감독관은 무조건 한명이 필요함
		if (a[i] <= 0) // a[i]가 0보다 작아질 상황을 고려하지 않고 a[i]==0 으로 조건을 두어서 틀렸음.
			continue; // 여기를 break로 넣어서 for문이 n번 돌아야하는데 계속 루프를 빠져나왔던 거였다.
		if (a[i] < c) {
			sum++;
		}
		else {
			sum += a[i] / c;
			if (a[i] % c != 0)
				sum++;
		}
	}
	printf("%lld", sum);
	return 0;
}