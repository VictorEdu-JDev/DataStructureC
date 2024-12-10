
#ifndef STACK_VECTOR_H
#define STACK_VECTOR_H

typedef struct stack_vector Stack_Vector;

Stack_Vector* stk_vector_create();
int stk_vector_is_empty(Stack_Vector* s);
void vector_push(Stack_Vector* stack, int value);
int vector_pop(Stack_Vector* stack);
void stk_vector_print(Stack_Vector* stack);
void stk_vector_destroy(Stack_Vector* stack);

int get_vector_top(Stack_Vector* stack);
int odds_vector(Stack_Vector* stack);
Stack_Vector* push_even_vector(Stack_Vector* p1, Stack_Vector* p2);

void stk_execute_test();

#endif //STACK_VECTOR_H
