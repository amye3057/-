#include <stdio.h>

//워씨 모르겠다 이거.

int main() {
	int N, L;
	int x = 0;
	int i;
	scanf_s("%d %d", &N, &L);
	int n = L;
	while (L < 101) { //언제까지 반복하는지 모르겠어서 일단.. x가 N이 될 수 없으니까.
		for (i = L; i > 1; i--) {
			n = n + (i - 1);
		}
		x = N / (L * n);

		if (x < L) { //x가 적당한 값이 나왔다는 조건이.. 어떻게 적어줘야할까. 여기 수정해야할듯!!!!!!!!!!
			for (i = 0; i < L; i++) {
				printf("%d", x);
				x = x + 1;
			}
		}
		else { //적절한 x 값이 나오지 않은 경우
			L = L + 1;
		}
	}
	if (L == 100) { //100까지 가고 while 다돌리고 나오면 -1 출력
		printf("-1");
	}
	else

		return 0;
}