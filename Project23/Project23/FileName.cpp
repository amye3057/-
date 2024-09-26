#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_VERTICES 7
#define MAX 999


void allcosts(int cost[][MAX_VERTICES], //<-�� ���� �� MAX_VERTICES�� �������� �𸣰ڴ� �迭 �ȿ� ���� �� �ƴѰ�? �̰� �� �迭 �ε������� ����ִ°�
    int distance[][MAX_VERTICES], int n) {
    /* �� �������� �ٸ� ��� ���������� �Ÿ� ���,cost:���� ���, distance:�Ÿ���*/
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            distance[i][j] = cost[i][j];
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    if (i == j)
                        distance[i][j] = 0;
                    printf(" %d - %d - %d: %d\n", i, k, j, distance[i][j]);
                }
    /*
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            if (distance[i][j] == MAX) {
                printf("distance[%d][%d] = MAX\n", i, j);
            }
            else if (i==j) { //�ڱ��ڽ�
                printf("distance[%d][%d] = 0\n", i, j);
            }
            else
                printf("distance[%d][%d] = %d\n", i, j, distance[i][j]);
        }
    }*/
}

int main() {
    int cost[MAX_VERTICES][MAX_VERTICES] = {};
    int distance[MAX_VERTICES][MAX_VERTICES] = {};

    FILE* fp;
    char filename[] = "nodelink.txt";

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("���� ���� ����");
    }

    while (!feof(fp)) {
        char start[] = "";
        char end[] = "";
        char weight[] = "";
        fscanf(fp, "%s %s %s", start, end, weight);
        int W = atoi(weight);
        //������� �𸣰��� weight�� corrupt �Ǿ��ٴµ�.. MAX ���� �ȵ��� 0�� ��; �׷��� �� �ؿ��� 0�̸� 999�� �ٲٰ� ��.
        //��. ���ʿ� ����� ������ �ȵǳ�. �����غ��ϱ�. �ֳĸ� ����� weight���� ������ 0�� �ƴ� �͵鸸 �����ϱ�..
        if (W != 0) {
            cost[atoi(start)][atoi(end)] = atoi(weight);
        }
    }

    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            if (cost[i][j] == 0) {
                cost[i][j] = MAX;
            }
            //printf("cost[%d][%d] = %d\n", i, j, cost[i][j]);
        }
    }

    allcosts(cost, distance, MAX_VERTICES);

    return 0;
}