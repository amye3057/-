#include <stdio.h>

int foo1(int a[], int n) {
    int i, j;
    int k = 0;
    int s = 1;
    for (i = 1; i <= n; i = i + 1) {
        for (j = 0; j < i; j++) {
            s *= a[j];
            k++;
            printf("%d *= a[%d](=%d), k=%d\n", s, j, a[j],k);
            if (s == 0) break;
        }
    }
    printf("ÃÑ ¹Ýº¹ È½¼ö : %d\n", k);
    return s;
}

int main() {
    int x[1000];
    int i;
    for (i = 0; i < 1000; i++)
        x[i] = i;
    printf("%d", foo1(x, 1000));
}