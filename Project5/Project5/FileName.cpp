#include <stdio.h>
#include <stdlib.h>
#define x 4

int sparseMatrix(int a[][x], int b[][3]) { //b에 a의 희소행렬을 넣고, 0이 아닌 원소의 개수를 반환.
    int n = 0;
    int A = 1;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if (a[i][j] != 0) {
                b[A][0] = i;
                b[A][1] = j;
                b[A][2] = a[i][j];
                A++;
                n++;
            }
        }
    }
    b[0][0] = x;
    b[0][1] = x;
    b[0][2] = n;
    return n;
}

void transpose(int a[][3], int b[][3]) {
    int n = a[0][1]; int terms = a[0][2];
    int* s = (int*)calloc(n, sizeof(int));
    int* t = (int*)calloc(n, sizeof(int));
    int i, j;
    b[0][0] = n; b[0][1] = a[0][0]; b[0][2] = terms;
    for (i = 1; i <= terms; i++) s[a[i][1]]++;
    t[0] = 1;
    for (i = 1; i < n; i++) t[i] = t[i - 1] + s[i - 1];
    for (i = 1; i <= terms; i++) {
        j = t[a[i][1]];
        b[j][0] = a[i][1];
        b[j][1] = a[i][0];
        b[j][2] = a[i][2];
        t[a[i][1]] = j + 1;
    }
}

int main() {
    int a[x][x] = { {0,1,0,0},{0,0,2,3},{4,0,0,0,},{0,5,6,0} };
    printf("2차원 %dx%d 배열\n", x, x);
    for (int i = 0; i < x; i++) { //확인용
        for (int j = 0; j < x; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int b[100][3] = {}; //a의 희소행렬이 들어갈 배열. 행의 크기는 100으로 설정했다.
    int n = sparseMatrix(a, b);
    printf("희소행렬\n");
    for (int i = 0; i < n + 1; i++) { //확인용
        for (int j = 0; j < 3; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    int c[100][3] = {}; //b의 전치행렬이 들어갈 배열
    transpose(b, c);
    printf("전치행렬\n");
    for (int i = 0; i < n + 1; i++) { //확인용
        for (int j = 0; j < 3; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}