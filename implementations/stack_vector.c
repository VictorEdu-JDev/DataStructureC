#include <stdio.h>
#include <stdlib.h>
#include "../interfaces/stack_vector.h"

#define MAX 10

struct stack_vector {
    int top;
    int data[MAX];
};

Stack_Vector* stk_vector_create() {
    Stack_Vector* stack = (Stack_Vector*)malloc(sizeof(Stack_Vector));
    if (stack == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    stack->top = 0;
    return stack;
}

void vector_push(Stack_Vector* stack, int info) {
    if (stack->top == MAX) {
        printf("Capacidade maxima atingida.\n");
        exit(1);
    }
    stack->data[stack->top] = info;
    stack->top++;
}

void stk_vector_print(Stack_Vector* stack) {
    for (int  i = stack->top - 1; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

void stk_vector_destroy(Stack_Vector* stack) {
    free(stack);
}

int stk_vector_is_empty(Stack_Vector* stack) {
    return stack->top == 0;
}

int vector_pop(Stack_Vector* stack) {
    if(stk_vector_is_empty(stack)) {
        printf("Erro ao dar pop stack.\n");
        exit(1);
    }
    stack->top--;
    return stack->data[stack->top];
}

int get_vector_top(Stack_Vector* stack) {
    if (stk_vector_is_empty(stack)) {
        printf("Erro: pilha vazia.\n");
        exit(1);
    }
    return stack->data[stack->top - 1];
}

int odds_vector(Stack_Vector* stack) {
    int count = 0;
    for (int i = 0; i < stack->top; i++) {
        if (stack->data[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

Stack_Vector* push_even_vector(Stack_Vector* p1, Stack_Vector* p2) {
    Stack_Vector* aux = stk_vector_create();

    for (int i = 0; i < p1->top; i++) {
        if (p1->data[i] % 2 == 0) {
            vector_push(aux, p1->data[i]);
        }
    }

    for (int i = 0; i < aux->top - 1; i++) {
        for (int j = i + 1; j < aux->top; j++) {
            if (aux->data[i] > aux->data[j]) {
                int temp = aux->data[i];
                aux->data[i] = aux->data[j];
                aux->data[j] = temp;
            }
        }
    }

    for (int i = 0; i < aux->top; i++) {
        vector_push(p2, aux->data[i]);
    }

    stk_vector_destroy(aux);

    return p2;
}


void stk_execute_test() {
    Stack_Vector* p1 = stk_vector_create();
    vector_push(p1, 10);
    vector_push(p1, 20);
    vector_push(p1, 25);
    vector_push(p1, 30);

    vector_pop(p1);
    stk_vector_print(p1);

    printf("Elemento no topo da pilha p1: %d\n", get_vector_top(p1));
    printf("Qtde elemts impares na pilha p1: %d\n", odds_vector(p1));

    Stack_Vector* p2 = stk_vector_create();
    vector_push(p2, 3);
    vector_push(p2, 4);
    vector_push(p2, 5);

    p2 = push_even_vector(p1, p2);
    stk_vector_print(p2);

    stk_vector_destroy(p1);
    stk_vector_destroy(p2);

    system("PAUSE");
}
