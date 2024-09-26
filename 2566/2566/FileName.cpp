#include <stdio.h>

int main() {
	//int arr[9][9] = {}; 배열에 굳이 값을 넣지 않고도 해결 가능.
	int a;
	int n = 0;
	int I = 0;
	int J = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf_s("%d", &a);
			if (a > n) {
				n = a;
				I = i;
				J = j;
			}
		}
	}

	printf("%d\n%d %d", n, I+1, J+1);
	return 0;
}