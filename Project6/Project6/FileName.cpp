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

int min_element(node* h) {
    h = h->next; //head �������� ���Ұ� �ִ�. �� �ڵ带 �������� min ���� ���̳ʽ� ���� ��������. ����!
    int min = 999999; //������ ũ��� ��� 999999 ���Ϸ� ����
    while (h != h->next) {
        if (h->key < min) {
            min = h->key;
        }
        h = h->next;
    }
    return min;
}

void print_list(node* h) {
    if (h->next->next == h->next) { //����Ʈ�� ������� ���
        printf("-999999");
    }
    else {
        printf("����Ʈ ���� �Ϸ�!\n");
        printf("����Ʈ ����: ");
        int sum = 0;
        h = h->next;
        while (h != h->next) {
            printf("%d ", h->key);
            sum += h->key;
            h = h->next;
        }
        printf("\n���ҵ��� ��: %d\n", sum);
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
    printf("���� ���� ����: %d", min);

    return 0;
}