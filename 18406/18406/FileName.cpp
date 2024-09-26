#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int sumL = 0, sumR = 0;
	int a;
	int size_a = 0; // a의 자릿수
	int sa10 = 1; // a의 자릿수만큼 10 곱한거

	scanf("%d", &a);
	int aa = a;

	while (aa != 0) {
		aa /= 10;
		size_a++;
		sa10 *= 10;
	}
	//printf("size_a : %d\n", size_a); // 확인용
	sa10 /= 10; // 자릿수만큼 10을 곱했기 때문에 한 번 나눠줘야 함. ex) 10이면 2자리 수니까 10을 두번 곱해서 100이 됨. 한번 나눠준다. sa10에 0.1을 애초에 넣으면 되긴 하지만 정수형으로 선언하기 위해서..
	int mid = size_a / 2;

	for (int i = 0; i < mid; i++) {
		sumL += a / sa10;
		a %= sa10;
		sa10 /= 10;
	}

	for (int i = 0; i < mid; i++) {
		sumR += a / sa10;
		a %= sa10;
		sa10 /= 10;
	}

	//printf("sumL = %d, sumR = %d\n", sumL, sumR); // 확인용

	if (sumL == sumR)
		printf("LUCKY");
	else
		printf("READY");
	return 0;
}