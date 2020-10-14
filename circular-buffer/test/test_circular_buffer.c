#include "vendor/unity.h"

#include "../src/circular_buffer.h"

#define BUFFER_CAPACITY  10

void setUp(void) {}


void tearDown(void) {}


void static test_build_circular_buffer(void) {
    CircularBuffer *circular_buffer = new_circular_buffer(BUFFER_CAPACITY);
    TEST_ASSERT_NOT_NULL(circular_buffer);
}


void static test_write_values_to_buffer(void) {
    CircularBuffer *circular_buffer = new_circular_buffer(BUFFER_CAPACITY);
    
    for (int i = 0; i < BUFFER_CAPACITY; i++) {
        write(circular_buffer, i);
    }

    TEST_ASSERT_EQUAL_INT(1, is_full(circular_buffer));

    int expected[BUFFER_CAPACITY];
    for (int i = 0; i < BUFFER_CAPACITY; i++) {
        expected[i] = i;
    }

    for (int i = 0; i < BUFFER_CAPACITY; i++) {
        TEST_ASSERT_EQUAL_INT(expected[i], circular_buffer->elements[i]);
    }

    delete_circular_buffer(circular_buffer);
    
}


void static test_read_from_buffer(void) {
    CircularBuffer *circular_buffer = new_circular_buffer(BUFFER_CAPACITY);
    
    for (int i = 0; i < 2 * BUFFER_CAPACITY; i++) {
        write(circular_buffer, i);
    }

    int value;
    for (int i = 0; i < BUFFER_CAPACITY; i++) {
        int result = pop(circular_buffer, &value);
        TEST_ASSERT_EQUAL_INT(0, result);
        TEST_ASSERT_EQUAL_INT(i + BUFFER_CAPACITY, circular_buffer->elements[i]);
    }

    delete_circular_buffer(circular_buffer);
}


int main(){
    UnityBegin("test/test_circular_buffer.c");

    RUN_TEST(test_write_values_to_buffer);
    RUN_TEST(test_read_from_buffer);

    return UnityEnd();
}
