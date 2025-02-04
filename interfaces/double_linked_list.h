//
// Created by victor-epc on 03/02/25.
//

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

typedef struct double_linked_list DoubleLinkedList;

DoubleLinkedList* dll_create();
int dll_is_empty(DoubleLinkedList *list);
DoubleLinkedList* dll_insert(DoubleLinkedList *list, int value);
void dll_print(DoubleLinkedList *list);
DoubleLinkedList* dll_search(DoubleLinkedList *list, int value);
DoubleLinkedList* dll_remove(DoubleLinkedList *list, int value);
void dll_free(DoubleLinkedList *list);


#endif //DOUBLE_LINKED_LIST_H
