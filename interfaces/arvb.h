//
// Created by Victor on 27/01/2025.
//

#ifndef ARVB_H
#define ARVB_H

typedef struct arvb ArvB;

ArvB* create_arvb(void);
int is_empty_arvb(ArvB* tree);
ArvB* arvb_node(ArvB* tree_search, int data);
void print_arvb(ArvB* tree);
ArvB* insert_arvb(ArvB* tree, int data);
ArvB* delete_arvb(ArvB* tree, int data);
int arv_altura(ArvB* tree);
void destroy_arvb(ArvB* tree);

int folhas_primos(ArvB* tree);
int dois_filhos(ArvB* tree);
int nos_igual_altura(ArvB* tree);
int iguais(ArvB* tree1, ArvB* tree2);

#endif //ARVB_H
