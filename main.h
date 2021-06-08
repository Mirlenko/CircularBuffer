#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>

#define QUEUE_IS_EMPTY 1
#define QUEUE_IS_FULL 2
#define ELEMENT_NOT_FOUND -1
#define SIZE 5

typedef struct queue{
    int* data; // array for storing int elements
    int i; // number of stored elements in the queue
    int idxIn; // index to put element in
} queue_t;

void init(queue_t* q);
int enqueue(queue_t* q, int val);
int dequeue(queue_t* q, int* val);
bool is_empty(queue_t* q);

#endif // MAIN_H
