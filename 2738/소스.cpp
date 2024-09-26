#include <stdio.h>
#include <stdlib.h>

int main() {
	int x, y;
	int n;
	scanf_s("%d %d", &x, &y);
	int** a = (int**)calloc(x, sizeof(int*)); //2차원 배열을 만들 땐 포인터 두개 (**) (sizeof(int*))
	for (int i = 0; i < x; i++) {
		a[i] = (int*)calloc(y, sizeof(int));
	}
	for (int z = 0; z < 2; z++) {
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				scanf_s("%d", &n);
				a[i][j] += n;
			}
		}
	}
	
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < x; i++) {
		free(a[i]);
	}
	free(a);

	return 0;
}