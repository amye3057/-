#include <stdio.h>

void downheap(int a[], int n, int k) {
	int i, v;
	v = a[k];
	while (k <= n / 2) {
		i = k << 1;
		if (i < n && a[i] < a[i + 1]) i++;
		if (v >= a[i]) break;
		a[k] = a[i];
		k = i;
	}
	a[k] = v;
}

int main() {
	int k, i;
	int a[] = { 999,4,1,6,2,3,5 };
	for (k = 3; k >= 1; k--) {
		downheap(a, 7, k);
		for (i = 1; i <= 6; i++) {
			printf("%d", a[i]);
		}
		printf("\n");
	}
}