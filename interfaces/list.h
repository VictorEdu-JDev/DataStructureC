
#ifndef LIST_H
#define LIST_H

typedef struct list List;

List* lst_create();
int lst_isEmpty(List* list);
List* lst_add(List* list, int value);
int lst_search(List* list, int value);
List* lst_delete(List* list, int value);
void lst_print(List* list);
void lst_destroy(List* list);

#endif //LIST_H
