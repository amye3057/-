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

node* insert(char k, node* t) { // 가장 맨 끝에 원소 추가
	node* s;
	if (!t || t->next == t)
		return t;
	s = (node*)malloc(sizeof(node));
	for (int i = 0; i < 3; i++) {
		s->key = k; //입력되는 원소는 모두 한자리인 것으로 설정.
	}
	while (t->next->next != t->next) { //t의 다음 원소가 tail일 때까지 뒤로 간다.
		t = t->next;
	}
	s->next = t->next;
	t->next = s;
	return s;
}

void print_list(node* t) { //리스트 출력
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
	//node* h = t; //head 고정.. 근데 없어도 될듯? 마지막 문단에 t=s 아닌거 같아서 t=h 넣었는데 차이없어서.. 일단 주석처리.
	//t = h->next; //head 뒤부터. (head(s) -> (t))
	while (t->next!= t->next->next) { //원소가 하나만 남을 때까지 반복.
		int n = 0;
		node* s = t; //head
		t = t->next;
		printf("왜그래1.. t->key = %s\n",t->key); //확인용

		while (t->next->next->key > '0' && t->next->next->key < '10') { //연속된 숫자 뒤로 오퍼레이터가 나올 때까지 뒤로 보내기
			s = t;
			t = t->next;
			printf("왜그래2"); //확인용

		}
		printf("왜그래3"); //확인용
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
			printf("n = %d * %d = %d\n", a, b, n); //확인용
		}
		new->key = n + '0'; //문자로 다시 변환하여 넣음. 일단 보류!!!!!!!!
		printf("n이 new에 들어갔어요~ n은 %d고 new는 %c(%d)에요 n을 문자로 바꾸면 %c\n", n, new->key, new->key, n+'0'); //왜 이럼? 확인용
		s->next = new;
		new->next = t->next->next->next;
		print_list(s); //확인용
		printf("\n"); //확인용

		//free(t);
		t = new; //반복문이 깨지지 않도록
		printf("t에는 현재 %c(%d)가 들어있어요~\n", t->key, t->key); //확인용

	}
	free(t);
	printf("반복문 깨짐.");
	return atoi(new->key);
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
		if (a[i] != ' ') { //공백이 아닌 경우에만 list에 추가 //수정하자 입력도 두글자 들어갈 수 있도록..
			insert(a[i], h);
		}
	}
	
	printf("단순 연결 리스트에 식을 저장하였습니다: ");
	print_list(h);
	printf("\n");
	printf("이 식의 계산 결과는 %d 입니다.", calc(h));
}