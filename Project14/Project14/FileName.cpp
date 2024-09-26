#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define BASE(i)     ((char*)base + (i)*width)
typedef int (*FCMP)(const void*, const void*);

void select_sort(void* base, size_t nelem, size_t width,
    double (*fcmp)(const void*, const void*)) {
    void* min;
    int minindex, i, j;
    min = malloc(width);
    for (i = 0; i < nelem - 1; i++) {
        minindex = i;
        for (j = i + 1; j < nelem; j++)
            if (fcmp(BASE(minindex), BASE(j)) > 0)
                minindex = j;
        memcpy(min, BASE(minindex), width);
        memcpy(BASE(minindex), BASE(i), width);
        memcpy(BASE(i), min, width);
    }
    free(min);
}

double dcmp(const void* a, const void* b) {
    return (*(double*)a - *(double*)b);
}



int main() {
    double a[] = { 4.2, 3.4, 5.6, 1.2, 3.3, 7.7 };

    select_sort(a, sizeof(a) / sizeof(double), sizeof(double), dcmp);


    for (int i = 0; i < 6; i++)
        printf("%lf ", a[i]);
    printf("\n");
}