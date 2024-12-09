#include <stdio.h>
#include <stdlib.h>
#include "../interfaces/list.h"

struct node {
    int data;
    Node* next;
};

struct list {
    Node* head;
    int length;
};

List* lst_create() {
    return NULL;
}

int lst_isEmpty(List* list) {
    return list == NULL;
}

List* lst_add(List* list, int data) {
    if (list == NULL) {
        list = (List*)malloc(sizeof(List));
        list->head = NULL;
        list->length = 0;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;

    list->head = newNode;
    list->length++;

    return list;
}

int lst_search(List* list, int data) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void lst_print(List* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

List* lst_delete(List* list, int data) {
    if (list == NULL || list->head == NULL) return NULL;

    if (list->head->data == data) {
        Node* temp = list->head->next;
        free(list->head);
        list->head = temp;
        list->length--;
        return list;
    }

    Node* temp = list->head->next;
    Node* tempBefore = list->head;

    while (temp != NULL) {
        if (temp->data == data) {
            tempBefore->next = temp->next;
            free(temp);
            list->length--;
            return list;
        }
        tempBefore = temp;
        temp = temp->next;
    }

    return list;
}

void lst_destroy(List* list) {
    Node* temp = NULL;
    while (list != NULL && list->head != NULL) {
        temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    free(list);
}

int lst_length(List* list) {
    if (list == NULL) return 0;
    return list->length;
}

int lst_less_than(List* list, int value) {
    Node* current = list->head;
    int count = 0;
    while (current != NULL) {
        if (current->data < value) count ++;
        current = current->next;
    }
    return count;
}