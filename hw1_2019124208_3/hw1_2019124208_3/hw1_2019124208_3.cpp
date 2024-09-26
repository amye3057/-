#include <stdio.h>
#define x 2
#define y 2

void inputMatrix(int a[][y]) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}
}

void multiMatrix(int a[][y], int b[][y], int c[][y]) {
	int xx = 0;
	int yy = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			for (int k = 0; k < y; k++) {
				c[xx][yy] += a[xx][k] * b[k][yy];
				//printf("c[%d][%d] += a[%d][%d] * b[%d][%d] : %d += %d * %d\n", xx, yy, xx, k, k, yy, c[xx][yy], a[xx][k], b[k][yy]);
		}
			//printf("c[%d][%d] = %d\n", xx, yy, c[xx][yy]);
			yy++;
			if (yy >= 2) {
				yy = 0;
				xx++;
			}
		}
	}
}

int main() {
	int a[x][y];
	int b[x][y];
	int c[x][y] = {};
	printf("Input elements of the first 2x2 matrix: ");
	inputMatrix(a);
	printf("Input elements of the second 2x2 matrix: ");
	inputMatrix(b);
	multiMatrix(a, b, c);
	printf("The result of multiplication\n");
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	return 0;
}