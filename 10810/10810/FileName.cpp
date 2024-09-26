#include <stdio.h>
#define SECURE_NO_WARNINGS

int main() {
	int N, M;
	int a, b, c;
	int arr[101] = {};
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		for (int j = a; j < b + 1; j++) {
			arr[j] = c;
		}
	}

	for (int i = 1; i < N+1; i++) {
		printf("%d ", arr[i]);
	}
}