
#ifndef QUEUE_H
#define QUEUE_H


typedef struct queue Queue;

Queue* que_create();
int que_is_empty(Queue* queue);
void enqueue(Queue* queue, int data);
int dequeue(Queue* queue);
void que_print(Queue* queue);
void que_destroy(Queue* queue);

int qtde_maior(Queue* queue, int n);
Queue* inverte(Queue* queue);
int pares(Queue* queue);

int que_retira_par(Queue* queue);

void que_execute_test();

#endif //QUEUE_H
