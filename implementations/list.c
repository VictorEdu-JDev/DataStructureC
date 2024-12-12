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
    List* newNode = (List*)malloc(sizeof(List));
    newNode->data = data;
    newNode->next = list;
    return newNode;
}

List* lst_search(List* list, int data) {
    List* current = list;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
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
    if (list == NULL) return NULL;

    if (list->data == data) {
        List* temp = list;
        list = list->next;
        free(temp);
        return list;
    }

    List* current = list;
    while (current->next != NULL) {
        if (current->next->data == data) {
            List* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return list;
        }
        current = current->next;
    }
    return list;
}

void lst_destroy(List* list) {
    List* current = list;
    List* temp = NULL;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

int comprimento(List* list) {
    int length = 0;
    List* current = list;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

int menores(List* list, int value) {
    int count = 0;
    List* current = list;
    while (current != NULL) {
        if (current->data < value) {
            count++;
        }
        current = current->next;
    }
    return count;
}

int soma(List* list) {
    int sum = 0;
    List* current = list;
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}

int primo(List* list) {
    int primeCount = 0;
    List* current = list;

    while (current != NULL) {
        int num = current->data;
        if (num < 2) {
            current = current->next;
            continue;
        }

        int isPrime = 1;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime) {
            primeCount++;
        }
        current = current->next;
    }

    return primeCount;
}

List* lst_conc(List* list1, List* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    List* newList = NULL;
    List* current = list1;
    while (current != NULL) {
        newList = lst_add(newList, current->data);
        current = current->next;
    }

    current = list2;
    while (current != NULL) {
        newList = lst_add(newList, current->data);
        current = current->next;
    }

    return newList;
}

List* lst_diferenca(List* list1, List* list2) {
    if (list1 == NULL || list2 == NULL) return list1;

    List* diff = NULL;

    List* current1 = list1;

    while (current1 != NULL) {
        if (!lst_search(list2, current1->data)) {
            diff = lst_add(diff, current1->data);
        }
        current1 = current1->next;
    }

    return diff;
}

int lst_maiores(List* list1, int value) {
    int count = 0;
    List* current = list1;
    while (current != NULL) {
        if (current->data > value) {
            count++;
        }
        current = current->next;
    }
    return count;
}

List* lst_insere_fim_lista(List* list1, int value) {
    List* newList = (List*)malloc(sizeof(List));
    newList->data = value;
    newList->next = NULL;

    if (list1 == NULL) {
        return newList;
    }

    List* temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newList;

    return list1;
}

void lst_execute_test() {
    List* l1 = lst_create();
    l1 = lst_add(l1, 60);
    l1 = lst_add(l1, 13);
    l1 = lst_add(l1, 45);
    l1 = lst_add(l1, 28);
    l1 = lst_add(l1, 41);
    l1 = lst_add(l1, 37);

    l1 = lst_delete(l1, 41);
    lst_print(l1);

    printf("Num. nos c/ info < que 30: %d\n", menores(l1, 30));
    printf("O comprimento da lista eh %d\n", comprimento(l1));
    printf("Soma dos valores dos nos %d\n", soma(l1));
    printf("Num. nos com val. primos eh %d\n", primo(l1));

    List* l2 = lst_create();
    l2 = lst_add(l2, 28);
    l2 = lst_add(l2, 45);
    l2 = lst_add(l2, 130);

    List* l3 = lst_conc(l1, l2);
    lst_print(l3);

    l1 = lst_diferenca(l1, l2);
    lst_print(l1);

    lst_destroy(l1);
    lst_destroy(l2);
    lst_destroy(l3);

    system("PAUSE");
}