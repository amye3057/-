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
    // malloc�� NULL�� ������ ��� ó�� �����??
    head->next = tail;
    tail->next = tail;

    return head;
}

node* insert_after(int k, node* t) {
    node* s;
    if (!t || t->next == t) return t;
    s = (node*)malloc(sizeof(node));
    if (s == NULL) return s;
    while (t->next != t->next->next) { //����Ʈ�� insert�Ǵ� ������� ����ֱ� ���� �׻� ������ ������ ������.
        t = t->next;
    }
    s->key = k;
    s->next = t->next;
    t->next = s;
    return s;
}

void print_list(node* h) {
    if (h->next->next == h->next) { //����Ʈ�� ������� ���
        printf("1");
    }
    else {
        printf("����Ʈ ���� �Ϸ�! ");
        printf("(����Ʈ ����: ");
        int m = 1;
        h = h->next;
        while (h != h->next) {
            printf("%d ", h->key);
            m *= h->key;
            h = h->next;
        }
        printf(")");
        printf("\n���ҵ��� ��: %d\n", m);
    }
}

int main() {
    node* head = init_list();
    node* p;

    int n;
    int x;
    printf("������ ������ �Է��ϼ���: ");
    scanf_s("%d", &n);
    if (n != 0) printf("���ڸ� �Է��ϼ���: ");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &x);
        insert_after(x, head);
    }

    print_list(head);


    return 0;
}