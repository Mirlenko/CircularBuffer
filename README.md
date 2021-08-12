# CircularBuffer

__CIRCULAR BUFFER IN C__

In the current project solution for queue based on circular buffer is implemented. The language used is C.
A circular buffer is based on an array of fixed size which is virtually connected end to end, i.e. when the end of the array is reached, writing is done at the start of the array. In our case as the buffer is used for a queue, when the maximum capacity is reached, an error code should be returned when trying to add more elements to the queue. Attempt to dequeue an element from an empty queue should also result in an error.

In the solution the following assumptions are made:
* the elements stored in the queue are of an int type;
* the values stored in the queue should be positive non-zero int values (logically, zero values can be stored, and in this case the queue is not considered to be empty, because of index variable, pointing at the position after the last inserted element; however, in case of printing or handling the queue the ambiguity can arise).

The error codes used are as follows:
* QUEUE_IS_EMPTY : 1
* QUEUE_IS_FULL : 2
* ELEMENT_IS_EMPTY: -1

The solution consits of 4 files:
* QUEUE.C
* QUEUE.H
* TEST_QUEUE.C
* UNIT_TEST.H

__QUEUE.C__
In the file the queue based on the circular buffer is implemented.
The init function is used to allocate memory for the queue and create necessary variables. By default, the queue size is set by SIZE to be equal to 5 elements (QUEUE.H).
The enqueue function is used to insert (push) element in the queue. In case the queue is full (filled with positive non-zero elements), the QUEUE_IS_FULL error code is returned; otherwise, 0 is returned.
The dequeue function is used to clear (pop) from the queue an element pointed by a pointer. In case the queue is empty, the QUEUE_IS_EMPTY error code is returned; in case the pointer contains address of an empty element, the ELEMENT_IS_EMPTY error code is returned; otherwise, 0 is returned. If the element is dequeued from the middle of filled values, the elements going after the dequeued one are shifted.
The is_empty function is used to check if the queue is empty, i.e. does not contain any non-zero values. 

__QUEUE.H__
The file contains the declaration of queue structure, as well as declaration of functions used.

__TEST_QUEUE.C__
The file contains unit tests for QUEUE.C logic.
In total, 17 tests are implemented. Firstly, all the functions behavior is tested, then various situations are tested.

__UNIT_TEST.H__
In the file the unit test functions are defined. The unit test framework solution is inspired by minunit solution. 
