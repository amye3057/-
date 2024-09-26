#include <stdio.h>
#include <string.h>

int main() {
	int n, m;
	int arr_plus[10000001] = {};
	int arr_minus[10000001] = {};
	int print_arr[500000] = {};

	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		int x;
		scanf_s("%d", &x);
		if (x >= 0) {
			arr_plus[x]++;
		}
		else
			arr_minus[x*(-1)]++;
	}

	scanf_s("%d", &m);
	for (int i = 0; i < m; i++) {
		int x;
		scanf_s("%d", &x);
		if (x >= 0) {
			print_arr[i] = arr_plus[x];
		}
		else
			print_arr[i] = arr_minus[x*(-1)];
	}

	for (int i = 0; i < m; i++) {
		printf("%d ", print_arr[i]);
	}
	return 0;
}