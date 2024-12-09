
#ifndef QUEUE_VECTOR_H
#define QUEUE_VECTOR_H

typedef struct queue_vector Queue_Vector;

Queue_Vector* que_vector_create();
int que_vector_is_empty(Queue_Vector* queue);
void enqueue_vector(Queue_Vector* queue, int value);
int dequeue_vector(Queue_Vector* queue);
void que_vector_print(Queue_Vector* queue);
void que_vector_destroy(Queue_Vector* queue);

#endif //QUEUE_VECTOR_H
