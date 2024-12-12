#include <stdio.h>
#include <stdlib.h>
#include "../interfaces/queue_vector.h"

#define QUEUE_SIZE 10

struct queue_vector {
    int value;
    int start;
    int data[QUEUE_SIZE];
};

Queue_Vector* que_vector_create() {
    Queue_Vector* queue = (Queue_Vector*)malloc(sizeof(Queue_Vector));
    if (queue == NULL) {
        printf("Memory allocation error");
        exit(1);
    }
    queue->value = 0;
    queue->start = 0;
    return queue;
}

void enqueue_vector(Queue_Vector* queue, int value) {
    if (queue->value == QUEUE_SIZE) {
        printf("Queue is full");
        exit(1);
    }
    int end = (queue->start + queue->value) % QUEUE_SIZE;
    queue->data[end] = value;
    queue->value++;
}

int que_vector_is_empty(Queue_Vector* queue) {
    return queue->value == 0;
}

int dequeue_vector(Queue_Vector* queue) {
    int a;
    if (que_vector_is_empty(queue)) {
        printf("Queue is empty");
        exit(1);
    }
    a = queue->data[queue->start];
    queue->start = (queue->start + 1) % QUEUE_SIZE;
    queue->value--;
    return a;
}

void que_vector_destroy(Queue_Vector* queue) {
    free(queue);
}

void que_vector_print(Queue_Vector* queue) {
    int k;
    for (int i = 0; i < queue->value; i++) {
        k = (queue->start+i) % QUEUE_SIZE;
        printf("%d ", queue->data[k]);
    }
    printf("\n");
}