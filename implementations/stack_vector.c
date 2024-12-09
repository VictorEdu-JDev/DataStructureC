#include <stdio.h>
#include <stdlib.h>
#include "../interfaces/stack_vector.h"

#define MAX 10

struct stack_vector {
    int top;
    int data[MAX];
};

Stack* stk_vector_create() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    stack->top = 0;
    return stack;
}

void stk_vector_push(Stack* stack, int info) {
    if (stack->top == MAX) {
        printf("Capacidade maxima atingida.\n");
        exit(1);
    }
    stack->data[stack->top] = info;
    stack->top++;
}

void stk_vector_print(Stack* stack) {
    for (int  i = stack->top - 1; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

void stk_vector_destroy(Stack* stack) {
    free(stack);
}

int stk_vector_is_empty(Stack* stack) {
    return stack->top == 0;
}

int stk_vector_pop(Stack* stack) {
    if(stk_vector_is_empty(stack)) {
        printf("Erro ao dar pop stack.\n");
        exit(1);
    }
    stack->top--;
    return stack->data[stack->top];
}