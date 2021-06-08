#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"


queue_t q;

int main()
{
    int error_message = 0;
    int dequeued_value = 0;
    // initialization
    printf("\ninitialization\n");
    init(&q);



    // enqueue
    printf("\nenqueue\n");
    error_message = enqueue(&q, 1);
    printf("\nError message: %d", error_message);
    error_message = enqueue(&q, 2);
    printf("\nError message: %d", error_message);
    error_message = enqueue(&q, 3);
    printf("\nError message: %d", error_message);
    error_message = enqueue(&q, 4);
    printf("\nError message: %d", error_message);
    error_message = enqueue(&q, 5);
    printf("\nError message: %d", error_message);
    printf("\n");
    for(int k=0;k<SIZE;k++){
        printf("\n%d",q.data[k]);
    }
    printf("\n--------------------\n");

    // dequeue
    printf("\ndequeue\n");
    dequeued_value = dequeue(&q, 3);
    printf("%d", dequeued_value);
    printf("\n");
    for(int k=0;k<SIZE;k++){
        printf("\n%d",q.data[k]);
    }
    printf("\n--------------------\n");
    dequeued_value = dequeue(&q, 10);
    printf("%d", dequeued_value);
    printf("\n");
    for(int k=0;k<SIZE;k++){
        printf("\n%d",q.data[k]);
    }
    printf("\n--------------------\n");
    dequeued_value = dequeue(&q, 5);
    printf("%d", dequeued_value);
    printf("\n");
    for(int k=0;k<SIZE;k++){
        printf("\n%d",q.data[k]);
    }
    printf("\n--------------------\n");
    dequeued_value = dequeue(&q, 1);
    printf("%d", dequeued_value);
    printf("\n");
    for(int k=0;k<SIZE;k++){
        printf("\n%d",q.data[k]);
    }
    printf("\n--------------------\n");

    //dequeued_value = dequeue(&q, 5);
    //printf("%d", dequeued_value);
    //printf("\n");
    //dequeued_value = dequeue(&q, 5);
    //printf("%d", dequeued_value);
    //printf("\n");

    printf("\nenqueue\n");
    error_message = enqueue(&q, 7);
    printf("\nError message: %d", error_message);
    error_message = enqueue(&q, 17);
    printf("\nError message: %d", error_message);
    error_message = enqueue(&q, 27);
    printf("\nError message: %d", error_message);
    error_message = enqueue(&q, 47);
    printf("\nError message: %d", error_message);
    error_message = enqueue(&q, 69);
    printf("\nError message: %d", error_message);

    // dequeue
    printf("\ndequeue\n");
    dequeued_value = dequeue(&q, 47);
    printf("%d", dequeued_value);
    printf("\n");
    for(int k=0;k<SIZE;k++){
        printf("\n%d",q.data[k]);
    }
    printf("\n--------------------\n");
    dequeued_value = dequeue(&q, 17);
    printf("%d", dequeued_value);
    printf("\n");
    for(int k=0;k<SIZE;k++){
        printf("\n%d",q.data[k]);
    }
    printf("\n--------------------\n");
    dequeued_value = dequeue(&q, 27);
    printf("%d", dequeued_value);
    printf("\n");
    for(int k=0;k<SIZE;k++){
        printf("\n%d",q.data[k]);
    }
    printf("\n--------------------\n");
    dequeued_value = dequeue(&q, 69);
    printf("%d", dequeued_value);
    printf("\n");
    for(int k=0;k<SIZE;k++){
        printf("\n%d",q.data[k]);
    }
    printf("\n--------------------\n");
    dequeued_value = dequeue(&q, 69);
    printf("%d", dequeued_value);
    printf("\n");
    for(int k=0;k<SIZE;k++){
        printf("\n%d",q.data[k]);
    }
    printf("\n--------------------\n");

    printf("\nenqueue\n");
    error_message = enqueue(&q, 111);
    for(int k=0;k<SIZE;k++){
        printf("\n%d",q.data[k]);
    }

    printf("\n--------------------\n");

    //is_empty
    printf("\nis_empty\n");
    error_message = is_empty(&q);
    printf("%d", error_message);

    //cleaning memory
    free(q.data);
    return 0;
}


void init(queue_t* q)
{
    q->data = (int *)calloc(SIZE, sizeof(int));
    q->i = 0;
    q->idxIn = 0;
}


int enqueue(queue_t* q, int val) // returns the ERROR CODE if needed
{
    int j = 0;

	if (q->i == SIZE)
	{
	    printf("\nQUEUE IS FULL!\n");
		return QUEUE_IS_FULL;
	}
    else
    {
        q->data[q->idxIn++] = val;
        q->i++;
        return 0;
    }
}


int dequeue(queue_t* q, int* val) // returns the dequeued value
{
    int i = 0;
    for(int j=0;j < q->i;j++)
    {
        // if no elements are stored in queue -> ERROR
        if (q->i == 0)
        {
            printf("QUEUE IS EMPTY!");
            is_empty(&q);
            break;
        }

        // finding the element equaling to val
        else if (q->data[j] == val)
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
            printf("NO SUCH ELEMENT IN THE QUEUE!");
            return NO_SUCH_ELEMENT_IN_QUEUE;
        }
        i++;
    }
}

bool is_empty(queue_t* q)
{
    return q->i == 0 ? QUEUE_IS_EMPTY : 0;
}
