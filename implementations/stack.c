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
    int a;

    List* list;
    if (stk_is_empty(stack)) {
        printf("Empty stack\n");
        exit(1);
    }

    list = stack->first;
    a = list->value;
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