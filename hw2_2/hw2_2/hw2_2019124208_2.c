#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	for (int i = 0; i < 3; i++) {
		s->key = k; //�ԷµǴ� ���Ҵ� ��� ���ڸ��� ������ ����.
	}
	while (t->next->next != t->next) { //t�� ���� ���Ұ� tail�� ������ �ڷ� ����.
		t = t->next;
	}
	s->next = t->next;
	t->next = s;
	return s;
}

void print_list(node* t) { //����Ʈ ���
	t = t->next;
	while (t->next != t->next->next) {
		printf("%c", t->key);
		printf(" -> ");
		t = t->next;
	}
		printf("%c", t->key);
}

int calc(node* t) {
	node* new = (node*)malloc(sizeof(node));
	//node* h = t; //head ����.. �ٵ� ��� �ɵ�? ������ ���ܿ� t=s �ƴѰ� ���Ƽ� t=h �־��µ� ���̾��.. �ϴ� �ּ�ó��.
	//t = h->next; //head �ں���. (head(s) -> (t))
	while (t->next!= t->next->next) { //���Ұ� �ϳ��� ���� ������ �ݺ�.
		int n = 0;
		node* s = t; //head
		t = t->next;
		printf("�ֱ׷�1.. t->key = %s\n",t->key); //Ȯ�ο�

		while (t->next->next->key > '0' && t->next->next->key < '10') { //���ӵ� ���� �ڷ� ���۷����Ͱ� ���� ������ �ڷ� ������
			s = t;
			t = t->next;
			printf("�ֱ׷�2"); //Ȯ�ο�

		}
		printf("�ֱ׷�3"); //Ȯ�ο�
		int a = atoi(&t->key);
		int b = atoi(&t->next->key);


		if (t->next->next->key == '+') {
			n = a + b;
		}
		else if (t->next->next->key == '-') {
			n = a - b;
		}
		else if (t->next->next->key == '*') {
			n = a * b;
			printf("n = %d * %d = %d\n", a, b, n); //Ȯ�ο�
		}
		new->key = n + '0'; //���ڷ� �ٽ� ��ȯ�Ͽ� ����. �ϴ� ����!!!!!!!!
		printf("n�� new�� �����~ n�� %d�� new�� %c(%d)���� n�� ���ڷ� �ٲٸ� %c\n", n, new->key, new->key, n+'0'); //�� �̷�? Ȯ�ο�
		s->next = new;
		new->next = t->next->next->next;
		print_list(s); //Ȯ�ο�
		printf("\n"); //Ȯ�ο�

		//free(t);
		t = new; //�ݺ����� ������ �ʵ���
		printf("t���� ���� %c(%d)�� ����־��~\n", t->key, t->key); //Ȯ�ο�

	}
	free(t);
	printf("�ݺ��� ����.");
	return atoi(new->key);
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
		if (a[i] != ' ') { //������ �ƴ� ��쿡�� list�� �߰� //�������� �Էµ� �α��� �� �� �ֵ���..
			insert(a[i], h);
		}
	}
	
	printf("�ܼ� ���� ����Ʈ�� ���� �����Ͽ����ϴ�: ");
	print_list(h);
	printf("\n");
	printf("�� ���� ��� ����� %d �Դϴ�.", calc(h));
}