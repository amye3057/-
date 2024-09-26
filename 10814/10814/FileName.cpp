#include <stdio.h>
#include <stdlib.h>
#define NAME_SIZE 101
#define AGE_SIZE 4 // 1~200살이므로 3자리 + 종결문자 \0 1자리

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

	init_person(); // 리스트 생성
	person* head = (person*)malloc(sizeof(person)); // 헤드를 처음에 선언하는 게 맞던가??
	for (int i = 0; i < n; i++) {
		input(head);
	}

}