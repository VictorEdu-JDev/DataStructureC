#include <stdio.h>
#include <stdlib.h>
#include "../interfaces/queue.h"
#include "../interfaces/list.h"

struct list {
    int data;
    List* next;
};

struct queue {
    List* head;
    List* tail;
};

Queue* que_create() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Queue is null\n");
        exit(1);
    }
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void enqueue(Queue* queue, int data) {
    List* list = (List*)malloc(sizeof(List));
    if (list == NULL) {
        printf("List is null\n");
        exit(1);
    }

    list->data = data;
    list->next = NULL;

    if (!que_is_empty(queue)) {
        queue->tail->next = list;
    } else {
        queue->head = list;
    }

    queue->tail = list;
}

int que_is_empty(Queue* queue) {
    return queue->head == NULL;
}

int dequeue(Queue* queue) {
    List* temp;
    int a;
    if (que_is_empty(queue)) {
        printf("Queue is empty\n");
        exit(1);
    }
    a = queue->head->data;
    temp = queue->head;
    queue->head = queue->head->next;
    free(temp);
    if (que_is_empty(queue)) {
        queue->tail = NULL;
    }
    return a;
}

void que_print(Queue* queue) {
    List* temp = queue->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void que_destroy(Queue* queue) {
    List* temp = queue->head;
    List* aux;
    while (temp != NULL) {
        aux = temp->next;
        free(temp);
        temp = aux;
    }
    free(queue);
}