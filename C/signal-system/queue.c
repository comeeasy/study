#include "queue.h"

//================================================

Node* make_node(element elem) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL) {
        printf("Out of memory in make_node function\n");
        return NULL;
    }

    new_node->elem = elem;
    new_node->next = NULL;

    return new_node;    
}

void delete_node(Node* del) {free(del);}

//================================================

Queue* init_queue(Queue* q) {
    q = (Queue*)malloc(sizeof(Queue));

    q->front = NULL;
    q->rear  = NULL;
    q->n = 0;

    printf("queue is initialized\n");

    return q;
}

void enqueue(Queue* q, element elem) {
    Node* tmp;

    if(q->front == NULL) {
        q->front = make_node(elem);
        q->rear = q->front;
        q->n++;
    }     
    else {
        tmp = make_node(elem);
        q->rear->next = tmp;
        q->rear = tmp;
        q->n++;
    }

    printf("elem %c is enqueued\n", elem);
    printf("size of queue is %d\n", q->n);
}

element dequeue(Queue* q) {
    element tmp;
    Node* del;

    if(q->n == 0) {
        printf("queue is empty\n");
        return (element)'\0';
    }

    tmp = q->front->elem;
    del = q->front;
    q->front = q->front->next;
    delete_node(del);
    q->n--;

    if(q->front == NULL) q->rear = NULL;

    return tmp;
}

void delete_queue(Queue* q) {
    for(int i=0; i<q->n; ++i) {
        dequeue(q);
    }
}