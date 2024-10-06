#include <stdio.h>

int main() {
	int n;
	int arr[10000] = {};
	int i = 0;
	while (1) {
		scanf_s("%d", &n);
		if (n == 0)
			break;
		arr[i] = (n + 1) * (n / 2);
		if (n % 2 != 0) {
			arr[i] += n / 2 + 1;
		}
		i++;
	}
	for (int j = 0; j < i; j++) {
		printf("%d\n", arr[j]);
	}
	return 0;
}