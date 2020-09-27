// ==================================================================

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// ==================================================================

//    queue q를 초기화한다.
void init_queue(QUEUE* q) {
    q->front = 0;
    q->rear  = 0;
}

// queue q에 저장된 데이터를 출력한다.
// 출력 형식은 (f|n|n:i1, i2,...,in)이다. 
// 여기서 f는 front index, r은 rear index, n은 queue q에 저장된
// item의 개수이고, i1, i2,..,in 은 front에서 rear 순서로 각 item이다.
int queue_length(QUEUE* q) {
    if(q->rear < q->front)  return (q->rear+MAX_QUEUE_SIZE - q->front);
    else                    return (q->rear - q->front);
}

void print_queue(QUEUE* q) {
    if(empty_queue(q)) {
        printf("(%d|%d|%d:)\n", q->front, q->rear, queue_length(q));
    }
    else {
        printf("(%d|%d|%d:", q->front, q->rear, queue_length(q));
        for(int i=(q->front+1)%MAX_QUEUE_SIZE; i != q->rear; i = (i+1)%MAX_QUEUE_SIZE) {
            printf("%d,", q->data[i] );
        }
        printf("%d)\n", q->data[q->rear]);
    }
}

int empty_queue(QUEUE* q) {
    if(q->front == q->rear) return 1;
    else                    return 0;
}

int full_queue(QUEUE* q) {
    if(q->front == (q->rear+1)%MAX_QUEUE_SIZE)  return 1;
    else                                        return 0;
}

// return index of rear
int en_queue(QUEUE* q, int item) {
    if(full_queue(q)) return ERROR;
    else {
        q->rear = (q->rear+1)%MAX_QUEUE_SIZE;
        q->data[q->rear] = item;
        return q->rear;
    }
}

// 하나의 item을 제거한 후 return 한다.
int de_queue(QUEUE* q) {
    if(empty_queue(q)) return ERROR;
    else {
        q->front = (q->front+1)%MAX_QUEUE_SIZE;
        return q->data[q->front];
    }
}

// ==================================================================