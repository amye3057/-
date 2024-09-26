#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <memory.h>
#define _CRT_SECURE_NO_WARNINGS
#define namesize 10
#define MAX 100000
int stack[MAX]; //char 아니면 node*로 바꾸어야함
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
	printf("새로 추가된 name은 %s. ->left = %s, ->right = %s\n", n->name, n->left->name, n->right->name);
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

void print_stack(stack_node*a) { //확인용 함수
	printf("stack: ");
	while (a != t) {
		printf("stack%s ", a);
		a = a->next;
	}
	printf("\n");
}

const char* pop() { //이걸 char로 문자열 반환을 하고 싶은데 문자 하나만 반환되어서.. 문자열 반환 알면 걍 pop()!=/null 저거 되는 건데 방법이 없나??
	stack_node* n;
	char popname[namesize];
	if (h->next == t) {
		printf("\nStack underflow");
		return t; //t?0? 무엇을 리턴?
	}
	/*n = h->next;
	strcpy(popname, n->key);
	h->next = n->next;
	free(n);*/
	//printf("pop %s", name); //확인용
	n = h->next;
	h->next = n->next;
	return n->nd/*popname*/;
}

//전위순회 검색함수 (재귀함수)

node* pt_search(node* t, char n[]) {
	if (t != tail) {
		//printf("현재 t의 name은 %s, 같아야하는 것은 %s\n", t->name, n);
		if (strcmp(t->name, n) == 0) {
			//printf("t = %s 동일!", t->name);
			return t;
		}
		//printf("pt_search 완료. 이름은 %s\n", t->name); //확인
		if (t->left != tail) {
			pt_search(t->left, n);
			//printf("pt_search(t->left)완료. 이름은 %s\n", t->name);
		} //확인
		if (t->right != tail) {
			pt_search(t->right, n);
			//printf("pt_search(t->right)완료. 이름은 %s\n", t->name);
		} //확인
	}
}

//전위순회 검색함수 (비재귀함수)
/*
node* pt_search(node* t, char n[]) {
	init_stack(); push(t->name);
	char popname[namesize];
	while (t=pop() != NULL) { //여기 내부.. 수정.. //strcpy(popname, pop()) != NULL
		//printf("pop %s", popname);
		if (strcmp(t->name, n) == 0) {
			printf("동일!\n");
			return t;
		}
		print_stack(h->next); //확인용
		if (t->right != tail) {
			push(t->right->name);
			printf("%s의 right push %s\n\n", t->name, t->right->name);
		}
		if (t->left != tail) {
			push(t->left->name);
			printf("%s의 left push %s\n\n", t->name, t->left->name);
		}
		//printf("popname %s", popname);
	}
}*/


void pt_print(node* t) { //전위순회 출력함수
	printf("전");
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
		printf("파일 열기 실패");
	}


	//읽어들인 텍스트 파일을 트리로 만든다.
	init_tree();
	char root[namesize] = "";
	fscanf(fp, "%s",root);
	head->right = make_node(root, tail, tail);

	while (!feof(fp)) {
		node* t;
		char teacher[namesize] = "";
		char student[namesize] = "";
		fscanf(fp, "%s %s", &teacher, &student);
		printf("\n스승 : %s, 제자 : %s\n", teacher, student);
		t = pt_search(head->right, teacher);
		//확인용
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
			printf("Error! %s의 제자는 이미 2명 이상. 파일 수정 필요\n");
		}
	}
	pt_print(head->right);
	/*
	printf("C:> tree.exe %s", filename);
	while (run) {
		void rewind(FILE * stream); //필요한가?
		printf("> 번호를 선택하세요(1: 추가 2:제자출력 3:스승출력 4:계보도출력 5:저장 0:종료): ");
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
	//스승과 제자를 입력한다. 스승을 찾고 왼쪽 또는 오른쪽 제자로 넣어준다. 둘다 차있을 경우 제자를 받아줄 자리가 없다는 오류 메시지를 띄운다.
}

int print_s(){
	//중위순회
}

int print_t(){
	//방법 2가지.
	//해당 노드부터 그의 스승을 찾아나간다.(나누기 2.. 하려고 했으나 이건 배열이 아니니까 그렇게는 못하겠군.) 스택에 넣어놓고 전부 출력한다.
}

int print_tree(FILE *fp) {
	//전위순회
	

}

int save(){
	//트리를 저장한다.
}