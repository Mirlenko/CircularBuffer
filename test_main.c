#include "unit_test.h"
#include "main.h"
#include <stddef.h>

int tests_run = 0;
queue_t q;

// testing init function
static char * test_init_memory_is_allocated() {
     init(&q);
     assert("ERROR: q.data == NULL", q.data != NULL);
     return 0;
}

static char * test_init_variables_declared_equal_0() {
     init(&q);
     assert("ERROR: q.data[q.i] != 0", q.i == 0);
     assert("ERROR: q.data[q.idxIn] != 0", q.idxIn == 0);
     return 0;
}
/***********************************************************/

// testing enqueue function
static char * test_enqueue_idxin_equals_1() {
     init(&q);
     enqueue(&q, 1);
     assert("ERROR: q.data[q.idxIn] != 1", q.idxIn == 1);
     enqueue(&q, 2);
     assert("ERROR: q.data[q.idxIn] != 2", q.idxIn == 2);
     return 0;
}

static char * test_enqueue_value_equals_1() {
     init(&q);
     enqueue(&q, 1);
     assert("ERROR: q.data[q.idxIn] != 1", q.data[0] == 1);
     return 0;
}

static char * test_enqueue_queue_is_full() {
     init(&q);
     for(int i=1;i<6;i++)
     {
         enqueue(&q, i);
     }
     int result = enqueue(&q, 6);
     assert("ERROR: result != QUEUE_IS_FULL", result == QUEUE_IS_FULL);
     return 0;
}

static char * test_enqueue_3_elements_rest_are_empty() {
     init(&q);
     for(int i=1;i<4;i++)
     {
         enqueue(&q, i);
     }
     assert("ERROR: q.data[0] != 1", q.data[0] == 1);
     assert("ERROR: q.data[1] != 2", q.data[1] == 2);
     assert("ERROR: q.data[2] != 3", q.data[2] == 3);
     assert("ERROR: q.data[3] != 0", q.data[3] == 0);
     assert("ERROR: q.data[4] != 0", q.data[4] == 0);
     return 0;
}
/***********************************************************/

// testing dequeue function
static char * test_dequeue_queue_is_empty() {
     init(&q);
     int result = dequeue(&q, 2);
     assert("ERROR: result != QUEUE_IS_EMPTY", result == QUEUE_IS_EMPTY);
     return 0;
}

static char * test_dequeue_value_equals_5() {
     init(&q);
     enqueue(&q, 2);
     enqueue(&q, 5);
     enqueue(&q, 4);
     int result = dequeue(&q, 5);
     assert("ERROR: result != 5", result == 5);
     return 0;
}

static char * test_dequeue_value_not_found() {
     init(&q);
     enqueue(&q, 1);
     enqueue(&q, 2);
     int result = dequeue(&q, 5);
     assert("ERROR: result != ELEMENT_NOT_FOUND", result == ELEMENT_NOT_FOUND);
     return 0;
}
/***********************************************************/

// testing is_empty function
static char * test_is_empty_true() {
     init(&q);
     int result = is_empty(&q);
     assert("ERROR: result != QUEUE_IS_EMPTY", result == QUEUE_IS_EMPTY);
     return 0;
}

static char * test_is_empty_false() {
     init(&q);
     enqueue(&q, 5);
     int result = is_empty(&q);
     assert("ERROR: result == QUEUE_IS_EMPTY", result != QUEUE_IS_EMPTY);
     return 0;
}
/***********************************************************/

// more complicated logic tests
static char * test_enqueue_3_elements_dequeue_middle() {
     init(&q);
     for(int i=1;i<4;i++)
     {
         enqueue(&q, i);
     }
     dequeue(&q, 2);
     assert("ERROR: q.data[0] != 1", q.data[0] == 1);
     assert("ERROR: q.data[1] != 3", q.data[1] == 3);
     assert("ERROR: q.data[2] != 0", q.data[2] == 0);
     assert("ERROR: q.data[3] != 0", q.data[3] == 0);
     assert("ERROR: q.data[4] != 0", q.data[4] == 0);
     return 0;
}

static char * test_enqueue_3_elements_dequeue_middle_enqueue_one_more() {
     init(&q);
     for(int i=1;i<4;i++)
     {
         enqueue(&q, i*2);
     }
     assert("ERROR: q.data[0] != 2", q.data[0] == 2);
     assert("ERROR: q.data[1] != 4", q.data[1] == 4);
     assert("ERROR: q.data[2] != 6", q.data[2] == 6);
     assert("ERROR: q.data[3] != 0", q.data[3] == 0);
     assert("ERROR: q.data[4] != 0", q.data[4] == 0);
     dequeue(&q, 4);
     enqueue(&q, 18);
     assert("ERROR: q.data[0] != 2", q.data[0] == 2);
     assert("ERROR: q.data[1] != 6", q.data[1] == 6);
     assert("ERROR: q.data[2] != 18", q.data[2] == 18);
     assert("ERROR: q.data[3] != 0", q.data[3] == 0);
     assert("ERROR: q.data[4] != 0", q.data[4] == 0);
     return 0;
}

static char * test_enqueue_3_elements_dequeue_middle_enqueue_to_overflow() {
     init(&q);
     for(int i=1;i<4;i++)
     {
         enqueue(&q, i);
     }
     assert("ERROR: q.data[0] != 1", q.data[0] == 1);
     assert("ERROR: q.data[1] != 2", q.data[1] == 2);
     assert("ERROR: q.data[2] != 3", q.data[2] == 3);
     assert("ERROR: q.data[3] != 0", q.data[3] == 0);
     assert("ERROR: q.data[4] != 0", q.data[4] == 0);
     dequeue(&q, 2);
     enqueue(&q, 5);
     enqueue(&q, 7);
     enqueue(&q, 9);
     int result = enqueue(&q, 11);
     assert("ERROR: q.data[0] != 1", q.data[0] == 1);
     assert("ERROR: q.data[1] != 3", q.data[1] == 3);
     assert("ERROR: q.data[2] != 5", q.data[2] == 5);
     assert("ERROR: q.data[3] != 7", q.data[3] == 7);
     assert("ERROR: q.data[4] != 9", q.data[4] == 9);
     assert("ERROR: result != QUEUE_IS_FULL", result == QUEUE_IS_FULL);
     return 0;
}

static char * test_enqueue_3_elements_dequeue_to_empty() {
     init(&q);
     for(int i=1;i<4;i++)
     {
         enqueue(&q, i);
     }
     assert("ERROR: q.data[0] != 1", q.data[0] == 1);
     assert("ERROR: q.data[1] != 2", q.data[1] == 2);
     assert("ERROR: q.data[2] != 3", q.data[2] == 3);
     dequeue(&q, 2);
     dequeue(&q, 3);
     dequeue(&q, 1);
     int result = dequeue(&q, 2);
     assert("ERROR: q.data[0] != 0", q.data[0] == 0);
     assert("ERROR: q.data[1] != 0", q.data[1] == 0);
     assert("ERROR: q.data[2] != 0", q.data[2] == 0);
     assert("ERROR: q.data[3] != 0", q.data[3] == 0);
     assert("ERROR: q.data[4] != 0", q.data[4] == 0);
     assert("ERROR: result != QUEUE_IS_EMPTY", result == QUEUE_IS_EMPTY);
     return 0;
}

static char * test_enqueue_same_elements_then_dequeue() {
     init(&q);
     for(int i=0;i<5;i++)
     {
         enqueue(&q, 5);
     }
     assert("ERROR: q.data[0] != 5", q.data[0] == 5);
     assert("ERROR: q.data[1] != 5", q.data[1] == 5);
     assert("ERROR: q.data[2] != 5", q.data[2] == 5);
     assert("ERROR: q.data[3] != 5", q.data[3] == 5);
     assert("ERROR: q.data[4] != 5", q.data[4] == 5);
     for(int i=0;i<5;i++)
     {
         dequeue(&q, 5);
     }
     int result = dequeue(&q, 5);
     assert("ERROR: q.data[0] != 0", q.data[0] == 0);
     assert("ERROR: q.data[1] != 0", q.data[1] == 0);
     assert("ERROR: q.data[2] != 0", q.data[2] == 0);
     assert("ERROR: q.data[3] != 0", q.data[3] == 0);
     assert("ERROR: q.data[4] != 0", q.data[4] == 0);
     assert("ERROR: result != QUEUE_IS_EMPTY", result == QUEUE_IS_EMPTY);
     return 0;
}
/***********************************************************/

// calling all tests
static char * all_tests() {
     run_test(test_init_memory_is_allocated);
     run_test(test_init_variables_declared_equal_0);
     run_test(test_enqueue_idxin_equals_1);
     run_test(test_enqueue_value_equals_1);
     run_test(test_enqueue_queue_is_full);
     run_test(test_enqueue_3_elements_rest_are_empty);
     run_test(test_dequeue_queue_is_empty);
     run_test(test_dequeue_value_equals_5);
     run_test(test_dequeue_value_not_found);
     run_test(test_is_empty_true);
     run_test(test_is_empty_false);
     run_test(test_enqueue_3_elements_dequeue_middle);
     run_test(test_enqueue_3_elements_dequeue_middle_enqueue_one_more);
     run_test(test_enqueue_3_elements_dequeue_middle_enqueue_to_overflow);
     run_test(test_enqueue_3_elements_dequeue_to_empty);
     run_test(test_enqueue_same_elements_then_dequeue);
     return 0;
}


int main(int argc, char **argv)
{
    printf("RUNNING TESTS...\n");
    char *result = all_tests();
    if (result != 0)
    {
        printf("\n*******************************\n");
        printf("%s\n", result);
    }
    else
    {
        printf("\n*******************************\n");
        printf("ALL TESTS PASSED\n");
    }
    printf("TESTS RUN: %d\n", tests_run);

    return result != 0;
}

