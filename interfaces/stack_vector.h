
#ifndef STACK_VECTOR_H
#define STACK_VECTOR_H

typedef struct stack_vector Stack_Vector;

Stack_Vector* stk_vector_create();
int stk_vector_is_empty(Stack_Vector* s);
void vector_push(Stack_Vector* stack, int value);
int vector_pop(Stack_Vector* stack);
void stk_vector_print(Stack_Vector* stack);
void stk_vector_destroy(Stack_Vector* stack);

int topo(Stack_Vector* stack);
int impares(Stack_Vector* stack);
Stack_Vector* empilha_pares(Stack_Vector* p1, Stack_Vector* p2);

void stk_execute_test();

#endif //STACK_VECTOR_H
