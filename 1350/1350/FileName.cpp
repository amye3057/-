#include <stdio.h>

int main() {
	int n;
	int arr[50] = {};
	int cluster;
	int sum = 0;

	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	scanf_s("%d", &cluster);

	for (int i = 0; i < n; i++) {
		if (arr[i] == 0)
			continue;
		else if (cluster >= arr[i]) {
			sum += cluster;
		}
		else {
			sum += (arr[i] / cluster) * cluster;
			if (arr[i] % cluster != 0)
				sum += cluster;
		}
	}

	printf("%d", sum);
	return 0;
}