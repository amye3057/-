#include <stdio.h>
#include <stdlib.h>

int search_idx(const int a[], int n, int key, int idx[]) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == key) {
			idx[j] = i;
			j++;
		}
	}
	printf("배열 idx\n{");
	for (int i = 0; i < j-1; i++) {
		printf("%d, ", idx[i]);
	}
	printf("%d}", idx[j-1]);
	return j;
}

int main() {
	int n, key;
	printf("요소의 개수 : ");
	scanf_s("%d", &n);
	int* x = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		printf("x[%d] = ", i);
		scanf_s("%d", &x[i]);
	}
	printf("검색값 : ");
	scanf_s("%d", &key);
	int* idx = (int*)calloc(n, sizeof(int));
	int s = search_idx(x, n, key, idx);
	printf("\n반환값 : %d", s);
	return 0;
}