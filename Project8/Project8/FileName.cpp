#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef struct _dnode
{
    int key;
    struct _dnode* prev;
    struct _dnode* next;
} dnode;

dnode* head, * tail;

void init_dlist(void)
{
    head = (dnode*)malloc(sizeof(dnode));
    tail = (dnode*)malloc(sizeof(dnode));
    head->next = tail;
    head->prev = head;
    tail->next = tail;
    tail->prev = head;
}

dnode* insert_dnode_ptr(int k, dnode* t)  /* insert k, before t */
{
    dnode* i;
    if (t == head)
        return NULL;
    i = (dnode*)malloc(sizeof(dnode));
    i->key = k;
    t->prev->next = i;
    i->prev = t->prev;
    t->prev = i;
    i->next = t;
    return i;
}

void print_dlist(dnode* p)
{
    printf("리스트 생성 완료!\n");
    printf("리스트 원소 : ");
    while (p != tail)
    {
        printf("%d ", p->key);
        p = p->next;
    }
    printf("\n");
}

void reverse_dlist(dnode* p) {
    dnode* t = p->next;
    p->prev = t; //head를 tail로
    p->next = p; 
    //printf("tail : %d, tail->next : %d, tail->prev: %d\n", p->key, p->next->key, p->prev->key); //확인용
    p = t;
    t = p->next;
    while (p != p->next) { //tail 전까지
        p->next = p->prev;
        p->prev = t;
        p = t;
        t = p->next;
    }
    p->next = p->prev; //tail을 head로
    p->prev = p;
    //printf("head : %d, head->next : %d, head->prev: %d\n", p->key, p->next->key, p->prev->key); //확인용

    printf("reverse_list 결과 : ");
    p = p->next;
    while (p != p->next) {
        printf("%d ", p->key);
        p = p->next;
    }
}

void main(void)
{
    int i;
    init_dlist();

    for (i = 1; i <= 10; i++) {
        insert_dnode_ptr(i, tail);

    }
    print_dlist(head->next);
    reverse_dlist(head);
    
}
