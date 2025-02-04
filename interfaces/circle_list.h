//
// Created by victor-epc on 03/02/25.
//

#ifndef CIRCLE_LIST_H
#define CIRCLE_LIST_H

typedef struct circle_list Circle_List;

int is_empty_circle_list(Circle_List *list);
Circle_List *new_circle_list();
void free_circle_list(Circle_List *list);
Circle_List *insert_circle_list(Circle_List *list, int data);
Circle_List *remove_circle_list(Circle_List *list, int data);
int search_circle_list(Circle_List *list, int data);
void print_circle_list(Circle_List *list);

#endif //CIRCLE_LIST_H
