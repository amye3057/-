#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int key;
    struct _node* next;
} node;

node* init_list(void) {
    node* head = (node*)malloc(sizeof(node));
    node* tail = (node*)malloc(sizeof(node));
    // malloc이 NULL을 리턴할 경우 처리 방법은??
    head->next = tail;
    tail->next = tail;

    return head;
}

node* insert_after(int k, node* t) {
    node* s;
    if (!t || t->next == t) return t;
    s = (node*)malloc(sizeof(node));
    if (s == NULL) return s;
    while (t->next != t->next->next) { //리스트에 insert되는 순서대로 집어넣기 위해 항상 마지막 순서로 가도록.
        t = t->next;
    }
    s->key = k;
    s->next = t->next;
    t->next = s;
    return s;
}

void print_list(node* h) {
    if (h->next->next == h->next) { //리스트가 비어있을 경우
        printf("1");
    }
    else {
        printf("리스트 생성 완료! ");
        printf("(리스트 원소: ");
        int m = 1;
        h = h->next;
        while (h != h->next) {
            printf("%d ", h->key);
            m *= h->key;
            h = h->next;
        }
        printf(")");
        printf("\n원소들의 곱: %d\n", m);
    }
}

int main() {
    node* head = init_list();
    node* p;

    int n;
    int x;
    printf("원소의 개수를 입력하세요: ");
    scanf_s("%d", &n);
    if (n != 0) printf("숫자를 입력하세요: ");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &x);
        insert_after(x, head);
    }

    print_list(head);


    return 0;
}