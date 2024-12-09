#include <stdio.h>
#include <stdlib.h>
#include "../interfaces/list.h"

struct list {
    int data;
    List* next;
};

List* lst_create() {
    return NULL;
}

int lst_isEmpty(List* list) {
    return list == NULL;
}

List* lst_add(List* list, int data) {
    List* newList = (List*)malloc(sizeof(List));
    newList->data = data;
    newList->next = list;

    return newList;
}

int lst_search(List* list, int data) {
    List* current = list;
    while (current != NULL) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void lst_print(List* list) {
    List* current = list;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

List* lst_delete(List* list, int data) {
    if (list == NULL) {
        return NULL;
    }

    if (list->data == data) {
        List* temp = list->next;
        free(list);
        return temp;
    }

    List* temp = list->next;
    List* tempBefore = list;

    while (temp != NULL) {
        if (temp->data == data) {
            tempBefore->next = temp->next;
            free(temp);
            return list;
        }
        tempBefore = temp;
        temp = temp->next;
    }

    return list;
}

void lst_destroy(List* list) {
    List* temp = NULL;
    while (list != NULL) {
        temp = list->next;
        free(list);
        list = temp;
    }
}

