#include "queue.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_enqueue(void)
{
    int a=10;

//This will evaluates to pass
    TEST_ASSERT_EQUAL_INT(10, a);
}
