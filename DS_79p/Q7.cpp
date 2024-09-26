#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void copy(int a[], const int b[], int n) {
	for (int i = 0; i < n; i++) {
		a[i] = b[n-i-1];
	}
}

void shuffle(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int t = a[i];
		int ran = i;
		while (ran == i) {
			srand(time(NULL));
			ran = rand() % n;
		}
		a[i] = a[ran];
		a[ran] = t;
		printf("a[%d]<->a[%d]\n", i, ran);
		for (int j = 0; j < n; j++) {
			printf("%d ", a[j]);
		}
		printf("\n");
	}
}

int main() {
	int n = 5;
	int* a = (int*)calloc(n, sizeof(int));
	int* b = (int*)calloc(n, sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		b[i] = rand() % 50 + 1;
		printf("%d ", b[i]);
	}
	printf("\n");

	copy(a, b, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	shuffle(a, n);

	return 0;
}