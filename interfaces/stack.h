
#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;

Stack* stk_create();
int stk_is_empty(Stack* s);
void stk_push(Stack* stack, int value);
int stk_pop(Stack* stack);
void stk_print(Stack* stack);
void stk_destroy(Stack* stack);

void stk_push_menor(Stack* stack, int value);
int stk_sum(Stack* stack);


#endif //STACK_H
