#include <stdio.h>
#include <time.h>

int price[] = { 0,1,5,8,9,10,17,17,20,22,26 };
int maxp(int m) {
    int i;
    int max; //�ִ� ����
    int maxCut = 10;

    if (m <= 0)
        return 0;
    if (m <= 10)
        maxCut = m;

    max = 0;
    for (i = 1; i <= maxCut; i++) {
        // i���̷� �ڸ� �� �ִ� ���� ����ϰ�, �ִ밡�� ��� �� ������Ʈ
        if (price[i] + maxp(m - i) > max) {
            max = price[i] + maxp(m - i);
        }
        //printf("max = price[%d] + maxp(%d) = %d\n ", i, maxCut-i, max); //Ȯ�ο�
    }
    return max;
}

int main() {
    int l;
    printf("Length of stick? ");
    scanf_s("%d", &l);
    clock_t start = clock();
    int p = maxp(l);
    clock_t end = clock();
    printf("Maximum price:%d\n", p);
    printf("�ҿ�ð� : %.3lf", (double)(end - start) / CLOCKS_PER_SEC);
}
