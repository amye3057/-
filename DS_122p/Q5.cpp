#include <stdio.h>
#include <stdlib.h>

int bin_search(const int a[], int n, int key) {
	int pl = 0;
	int pr = n - 1;
	do {
		int pc = (pl + pr) / 2; //계속해서 중간값도 바뀌어야 하니깐
		if (a[pc] == key)
			return pc;
		else if (a[pc] > key)
			pr = pc - 1;
		else
			pl = pc + 1;
	} while (pl <= pr);
	return -1; //실패
}

int main() {
	int nx, ky;
	printf("이진검색\n 요소 개수 : ");
	scanf_s("%d", &nx);

	int* x = (int*)calloc(nx, sizeof(int));

	printf("오름차순으로 입력하세요.\n");
	printf("x[0] : ");
	scanf_s("%d", &x[0]);

	int i = 1;
	while (i < nx) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
		if (x[i]>x[i-1]) {
			i++;
		}
		else
			printf("앞의 입력보다 큰 값을 입력해주세요.\n");
	}

	printf("검색값 : ");
	scanf_s("%d", &ky);
	int s = bin_search(x, nx, ky);
	if (s == -1)
		printf("검색에 실패했습니다.");
	else
		printf("%d는(은) x[%d]에 있습니다.", ky, s);

	free(x);
	return 0;
}