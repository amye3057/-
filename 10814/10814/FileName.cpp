#include <stdio.h>
#include <stdlib.h>
#define NAME_SIZE 101
#define AGE_SIZE 4 // 1~200���̹Ƿ� 3�ڸ� + ���Ṯ�� \0 1�ڸ�

typedef struct node {
	int age;
	char name[NAME_SIZE];
	struct node* next;
} person;

person* head, *tail;

void init_person(void) {
	head = (person*)malloc(sizeof(person));
	tail = (person*)malloc(sizeof(person));
	head->next = tail;
	tail->next = tail;
}

void input(person *h) {
	
	scanf_s("%d", &h->age);
	fgets(h->name, AGE_SIZE, stdin);
}

int main() {
	int n;
	char arr[100000][101] = {};
	scanf("%d", &n);

	init_person(); // ����Ʈ ����
	person* head = (person*)malloc(sizeof(person)); // ��带 ó���� �����ϴ� �� �´���??
	for (int i = 0; i < n; i++) {
		input(head);
	}

}