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
    if (queue == NULL || que_is_empty(queue)) {
        printf("Queue is empty or uninitialized\n");
        exit(1);
    }

    List* temp = queue->head;
    int data = temp->data;

    queue->head = queue->head->next;

    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    free(temp);

    return data;
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
    if (queue == NULL) {
        return;
    }

    List* temp = queue->head;
    List* aux;
    while (temp != NULL) {
        aux = temp->next;
        free(temp);
        temp = aux;
    }
    free(queue);
}

int qtde_maior(Queue* queue, int n) {
    int count = 0;
    List* temp = queue->head;
    while (temp != NULL) {
        if (temp->data > n) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

Queue* inverte(Queue* queue) {
    Queue* reversed = que_create();
    List* temp = queue->head;
    while (temp != NULL) {
        List* new_node = (List*)malloc(sizeof(List));
        new_node->data = temp->data;
        new_node->next = reversed->head;
        reversed->head = new_node;
        if (reversed->tail == NULL) {
            reversed->tail = new_node;
        }
        temp = temp->next;
    }
    return reversed;
}

int pares(Queue* queue) {
    int count = 0;
    List* temp = queue->head;
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

int que_retira_par(Queue* queue) {
    if (queue->head == NULL) return 1;

    List* temp = queue->head;
    int data = temp->data;
    if (data % 2 == 0) {
        queue->head = queue->head->next;
        free(temp);
        printf("Dado removido: %d\n", data);
        return data;
    }
    printf("Nenhum dado removido.\n");
    return 1;
}

void que_execute_test() {
    int a;
    int qtd;

    Queue* f1 = que_create();
    enqueue(f1, 11);
    enqueue(f1, 12);
    enqueue(f1, 13);
    enqueue(f1, 14);
    enqueue(f1, 15);

    a = dequeue(f1);

    printf("Valor removido da fila f1: %d\n", a);
    que_print(f1);

    Queue* f2 = inverte(f1);
    que_print(f2);
    qtd = qtde_maior(f1, 12);

    printf("Num. de elem. maiores que 12 em f1: %d\n", qtd);
    printf("Qtd. elem. pares na fila f1: %d\n", pares(f1));

    que_destroy(f1);
    que_destroy(f2);

    system("PAUSE");
}