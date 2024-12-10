#include <stdio.h>

#include "interfaces/list.h"
#include "interfaces/queue.h"
#include "interfaces/stack_vector.h"

int main(void) {
    printf("TESTE DE LIST\n");
    lst_execute_test();

    printf("TESTE DE STACK_VECTOR\n");
    stk_execute_test();

    printf("TESTE DE QUEUE\n");
    que_execute_test();

    return 0;
}
