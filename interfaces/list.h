
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

int comprimento(List* list);
int menores(List* list, int value);
int soma(List* list);
int primo(List* list);
List* lst_conc(List* list1, List* list2);
List* lst_diferenca(List* list1, List* list2);

int lst_maiores(List* list1, int value);
List* lst_insere_fim_lista(List* list, int value);

void lst_execute_test();

#endif //LIST_H
