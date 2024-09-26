#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <memory.h>
#define _CRT_SECURE_NO_WARNINGS
#define namesize 10
#define MAX 100000
int stack[MAX]; //char �ƴϸ� node*�� �ٲپ����
int top;

int add();
int print_s(), print_t(), print_tree(), save();

typedef struct _node{
	char name[namesize];
	struct _node* left;
	struct _node* right;
} node;

node* head, * tail;

void init_tree(void) {
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->left = tail;
	head->right = tail;
	tail->left = tail;
	tail->right = tail;
}

node* make_node(char v[], node* l, node* r) {
	node* n = (node*)malloc(sizeof(node*));
	n->left = l;
	n->right = r;
	strcpy(n->name, v);
	printf("���� �߰��� name�� %s. ->left = %s, ->right = %s\n", n->name, n->left->name, n->right->name);
	return n;
}

typedef struct _stack_node {
	//char key[namesize];
	struct node* nd;
	struct _stack_node* next;
}stack_node;

stack_node* h, * t;

void init_stack() {
	h = (stack_node*)malloc(sizeof(stack_node));
	t = (stack_node*)malloc(sizeof(stack_node));
	h->next = t;
	t->next = t;
}

void push(node* b/*char k[]*/) {
	stack_node* a;
	if ((a = (stack_node*)malloc(sizeof(stack_node))) == NULL) {
		printf("\nOut of memory");
		return -1;
	}
	//strcpy(a->key, k);
	a->nd = b;
	a->next = h->next;
	h->next = a;
}

void print_stack(stack_node*a) { //Ȯ�ο� �Լ�
	printf("stack: ");
	while (a != t) {
		printf("stack%s ", a);
		a = a->next;
	}
	printf("\n");
}

const char* pop() { //�̰� char�� ���ڿ� ��ȯ�� �ϰ� ������ ���� �ϳ��� ��ȯ�Ǿ.. ���ڿ� ��ȯ �˸� �� pop()!=/null ���� �Ǵ� �ǵ� ����� ����??
	stack_node* n;
	char popname[namesize];
	if (h->next == t) {
		printf("\nStack underflow");
		return t; //t?0? ������ ����?
	}
	/*n = h->next;
	strcpy(popname, n->key);
	h->next = n->next;
	free(n);*/
	//printf("pop %s", name); //Ȯ�ο�
	n = h->next;
	h->next = n->next;
	return n->nd/*popname*/;
}

//������ȸ �˻��Լ� (����Լ�)

node* pt_search(node* t, char n[]) {
	if (t != tail) {
		//printf("���� t�� name�� %s, ���ƾ��ϴ� ���� %s\n", t->name, n);
		if (strcmp(t->name, n) == 0) {
			//printf("t = %s ����!", t->name);
			return t;
		}
		//printf("pt_search �Ϸ�. �̸��� %s\n", t->name); //Ȯ��
		if (t->left != tail) {
			pt_search(t->left, n);
			//printf("pt_search(t->left)�Ϸ�. �̸��� %s\n", t->name);
		} //Ȯ��
		if (t->right != tail) {
			pt_search(t->right, n);
			//printf("pt_search(t->right)�Ϸ�. �̸��� %s\n", t->name);
		} //Ȯ��
	}
}

//������ȸ �˻��Լ� (������Լ�)
/*
node* pt_search(node* t, char n[]) {
	init_stack(); push(t->name);
	char popname[namesize];
	while (t=pop() != NULL) { //���� ����.. ����.. //strcpy(popname, pop()) != NULL
		//printf("pop %s", popname);
		if (strcmp(t->name, n) == 0) {
			printf("����!\n");
			return t;
		}
		print_stack(h->next); //Ȯ�ο�
		if (t->right != tail) {
			push(t->right->name);
			printf("%s�� right push %s\n\n", t->name, t->right->name);
		}
		if (t->left != tail) {
			push(t->left->name);
			printf("%s�� left push %s\n\n", t->name, t->left->name);
		}
		//printf("popname %s", popname);
	}
}*/


void pt_print(node* t) { //������ȸ ����Լ�
	printf("��");
	if (t != tail) {
		printf("%s ", t->name);
		pt_print(t->left);
		pt_print(t->right);
	}
}

int main() {
	FILE* fp;
	char filename[] = "a.dat";
	int run = 1;

	if ((fp = fopen(filename, "r+")) == NULL) {
		printf("���� ���� ����");
	}


	//�о���� �ؽ�Ʈ ������ Ʈ���� �����.
	init_tree();
	char root[namesize] = "";
	fscanf(fp, "%s",root);
	head->right = make_node(root, tail, tail);

	while (!feof(fp)) {
		node* t;
		char teacher[namesize] = "";
		char student[namesize] = "";
		fscanf(fp, "%s %s", &teacher, &student);
		printf("\n���� : %s, ���� : %s\n", teacher, student);
		t = pt_search(head->right, teacher);
		//Ȯ�ο�
		//printf("\n<<t = %s ", t->name);
		//printf("t->right = %s ", t->right->name);
		//printf("t->left = %s>>\n", t->left->name);

		if (t->left == tail) {
			t->left = make_node(student, tail, tail);
			//printf("%s -> left = %s\n", t->name, t->left->name);
		}
		else if (t->right == tail) {
			t->right = make_node(student, tail, tail);
			//printf("%s -> right = %s\n", t->name, t->right->name);
		}
		else {
			printf("Error! %s�� ���ڴ� �̹� 2�� �̻�. ���� ���� �ʿ�\n");
		}
	}
	pt_print(head->right);
	/*
	printf("C:> tree.exe %s", filename);
	while (run) {
		void rewind(FILE * stream); //�ʿ��Ѱ�?
		printf("> ��ȣ�� �����ϼ���(1: �߰� 2:������� 3:������� 4:�躸����� 5:���� 0:����): ");
		int a;
		scanf("%d", &a);
		getchar();
		switch (a) {
		case 1:
			//add();
			break;
		case 2:
			//print_s(fp);
			break;
		case 3:
			//print_t(fp);
			break;
		case 4:
			pt_print(head->right);
			break;
		case 5:
			//save();
			break;
		case 0:
			run = 0;
		}
	}
	*/
}

int add(){
	//���°� ���ڸ� �Է��Ѵ�. ������ ã�� ���� �Ǵ� ������ ���ڷ� �־��ش�. �Ѵ� ������ ��� ���ڸ� �޾��� �ڸ��� ���ٴ� ���� �޽����� ����.
}

int print_s(){
	//������ȸ
}

int print_t(){
	//��� 2����.
	//�ش� ������ ���� ������ ã�Ƴ�����.(������ 2.. �Ϸ��� ������ �̰� �迭�� �ƴϴϱ� �׷��Դ� ���ϰڱ�.) ���ÿ� �־���� ���� ����Ѵ�.
}

int print_tree(FILE *fp) {
	//������ȸ
	

}

int save(){
	//Ʈ���� �����Ѵ�.
}