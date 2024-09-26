#include <stdio.h>

void multiply_matrix(int m1[], int m2[], int m3[], int m, int n, int l)
{
    int i, j, k;

    for (i = 0; i < m; i++)
        for (j = 0; j < l; j++) {
            m3[i * l + j] = 0;
            for (k = 0; k < n; k++) {
                m3[i * l + j] += m1[i * n + k] * m2[k * l + j];
            }
        }
}

int main() {
    int a[4][2] = { {1,2},{3,4},{5,6},{7,8} };
    int b[2][3] = { {1,2,3},{2,3,4} };
    int c[4][3] = {};
    multiply_matrix(*a, *b, *c, 4, 2, 3); //a,b¸¦°öÇØ¼­
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
