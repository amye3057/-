#include <stdio.h>

int main() {
	int n, k;
	int x;
	int y = 0; //ÃÖ¼Ú°ª
	int arr[10] = {};
	scanf_s("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] <= k) {
			x = i;
			break;
		}
	}

	while (k != 0) {
		y += k / arr[x];
		k %= arr[x];
		x--;
	}
	printf("%d", y);
	return 0;
}