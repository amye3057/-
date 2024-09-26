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

int min_element(node* h) {
    h = h->next; //head 다음부터 원소가 있다. 이 코드를 빼놓으면 min 값에 마이너스 값이 들어가버린다. 주의!
    int min = 999999; //원소의 크기는 모두 999999 이하로 가정
    while (h != h->next) {
        if (h->key < min) {
            min = h->key;
        }
        h = h->next;
    }
    return min;
}

void print_list(node* h) {
    if (h->next->next == h->next) { //리스트가 비어있을 경우
        printf("-999999");
    }
    else {
        printf("리스트 생성 완료!\n");
        printf("리스트 원소: ");
        int sum = 0;
        h = h->next;
        while (h != h->next) {
            printf("%d ", h->key);
            sum += h->key;
            h = h->next;
        }
        printf("\n원소들의 합: %d\n", sum);
    }
}

int main() {
    node* head = init_list();
    node* p;
    insert_after(4, head);
    insert_after(3, head);
    insert_after(6, head);
    insert_after(1, head);

    print_list(head);
    int min = min_element(head);
    printf("가장 작은 원소: %d", min);

    return 0;
}