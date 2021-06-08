#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"

// initialization function
void init(queue_t* q)
{
    q->data = (int *)calloc(SIZE, sizeof(int));
    q->i = 0;
    q->idxIn = 0;
}

// function pushing the val element to the queue
// returns 0 in case of successful push, and 2 in case of full queue
int enqueue(queue_t* q, int val)
{
    int j = 0;

	if (q->i == SIZE)
	{
	    printf("QUEUE IS FULL!\n");
		return QUEUE_IS_FULL;
	}
    else
    {
        q->data[q->idxIn++] = val;
        q->i++;
        return 0;
    }
}

// function popping the val element from queue
// the element is deleted from the queue in case of successful dequeue operation
// returns 1 in case of empty queue, val if found, otherwise returns -1
int dequeue(queue_t* q, int* val) // returns the dequeued value
{
    if (is_empty(q))
    {
        return QUEUE_IS_EMPTY;
    }
    else
    {
        int i = 0;
        for(int j=0;j<q->i;j++)
        {
            // finding the element equaling to val
            if (q->data[j] == val)
            {
                for(int k=j;k<q->i;k++)
                {
                    q->data[k] = q->data[k+1];

                }
                q->i--;
                q->idxIn --;
                return val;
            }

            // if no element stored is equal to val -> ERROR
            else if (i == q->i-1)
            {
                printf("NO SUCH ELEMENT IN THE QUEUE!\n");
                return ELEMENT_NOT_FOUND;
            }
            i++;
        }
    }
}

// function checking if the queue is empty
// returns 1 in case of emptiness, 0 otherwise
bool is_empty(queue_t* q)
{
    return q->i == 0 ? QUEUE_IS_EMPTY : 0;
}
