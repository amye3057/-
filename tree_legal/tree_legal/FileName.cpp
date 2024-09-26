#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
	int key;
	struct _node* left;
	struct _node* right;
}node;

node *head, *tail;

void init_tree() {
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->left = tail;
	head->right = tail;
	tail->left = tail;
	tail->right = tail;
}

int is_operator(int p) {
	return (p == '+' || p == '-' || p == '/' || p == '*');
}

int is_legal(char* s) {
	int f = 0;
	int a = 0;
	while (*s) {
		while (*s == ' ') s++;

		if (is_operator(*s)) {
			f--;
			//printf("���۷��̴���(%c), f = %d\n", *s, f); //Ȯ�ο�
		}
		else if (*s >= '0' && *s < '10') { //������ ���� \0�� ���� ��찡 �־ �̸� �����ϱ� ���� �߰��Ͽ���.
			f++;
			//printf("���۷��̴��ƴ�(%c), f = %d\n", *s, f); //Ȯ�ο�
		}
		
		if (f > 0 && a == 0) { //�� ó���� ���ڰ� ���� ��� �����Ŀ� �������� �����Ƿ� 0�� �����ϵ��� �Ѵ�.
			f = 0;
			break;
		}
		a++; //�� �Լ��� �ѹ��� ������ �Լ��� a++�� ���־���. �Լ��� ���ư��� ���� a++�� ��� �̷������ ������ �ణ ��ȿ�����̴�.
		s++;
	}
	return (f == 1); /* legal if operand-operator==1 */
}

void main(void) {
	char post[256];
	//init_stack(); ��� �ʿ� ���� �� ���Ƽ� �ϴ� ����
	//init_queue();
	init_tree();
	while (1) {
		printf("\nInput Prefix expression -> ");
		fgets(post, sizeof(post), stdin);
		if (*post == NULL) {
			printf("\nProgram ends...");
			exit(0);
		}
		if (!is_legal(post)) {
			printf("\nExpression is not legal.\n");
			continue;
		}
		else {
			printf("\nExpression is legal!\n");
			continue;
		}
	}
}