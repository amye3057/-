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
			//printf("오퍼레이더임(%c), f = %d\n", *s, f); //확인용
		}
		else if (*s >= '0' && *s < '10') { //마지막 공백 \0이 들어가는 경우가 있어서 이를 방지하기 위해 추가하였다.
			f++;
			//printf("오퍼레이더아님(%c), f = %d\n", *s, f); //확인용
		}
		
		if (f > 0 && a == 0) { //맨 처음에 숫자가 들어올 경우 전위식에 적합하지 않으므로 0을 리턴하도록 한다.
			f = 0;
			break;
		}
		a++; //위 함수는 한번만 실행할 함수라서 a++을 해주었다. 함수가 돌아가는 동안 a++이 계속 이루어지기 때문에 약간 비효율적이다.
		s++;
	}
	return (f == 1); /* legal if operand-operator==1 */
}

void main(void) {
	char post[256];
	//init_stack(); 얘네 필요 없는 것 같아서 일단 없앰
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