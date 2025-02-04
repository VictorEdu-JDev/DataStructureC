//
// Created by victor-epc on 03/02/25.
//

#include "../interfaces/circle_list.h"

#include <stdio.h>
#include <stdlib.h>

struct circle_list {
    int data;
    Circle_List *next;
};

int is_empty_circle_list(Circle_List *list) {
    return list == NULL;
}

Circle_List *new_circle_list() {
    return NULL;
}
void free_circle_list(Circle_List *list) {
    if (list == NULL) return;
    Circle_List *current = list;
    Circle_List *next = NULL;
    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != list);

}
Circle_List *insert_circle_list(Circle_List *list, int data) {
    Circle_List *cl = (Circle_List *)malloc(sizeof(Circle_List));
    cl->data = data;
    if (is_empty_circle_list(list)) {
        cl->next = cl;
    } else {
        cl->next = list->next;
        list->next = cl;
    }
    return cl;
}

Circle_List *remove_circle_list(Circle_List *list, int data) {
    if (list == NULL) return NULL;

    if (list->data == data) {
        Circle_List* temp = list;
        list = list->next;
        free(temp);
        return list;
    }

    Circle_List* current = list;
    while (current->next != NULL) {
        if (current->next->data == data) {
            Circle_List* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return list;
        }
        current = current->next;
    }
    return list;
}
int search_circle_list(Circle_List *list, int data) {
    if (list == NULL) return 0;
    if (list->data == data) return 1;

    Circle_List* current = list;
    while (current->next != NULL)
        if (current->next->data == data)
            return 1;
    return 0;
}

void print_circle_list(Circle_List *list) {
    if (list != NULL) {
        Circle_List* current = list;
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (list != current);
    }
}
