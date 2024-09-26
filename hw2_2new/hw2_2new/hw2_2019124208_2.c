#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

typedef struct _node* ndptr;
typedef struct _node {
	char key;
	ndptr next;
} node;

node head;

node* init_list(void) {
	node* head = (node*)malloc(sizeof(node));
	node* tail = (node*)malloc(sizeof(node));
	head->next = tail;
	tail->next = tail;

	return head;
}

node* insert(char k, node* t) { // ���� �� ���� ���� �߰�
	node* s;
	if (!t || t->next == t)
		return t;
	s = (node*)malloc(sizeof(node));
	//strcpy_s(s->key, strlen(k), s); //���� ���Ҹ� key�� �Է�
	while (t->next->next != t->next) { //t�� ���� ���Ұ� tail�� ������ �ڷ� ����.
		t = t->next;
	}
	s->key = k;
	s->next = t->next;
	t->next = s;
	return s;
}

void print_list(node* t) { //����Ʈ ���
	t = t->next;
	while (t->next != t->next->next) {
		int i = 0;
		printf("%c", t->key);
		i++;
		printf(" -> ");
		t = t->next;
	}
	int i = 0;
	printf("%c", t->key);
	i++;
}

int calc(node* t) {
	node* new = (node*)malloc(sizeof(node));
	node* h = t; //head ����.
	t = h->next; //head �ں���. (head(s) -> (t))
	int n = 0;
	while (t->next != t->next->next) { //���Ұ� �ϳ��� ���� ������ �ݺ�.
		node* s = h; //head
		while (t->next->next->key > '0' && t->next->next->key < '10') { //���ӵ� ���� �ڷ� ���۷����Ͱ� ���� ������ �ڷ� ������
			s = t;
			t = t->next;
		}
		int a;
		if (t->key == 'n') { //n�̶�� ���ڰ� �� ���� �� ������ ������ n���� �����ͼ� ���.
			a = n;
		}
		else {
			a = atoi(&t->key);
		}
		int b = atoi(&t->next->key);
		
		if (t->next->next->key == '+') {
			n = a + b;
		}
		else if (t->next->next->key == '-') {
			n = a - b;
		}
		else if (t->next->next->key == '*') {
			n = a * b;
		}

		new->key = 'n'; //char�� ���Ҹ� �ִٺ��ϱ� ���� �Ŀ� ���ڸ� �� �̻��� �Ǹ� ���� ����� ���� �ʴ� �������� �־ �迭�� ���Ұ� �� �� �ְ� ����ٰ�,
		//�׳� ����Ʈ���� n�̶�� ���ڰ� ���� �� ����� �� int�� n�� �����ͼ� �����ϵ��� �������.
		s->next = new;
		new->next = t->next->next->next;
		//print_list(s); //Ȯ�ο�
		//printf("\n"); //Ȯ�ο�

		//free(t);
		t = new; //�ݺ����� ������ �ʵ���
	}
	free(t);
	return n;
}
/*t�� t->next, t->next->next�� ���ڸ� t�� �� ĭ �ڷ� ������.
t�� t->next�� ���ڰ� �ڰ� ���۷����͸� t�� t->next�� ��� ��(x)
���۷����� �ڿ� ���ο� ���(x)�� �߰��� ���� ���� ��带 ��� �����Ѵ�. t�� �Ǿ����� �ű�� ��� �ݺ��ϸ�.. �ǰڴ�
*/

int main() {
	node* h = init_list(); //����Ʈ ����
	char a[100] = { 0 };
	printf("> �������� �Է��ϼ���. ");

scanf_s("%[^\n]s", &a, 100); //������ ������ ���ڿ��� �ޱ� ���� %[^\n]s ���

	for (int i = 0; i < strlen(a); i++) {
		if (a[i] != ' ') { //������ �ƴ� ��쿡�� list�� �߰�
			char b;
			int j = 0;
			b = a[i];
			insert(b, h);
		}
	}

	printf("�ܼ� ���� ����Ʈ�� ���� �����Ͽ����ϴ�: ");
	print_list(h);
	printf("\n");
	printf("�� ���� ��� ����� %d �Դϴ�.", calc(h));
}