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

//�����Լ�////////////////////////////////////////////
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
        // ���� ����
        //file = fopen(filename, "r");
        fopen_s(&file, filename, "r");
        if (file == NULL) {
            printf("������ �� �� �����ϴ�.");
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
                printf("������ ���Ͻʴϱ�? 1:���� 2:���� 3:�˻� 4:���� -> ");
                scanf_s("%s", &n);
                switch (n) {
                case 1:
                    printf("First name: ");
                    scanf_s("%s", &fname);
                    getchar();
                    printf("\nSecond name: ");
                    scanf_s("%s", &sname);
                    getchar();
                    printf("\n�̸���: ");
                    scanf_s("%s", &mail);
                    getchar();
                    printf("\n����: ");
                    scanf_s("%d", &age);
                    getchar();
                    printf("\nȸ���: ");
                    scanf_s("%s", &add);
                    getchar();
                    int h = hash1(mail);
                    if (P[h].email != NULL) { //�浹�� �߻��� ���->�ؽ��Լ� h2 ����
                        h += hash2(age);
                    }
                    while (P[h].email != NULL) { //h2 ���� �Ŀ��� �浹�� �߻��� ���->1�� �ڷ� �̵�
                        h++;
                    }
                    strcpy(P[h].Fname, fname);
                    strcpy(P[h].Sname, sname);
                    strcpy(P[h].email, mail);
                    strcpy(P[h].age, age);
                    strcpy(P[h].add, add);
                    printf("-> �����͸� �߰��Ͽ����ϴ�.");
                    break;
                case 2:
                    printf("�̸���: ");
                    scanf_s("%s", &mail);
                    printf("\n����: ");
                    scanf_s("%d", &age);
                    int i = search(mail, age);
                    if (i == 0)
                        printf("�����Ͱ� �����ϴ�.");
                    else {
                        printf("-> �����͸� �����Ͽ����ϴ�: %s, %s, %s, %d, %s", P[i].Fname, P[i].Sname, P[i].email, P[i].age, P[i].add);
                        strcpy(P[h].Fname, NULL);
                        strcpy(P[h].Sname, NULL);
                        strcpy(P[h].email, NULL);
                        strcpy(P[h].age, NULL);
                        strcpy(P[h].add, NULL);
                    }
                    getchar();
                    break;
                case 3:
                    printf("�̸���: ");
                    scanf_s("%s", &mail);
                    printf("\n����: ");
                    scanf_s("%d", &age);
                    int i = search(mail, age);
                    if(i==0)
                        printf("�����Ͱ� �����ϴ�.");
                    else {
                        printf("-> �����͸� ã�ҽ��ϴ�: ");
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
            printf("�ش� ���α׷��� �������� �ʽ��ϴ�.\n");
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
    // �� �پ� ���� �б�
    while (fgets(line, MAX_LINE_SIZE, f) != NULL) {
        // ��ǥ�� ���е� ������ �Ľ�
        int i = 1;
        int h;
        char fname[15];
        char sname[15];
        char email[35];
        char age[3];
        char add[50];
        token = strtok(line, ",");
        while (token != NULL) {
            // ������ ��� �Ǵ� ���ϴ� �۾� ����
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
            // ���� ��ū���� �̵� (���� ��ū �������� ���� ��� ù ���ڰ� NULL��)
            token = strtok(NULL, ",");
            i++;
        }
        //����� �ؽ��Լ� ���� name.csv ���� �����ϰ� �����ϴ� ��.. �� �����ϸ� �ϴ� ���� �°�.
        h = hash1(email);
        if (P[h].email != NULL) { //�浹�� �߻��� ���->�ؽ��Լ� h2 ����
            h += hash2(age);
        }
        while (P[h].email != NULL) { //h2 ���� �Ŀ��� �浹�� �߻��� ���->1�� �ڷ� �̵�
            h++;
        }
        strcpy(P[h].Fname, fname);
        strcpy(P[h].Sname, sname);
        strcpy(P[h].email, email);
        strcpy(P[h].age, age);
        strcpy(P[h].add, add);
        printf("\n");
    }

    // ���� �ݱ�
    fclose(f);
    printf("�����͸� ��� �����Ͽ����ϴ�.");
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