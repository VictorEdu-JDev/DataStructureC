
#ifndef TREE_H
#define TREE_H

typedef struct tree Tree;
typedef struct tree_search TreeSearch;
typedef struct tree_avl TreeAVL;

Tree* create_tree(void);
Tree* create_tree_node(char c, Tree* left, Tree* right);
int is_empty_tree(Tree* tree);
void destroy_tree(Tree* tree);
void tree_print(Tree* tree);
int is_belongs_to_tree(Tree* tree, char c);
int tree_height(Tree* tree);

TreeSearch* create_tree_search(void);
int is_empty_tree_search(TreeSearch* tree);
TreeSearch* tree_search_node(TreeSearch* tree_search, int data);
void print_tree_search(TreeSearch* tree);
TreeSearch* insert_tree_search(TreeSearch* tree, int data);
TreeSearch* delete_tree_search(TreeSearch* tree, int data);


TreeAVL* create_tree_avl(void);
TreeAVL *insert_tree_avl(TreeAVL *ptr, int data, int *ht_inc);
TreeAVL* delete_tree_avl(TreeAVL* tree, int data);
TreeAVL* search_tree_avl(TreeAVL* tree, int data);
int is_empty_tree_avl(TreeAVL* tree);
void destroy_tree_avl(TreeAVL* tree);
void tree_avl_print(TreeAVL* tree);

#endif //TREE_H
