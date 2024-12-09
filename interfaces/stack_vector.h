
#ifndef STACK_VECTOR_H
#define STACK_VECTOR_H

typedef struct stack_vector Stack;

Stack* stk_vector_create();
int stk_vector_is_empty(Stack* s);
void stk_vector_push(Stack* stack, int value);
int stk_vector_pop(Stack* stack);
void stk_vector_print(Stack* stack);
void stk_vector_destroy(Stack* stack);

#endif //STACK_VECTOR_H
