
#ifndef QUEUE_H
#define QUEUE_H


typedef struct queue Queue;

Queue* que_create();
int que_is_empty(Queue* queue);
void enqueue(Queue* queue, int data);
int dequeue(Queue* queue);
void que_print(Queue* queue);
void que_destroy(Queue* queue);

int count_greater(Queue* queue, int n);
Queue* reverse_queue(Queue* queue);
int count_even(Queue* queue);

void que_execute_test();

#endif //QUEUE_H
