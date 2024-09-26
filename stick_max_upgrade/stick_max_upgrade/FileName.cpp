#include <stdio.h>
#include <time.h>

int maxprices[100] = { 0 }; /* 최대 가격을 일단 0으로 초기화 */
int price[] = { 0,1,5,8,9,10,17,17,20,22,26 };
int maxp(int m) {
    int i;
    int maxCut = 10;

    if (m <= 0)
        return 0;
    if (m <= 10)
        maxCut = m;
    if (maxprices[m] != NULL){
        //printf("return maxprices[%d] : %d\n", m, maxprices[m]); //확인용
        return maxprices[m];
    }

    for (i = 1; i <= maxCut; i++) {
        if (price[i] + maxp(m - i) > maxprices[m]) {
            maxprices[m] = price[i] + maxp(m - i);
        }
    }
    return maxprices[m];
}

int main() {
    int l;
    printf("Length of stick? ");
    scanf_s("%d", &l);
    clock_t start = clock();
    int p = maxp(l);
    clock_t end = clock();
    printf("Maximum price:%d\n", p);
    printf("소요시간 : %lf", (double)(end - start) / CLOCKS_PER_SEC);
}
