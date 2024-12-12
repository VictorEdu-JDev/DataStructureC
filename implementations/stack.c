#include <stdio.h>
#include <stdlib.h>
#include "../interfaces/list.h"
#include "../interfaces/stack.h"

struct stack {
    List *first;
};

struct list {
    int value;
    List *next;
};

Stack *stk_create() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        return NULL;
    }
    stack->first = NULL;
    return stack;
}

void stk_push(Stack *stack, int value) {
    List* list = (List*)malloc(sizeof(List));
    if (list == NULL) {
        printf("Memory allocation failed in stk_push()\n");
        exit(1);
    }
    list->value = value;
    list->next = stack->first;
    stack->first = list;
}

int stk_pop(Stack *stack) {
    if (stk_is_empty(stack)) {
        printf("Empty stack\n");
        exit(1);
    }

    List* list = stack->first;
    int a = list->value;
    stack->first = list->next;

    free(list);
    return a;
}

int stk_is_empty(Stack *stack) {
    return stack->first == NULL;
}

void stk_print(Stack *stack) {
    List* list = stack->first;
    while (list != NULL) {
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}

void stk_destroy(Stack *stack) {
    List* list = stack->first;
    List* aux;
    while (list != NULL) {
        aux = list->next;
        free(list);
        list = aux;
    }
    free(stack);
}

void stk_push_menor(Stack *stack, int value) {
    List* list = (List*)malloc(sizeof(List));
    if (list == NULL) {
        printf("Memory allocation failed in stk_push_menor()\n");
        exit(1);
    }

    if (stack->first == NULL) {
        list->value = value;
        list->next = stack->first;
        stack->first = list;
        return;
    }

    if (stack->first->value > value) {
        list->value = value;
        list->next = stack->first;
        stack->first = list;
    } else {
        free(list);
        printf("Valor maior que o topo da pilha.\n");
    }
}

int stk_sum(Stack* stk) {
    if (stk->first == NULL) return 0;

    List* aux = stk->first;
    int sum = 0;
    while (aux != NULL) {
        sum += aux->value;
        aux = aux->next;
    }
    return sum;
}