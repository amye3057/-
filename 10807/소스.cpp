#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, key;
	int y = 0;
	scanf_s("%d", &n);
	int* x = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf_s("%d",&x[i]);
	}
	scanf_s("%d", &key);
	for (int i = 0; i < n; i++) {
		if (x[i] == key)
			y++;
	}
	printf("%d", y);
	return 0;
}