#include <stdio.h>
#define SECURE_NO_WARNINGS

int main() {
	int M, N;
	int a, b, t;
	int arr[101] = {};
	int brr[101] = {};

	for (int i = 1; i < 101; i++) {
		arr[i] = i;
	}

	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		while (a < b) {
			t = arr[b];
			arr[b] = arr[a];
			arr[a] = t;
			a++;
			b--;
		}
	}

	for (int i = 1; i < N + 1; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}