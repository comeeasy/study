// ==================================================================

#define MAX_QUEUE_SIZE  8
#define ERROR           -1

// ==================================================================

typedef struct queue {
    int data[MAX_QUEUE_SIZE];
    int front, rear;
} QUEUE;

// ==================================================================

void init_queue(QUEUE* q);
void print_queue(QUEUE* q);
int empty_queue(QUEUE* q);
int full_queue(QUEUE* q);
int en_queue(QUEUE* q, int item);
int de_queue(QUEUE* q);

// ==================================================================