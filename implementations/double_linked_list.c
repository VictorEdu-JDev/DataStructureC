//
// Created by victor-epc on 03/02/25.
//

#include "../interfaces/double_linked_list.h"
#include <stdlib.h>
#include <stdio.h>

struct double_linked_list {
    int value;
    DoubleLinkedList *prev;
    DoubleLinkedList *next;
};

DoubleLinkedList* dll_create() {
    return NULL;
}

int dll_is_empty(DoubleLinkedList *list) {
    return list == NULL;
}

DoubleLinkedList* dll_insert(DoubleLinkedList *list, int value) {
    DoubleLinkedList *new_node = (DoubleLinkedList*) malloc(sizeof(DoubleLinkedList));
    new_node->value = value;
    new_node->prev = NULL;
    new_node->next = list;
    if (list != NULL) {
        list->prev = new_node;
    }
    return new_node;
}

void dll_print(DoubleLinkedList *list) {
    DoubleLinkedList *current = list;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

DoubleLinkedList* dll_search(DoubleLinkedList *list, int value) {
    DoubleLinkedList *current = list;
    while (current != NULL) {
        if (current->value == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

DoubleLinkedList* dll_remove(DoubleLinkedList *list, int value) {
    DoubleLinkedList *current = list;
    while (current != NULL && current->value != value) {
        current = current->next;
    }
    if (current == NULL) {
        return list;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        list = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
    return list;
}

void dll_free(DoubleLinkedList *list) {
    DoubleLinkedList *current = list;
    while (current != NULL) {
        DoubleLinkedList *next = current->next;
        free(current);
        current = next;
    }
}

DoubleLinkedList* dll_insert_final(DoubleLinkedList* dll, int value) {
    DoubleLinkedList *new_node = malloc(sizeof(DoubleLinkedList));
    new_node->value = value;
    new_node->next = NULL;

    if (!dll) {
        new_node->prev = NULL;
        return new_node;
    }

    DoubleLinkedList *temp = dll;
    while (temp->next) temp = temp->next;

    temp->next = new_node;
    new_node->prev = temp;

    return dll;
}

DoubleLinkedList* dll_insert_two_values(DoubleLinkedList* dll, int x, int y) {
    DoubleLinkedList *new_x = malloc(sizeof(DoubleLinkedList));
    DoubleLinkedList *new_y = malloc(sizeof(DoubleLinkedList));

    new_x->value = x;
    new_y->value = y;

    if (!dll) {
        new_x->prev = NULL, new_x->next = new_y;
        new_y->prev = new_x, new_y->next = NULL;
        return new_x;
    }

    DoubleLinkedList *temp = dll;
    while (temp->next) temp = temp->next;

    new_x->prev = temp->prev;
    new_x->next = temp;
    if (temp->prev) temp->prev->next = new_x;
    temp->prev = new_x;

    new_y->prev = temp;
    new_y->next = NULL;
    temp->next = new_y;

    return dll;
}

