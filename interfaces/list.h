
#ifndef LIST_H
#define LIST_H

typedef struct list List;

List* lst_create();
int lst_isEmpty(List* list);
List* lst_add(List* list, int value);
List* lst_search(List* list, int value);
List* lst_delete(List* list, int value);
void lst_print(List* list);
void lst_destroy(List* list);

int lst_length(List* list);
int lst_less_than(List* list, int value);
int lst_sum(List* list);
int lst_prime(List* list);
List* lst_concat(List* list1, List* list2);
List* lst_diff(List* list1, List* list2);

void lst_execute_test();

#endif //LIST_H
