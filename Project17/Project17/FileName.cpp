#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define BASE(i)     ((char*)base + (i)*width)
typedef double (*FCMP)(const void*, const void*);

void shell_sort(void *base, size_t nelem, size_t width, FCMP fcmp) {
	int i, j, k, h;
	void* v;
	v = malloc(width);
	for (h = nelem / 2; h > 0; h /= 2) {
		for (i = 0; i < h; i++) {
			for (j = i + h; j < nelem; j += h) {
				memcpy(v, BASE(j), width);
				k = j;
				while (k > h - 1 && (fcmp(BASE(k - h), v) > 0)) {
					memcpy(BASE(k), BASE(k - h), width);
					k -= h;
				}
				memcpy(BASE(k), v, width);
			}
		}
	}
}

double dcmp(const void* a, const void* b) {
	return (*(double*)a - *(double*)b);
}

int main() {
	double a[] = { 4.2, 3.4, 5.6, 1.2, 3.3, 7.7 };

	shell_sort(a, sizeof(a) / sizeof(double), sizeof(double), dcmp);


	for (int i = 0; i < 6; i++) {
		printf("%lf ", a[i]);
	}
	printf("\n");
}