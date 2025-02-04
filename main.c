#include <stdio.h>
#include <stdlib.h>

#include "interfaces/double_linked_list.h"
#include "interfaces/queue.h"
#include "interfaces/tree.h"

int main() {
    DoubleLinkedList* dll = dll_create();

    dll = dll_insert(dll, 10);
    dll = dll_insert(dll, 20);
    dll = dll_insert(dll, 30);
    dll = dll_insert(dll, 40);
    dll = dll_insert(dll, 50);
    dll = dll_insert(dll, 60);
    dll = dll_insert(dll, 70);
    dll = dll_insert(dll, 80);
    dll = dll_insert(dll, 90);
    dll = dll_insert(dll, 100);

    dll_print(dll);

    return EXIT_SUCCESS;
}
