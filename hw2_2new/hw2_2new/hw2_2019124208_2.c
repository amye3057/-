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

node* insert(char k, node* t) { // 가장 맨 끝에 원소 추가
	node* s;
	if (!t || t->next == t)
		return t;
	s = (node*)malloc(sizeof(node));
	//strcpy_s(s->key, strlen(k), s); //받은 원소를 key에 입력
	while (t->next->next != t->next) { //t의 다음 원소가 tail일 때까지 뒤로 간다.
		t = t->next;
	}
	s->key = k;
	s->next = t->next;
	t->next = s;
	return s;
}

void print_list(node* t) { //리스트 출력
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
	node* h = t; //head 고정.
	t = h->next; //head 뒤부터. (head(s) -> (t))
	int n = 0;
	while (t->next != t->next->next) { //원소가 하나만 남을 때까지 반복.
		node* s = h; //head
		while (t->next->next->key > '0' && t->next->next->key < '10') { //연속된 숫자 뒤로 오퍼레이터가 나올 때까지 뒤로 보내기
			s = t;
			t = t->next;
		}
		int a;
		if (t->key == 'n') { //n이라는 문자가 들어가 있을 시 정수형 선언한 n값을 가져와서 계산.
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

		new->key = 'n'; //char로 원소를 넣다보니까 연산 후에 두자리 수 이상이 되면 값이 제대로 들어가지 않는 문제점이 있어서 배열로 원소가 들어갈 수 있게 만들다가,
		//그냥 리스트에서 n이라는 문자가 나올 시 저장된 값 int형 n을 꺼내와서 연산하도록 만들었다.
		s->next = new;
		new->next = t->next->next->next;
		//print_list(s); //확인용
		//printf("\n"); //확인용

		//free(t);
		t = new; //반복문이 깨지지 않도록
	}
	free(t);
	return n;
}
/*t와 t->next, t->next->next가 숫자면 t를 한 칸 뒤로 보낸다.
t와 t->next가 숫자고 뒤가 오퍼레이터면 t와 t->next를 계산 후(x)
오퍼레이터 뒤에 새로운 노드(x)를 추가한 다음 앞의 노드를 모두 제거한다. t는 맨앞으로 옮기고 계속 반복하면.. 되겠다
*/

int main() {
	node* h = init_list(); //리스트 생성
	char a[100] = { 0 };
	printf("> 후위식을 입력하세요. ");

scanf_s("%[^\n]s", &a, 100); //공백을 포함한 문자열을 받기 위해 %[^\n]s 사용

	for (int i = 0; i < strlen(a); i++) {
		if (a[i] != ' ') { //공백이 아닌 경우에만 list에 추가
			char b;
			int j = 0;
			b = a[i];
			insert(b, h);
		}
	}

	printf("단순 연결 리스트에 식을 저장하였습니다: ");
	print_list(h);
	printf("\n");
	printf("이 식의 계산 결과는 %d 입니다.", calc(h));
}