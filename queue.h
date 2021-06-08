#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define QUEUE_IS_EMPTY 1
#define QUEUE_IS_FULL 2
#define NO_SUCH_ELEMENT_IN_QUEUE -1
#define SIZE 10 //fixed size, suppose equals 3 elements

typedef struct queue{
    int* data; // array for storing int elements
    int i; // number of stored elements in the queue
    int idxIn; // index to put element in
} queue_t;

void init(queue_t* q);
int enqueue(queue_t* q, int val);
int dequeue(queue_t* q, int* val);
bool is_empty(queue_t* q);

#endif // QUEUE_H
