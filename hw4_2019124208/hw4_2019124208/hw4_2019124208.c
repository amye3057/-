#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_LINE_SIZE 256
#define TABLE_SIZE 300
#define _CRT_SECURE_NO_WARNINGS

void init_hashtable(int* hashtable);
int get_data(FILE* f, char line[]);
int hash1(char str[]);
int hash2(char a[]);
int search(char email, int age);


struct people {
    char Fname[15];
    char Sname[15];
    char email[35];
    int age;
    char add[50];
} P[TABLE_SIZE];
//char hash_table[TABLE_SIZE][3];

//메인함수////////////////////////////////////////////
int main() {
    char L[MAX_LINE_SIZE];
    char filename[15] = "";
    char program[15] = "";
    int hashtable[TABLE_SIZE];

    while (1) {
        printf("C:> ");
        scanf_s("%s", &program, 15);
        getchar();
        scanf_s("%s", &filename, 15);

        FILE* file;
        // 파일 열기
        //file = fopen(filename, "r");
        fopen_s(&file, filename, "r");
        if (file == NULL) {
            printf("파일을 열 수 없습니다.");
            return 1;
        }

        get_data(file, L);

        if (strcmp(program,"hash.exe")==0) {

            while (1) {
                int n;
                char fname[15];
                char sname[15];
                char mail[35];
                int age;
                char add[50];
                printf("무엇을 원하십니까? 1:삽입 2:삭제 3:검색 4:종료 -> ");
                scanf_s("%s", &n);
                switch (n) {
                case 1:
                    printf("First name: ");
                    scanf_s("%s", &fname);
                    getchar();
                    printf("\nSecond name: ");
                    scanf_s("%s", &sname);
                    getchar();
                    printf("\n이메일: ");
                    scanf_s("%s", &mail);
                    getchar();
                    printf("\n나이: ");
                    scanf_s("%d", &age);
                    getchar();
                    printf("\n회사명: ");
                    scanf_s("%s", &add);
                    getchar();
                    int h = hash1(mail);
                    if (P[h].email != NULL) { //충돌이 발생할 경우->해쉬함수 h2 적용
                        h += hash2(age);
                    }
                    while (P[h].email != NULL) { //h2 적용 후에도 충돌이 발생할 경우->1씩 뒤로 이동
                        h++;
                    }
                    strcpy(P[h].Fname, fname);
                    strcpy(P[h].Sname, sname);
                    strcpy(P[h].email, mail);
                    strcpy(P[h].age, age);
                    strcpy(P[h].add, add);
                    printf("-> 데이터를 추가하였습니다.");
                    break;
                case 2:
                    printf("이메일: ");
                    scanf_s("%s", &mail);
                    printf("\n나이: ");
                    scanf_s("%d", &age);
                    int i = search(mail, age);
                    if (i == 0)
                        printf("데이터가 없습니다.");
                    else {
                        printf("-> 데이터를 삭제하였습니다: %s, %s, %s, %d, %s", P[i].Fname, P[i].Sname, P[i].email, P[i].age, P[i].add);
                        strcpy(P[h].Fname, NULL);
                        strcpy(P[h].Sname, NULL);
                        strcpy(P[h].email, NULL);
                        strcpy(P[h].age, NULL);
                        strcpy(P[h].add, NULL);
                    }
                    getchar();
                    break;
                case 3:
                    printf("이메일: ");
                    scanf_s("%s", &mail);
                    printf("\n나이: ");
                    scanf_s("%d", &age);
                    int i = search(mail, age);
                    if(i==0)
                        printf("데이터가 없습니다.");
                    else {
                        printf("-> 데이터를 찾았습니다: ");
                        printf("%s, %s, %s, %d, %s", P[i].Fname, P[i].Sname, P[i].email, P[i].age, P[i].add);
                    }
                    getchar();
                    break;
                case 4:
                    printf("-> Bye~");
                    return 0;
                }
            }
        }
        else {
            printf("해당 프로그램이 존재하지 않습니다.\n");
        }
    }

    return 0;
}


int search(char email, int age) {
    int h = h1(email);
    if (P[h].email != email) {
        h += h2(age);
    }
    while (P[h].email != email) {
        h++;
    }
    if (P[h].email != email) {
        return 0;
    }
    else {
        return h;
    }
}


int get_data(FILE* f, char line[]) {
    char* token;
    // 한 줄씩 파일 읽기
    while (fgets(line, MAX_LINE_SIZE, f) != NULL) {
        // 쉼표로 구분된 데이터 파싱
        int i = 1;
        int h;
        char fname[15];
        char sname[15];
        char email[35];
        char age[3];
        char add[50];
        token = strtok(line, ",");
        while (token != NULL) {
            // 데이터 출력 또는 원하는 작업 수행
            printf("%s ", token);
            if (i == 1) {
                strcpy(fname, token);
            }
            else if (i == 2) {
                strcpy(sname, token);
            }
            else if (i == 3) {
                strcpy(email, token);
            }
            else if (i == 4) {
                strcpy(age, token);
            }
            else if (i == 5) {
                strcpy(add, token);
            }
            // 다음 토큰으로 이동 (이전 토큰 다음부터 읽을 경우 첫 인자가 NULL임)
            token = strtok(NULL, ",");
            i++;
        }
        //여기다 해쉬함수 만들어서 name.csv 파일 적절하게 저장하는 것.. 을 구현하면 일단 반은 온거.
        h = hash1(email);
        if (P[h].email != NULL) { //충돌이 발생할 경우->해쉬함수 h2 적용
            h += hash2(age);
        }
        while (P[h].email != NULL) { //h2 적용 후에도 충돌이 발생할 경우->1씩 뒤로 이동
            h++;
        }
        strcpy(P[h].Fname, fname);
        strcpy(P[h].Sname, sname);
        strcpy(P[h].email, email);
        strcpy(P[h].age, age);
        strcpy(P[h].add, add);
        printf("\n");
    }

    // 파일 닫기
    fclose(f);
    printf("데이터를 모두 저장하였습니다.");
}


int hash1(char str[]) {
    int h;
    h = str[0] ^ (str[1] * str[1] + str[2]) % TABLE_SIZE;
    return h;
}

int hash2(char a[]) {
    int h;
    h = a[0] * a[1];
    return h;
}