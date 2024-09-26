#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define BASE(i)     ((char*)base + (i)*width)
typedef double (*FCMP)(const void*, const void*);

void bubble_sort(void *base, size_t nelem, size_t width, FCMP fcmp) {
	int i, j;
	void* t;
	t = malloc(width);
	for (i = nelem - 1; i > 0; i--) {
		for (j = 1; j <= i; j++) {
			if (fcmp(BASE(j-1), BASE(j)) > 0) {
				memcpy(t, BASE(j - 1), width);
				memcpy(BASE(j-1), BASE(j), width);
				memcpy(BASE(j), t, width);
			}
		}
	}
	free(t);
}

double dcmp(const void* a, const void* b) {
	return (*(double*)a - *(double*)b);
}

int main() {
	double a[] = { 4.2, 3.4, 5.6, 1.2, 3.3, 7.7 };

	bubble_sort(a, sizeof(a) / sizeof(double), sizeof(double), dcmp);

	for (int i = 0; i < 6; i++)
		printf("%lf ", a[i]);
	printf("\n");
}