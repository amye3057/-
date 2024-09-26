#include <stdio.h>

unsigned bits(unsigned x, int k, int j) {
    return (x >> k) & ~(~0 << j);
}

void radix_exchange_sort(char a[], int n, int b) {
    int i, j;
    char t;
    if (n > 1 && b >= 0) {
        i = 0;
        j = n - 1;
        while (i != j) {
            while (bits(a[i], b, 1) == 0 && i < j) i++;
            while (bits(a[j], b, 1) != 0 && i < j) j--;
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
        if (bits(a[n - 1], b, 1) == 0) {
            j++;
            printf("%c %d\n", a[n - 1], n - 1);
        }
        radix_exchange_sort(a, j, b - 1);
        radix_exchange_sort(a + j, n - j, b - 1);
    }
}

int main() {
    char a[] = { 't','h','i','s','p','r','o','b','l','e','m' };
    radix_exchange_sort(a, sizeof(a), sizeof(char) * 8 - 1);
    printf("{");
    for (int i = 0; i < sizeof(a); i++) {
        printf("%c ", a[i]);
    }
    printf("}");
    return 0;
}