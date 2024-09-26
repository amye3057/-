#include <stdio.h>
#include <stdlib.h>
typedef struct _node {
	int key;
	struct _node* next;
} node;
node* init_list(void) {
	node* head, * tail;
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->next = tail;
	tail->next = tail;
	return head;
}
node* insert(node* head, int k) {
	node* s;
	s = (node*)malloc(sizeof(node));
	s->key = k;
	s->next = head->next;
	head->next = s;
	return s;
}
void print_list(node* head) {
	node* t = head->next;
	while (t->next != t) {
		printf("%d ", t->key);
		t = t->next;
	}
	printf("\n");
}

node* split(node* a, node* b) {
	//int aa = a->key; //왼쪽 축값
	node* bb = b; //가장 오른쪽 값 빼둠
	int n = b->key; //축값
	int j = n - 1;
	int t;
	while (1) {
		while (a->key < n) a = a->next;
		while (b->key > n && a != b) { //기존 함수를 수정하지 말라고 해서 prev를 추가하려다가 이런 방식을 채택.
			node* c = a;
			while (c->next != b)
				c = c->next;
			b = c;
		}
		if (a == b || b->next==a) break;
		t = a->key;
		a->key = b->key;
		b->key = t;
	}
	t = a->key;
	a->key = bb->key;
	bb->key = t;
	return a->next;
}

void quick_sort(node* lst) {
	node* lst2;
	lst2 = lst->next;
	while (lst2->next->key > -1) { //lst2->next!=NULL로 줬는데 안된다. 
		lst2 = lst2->next; //가장 오른쪽 값
	}
	lst2 = split(lst, lst2); //추가
	quick_sort(lst);
	quick_sort(lst2);
}
void main(void)
{
	node* t;
	node* lst = init_list();
	t = lst;
	for (int i = 0; i < 30; i++)
		insert(lst, rand() % 731);
	printf("Initial Linked list is \n");
	print_list(lst);
	quick_sort(t->next);
	printf("\nSorted Linked list is \n");
	print_list(t);
}