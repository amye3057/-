#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_VERTICES 7
#define MAX 999


void allcosts(int cost[][MAX_VERTICES], //<-난 여기 왜 MAX_VERTICES가 들어가는지도 모르겠다 배열 안에 들어가는 값 아닌가? 이걸 왜 배열 인덱스에다 집어넣는겨
    int distance[][MAX_VERTICES], int n) {
    /* 각 정점에서 다른 모든 정점으로의 거리 계산,cost:인접 행렬, distance:거리값*/
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
            else if (i==j) { //자기자신
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
        printf("파일 열기 실패");
    }

    while (!feof(fp)) {
        char start[] = "";
        char end[] = "";
        char weight[] = "";
        fscanf(fp, "%s %s %s", start, end, weight);
        int W = atoi(weight);
        //여기부터 모르겠으 weight가 corrupt 되었다는데.. MAX 값이 안들어가고 0이 들어감; 그래서 걍 밑에서 0이면 999로 바꾸게 함.
        //아. 애초에 여기다 넣으면 안되네. 생각해보니까. 왜냐면 여기는 weight값이 무조건 0이 아닌 것들만 있으니까..
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