#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct _node* nodeptr;
typedef struct _node {
    int val;
    nodeptr next;
} node;

typedef struct {
    nodeptr head;
    nodeptr tail;
    nodeptr rear;
} queue;

queue* create_queue() {
    queue* q = (queue*)malloc(sizeof(queue));
    q->head = (node*)malloc(sizeof(node));
    q->tail = (node*)malloc(sizeof(node));
    q->rear = q->head;
    q->head->next = q->tail;   // q->head->next 가 q->tail이면 empty
    q->tail->next = q->tail;
    return q;
}

void clear_queue(queue* q) {
    nodeptr t;
    nodeptr s;
    t = q->head->next;
    while (t != q->tail) {
        s = t;
        t = t->next;
        free(s);
    }
    q->head->next = q->tail;
}




int put(queue* q, int k) //rear 뒤에 노드 삽입
{
    nodeptr p;
    if ((p = (node*)malloc(sizeof(node)))==NULL) { //꽉 참
        printf("\n Out of memory.");
        return -1; //실패
    }
    p->val = k;
    p->next = q->rear->next;
    q->rear->next = p;
    q->rear = p; // rear 뒤로 이동
    return k;
}

int get(queue* q) {
    int i;
    node* p;
    p = q->head->next;
    if (p == q->tail) { //비어있음
        printf("\n Queue Underflow.");
            return -1;
    }
    i = p->val;
    q->head->next = p->next;
    free(p);
    return i;
}

void print_queue(queue* q) {
    node* p;
    printf("\n  Queue contents : Front ----> Rear\n");
    for (p = q->head->next; p != q->tail; p = p->next)
        printf("%-6d", p->val);
}

void main(void) {
    int i;
    queue* q = create_queue();
    printf("\nPut5, 4, 7, 8, 2, 1");
    put(q, 5); put(q, 4); put(q, 7);
    put(q, 8); put(q, 2); put(q, 1);
    print_queue(q);
    printf("\nGet"); i = get(q);
    print_queue(q);
    printf("\n   getting value is %d", i);
    printf("\nPut3, 2, 5, 7");
    put(q, 3); put(q, 2); put(q, 5); put(q, 7);
    print_queue(q);
    printf("\nNowqueue is full, put 3");
    put(q, 3);
    print_queue(q);
    printf("\nInitializequeue");
    clear_queue(q);
    print_queue(q);
    printf("\nNowqueue is empty, get");
    i = get(q);
    print_queue(q);
    printf("\n   getting value is %d\n", i);
}

