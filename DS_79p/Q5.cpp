#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0)

void putarr(int a[], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100 + 1;
		printf("%d ", a[i]);
	}
	printf("\n");
}

void reverse(int a[], int n) {
	for (int i = 0; i < n / 2; i++) {
		swap(int, a[i], a[n - i - 1]);
		printf("a[%d] <-> a[%d] : ", i, n - i - 1);
		for (int i = 0; i < n; i++)
			printf("%d ", a[i]);
		printf("\n");
	}
}

int main_a() {
	int n = 10;
	int* arr = (int*)calloc(n, sizeof(int));
	putarr(arr, n);
	reverse(arr, n);
	return 0;
}