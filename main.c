#include <stdio.h>
#include <stdlib.h>
#include "interfaces/list.h"

int main(void) {
    List* list = lst_create();

    list = lst_add(list, 10);


    printf("%d\n", lst_length(list));

    return EXIT_SUCCESS;
}
