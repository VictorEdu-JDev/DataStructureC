#include "../interfaces/tree.h"
#include <stdio.h>
#include <stdlib.h>

struct tree {
    char info;
    Tree* left;
    Tree* right;
};

struct tree_search {
    int info;
    TreeSearch* left;
    TreeSearch* right;
};

struct tree_avl {
    int val;
    int balance;
    TreeAVL* left_child;
    TreeAVL* right_child;
};

Tree* create_tree(void) {
    return NULL;
}

Tree* create_tree_node(char info, Tree* left, Tree* right) {
    Tree* node = (Tree*)malloc(sizeof(Tree));
    node->info = info;
    node->left = left;
    node->right = right;
    return node;
}

int is_empty_tree(Tree* tree) {
    return tree == NULL;
}

void tree_print(Tree* tree) {
    if (tree != NULL) {
        printf("%c ", tree->info);
        tree_print(tree->left);
        tree_print(tree->right);
    }
}

int is_belongs_to_tree(Tree* tree, char ch) {
    if (tree == NULL) return 0;

    return tree->info == ch ||
        is_belongs_to_tree(tree->left, ch) ||
            is_belongs_to_tree(tree->right, ch);
}

void destroy_tree(Tree* tree) {
    if (tree != NULL) {
        destroy_tree(tree->left);
        destroy_tree(tree->right);
        free(tree);
    }
}

int tree_height(Tree* tree) {
    if (tree == NULL) return -1;

    int left_height = tree_height(tree->left);
    int right_height = tree_height(tree->right);

    if (left_height > right_height) return 1 + left_height;
    return 1 + right_height;
}

TreeSearch* create_tree_search(void) {
    return NULL;
}

int is_empty_tree_search(TreeSearch* tree) {
    return tree == NULL;
}

TreeSearch* tree_search_node(TreeSearch* ts, int data) {
    if (ts == NULL || ts->info == data) return ts;
    if (ts->info < data) return tree_search_node(ts->right, data);
    if (ts->info > data) return tree_search_node(ts->left, data);
    return ts;
}

void print_tree_search(TreeSearch* tree) {
    if (tree != NULL) {
        print_tree_search(tree->left);
        printf("%d ", tree->info);
        print_tree_search(tree->right);
    }
}

TreeSearch* insert_tree_search(TreeSearch* tree, int data) {
    if (tree == NULL) {
        tree = (TreeSearch*)malloc(sizeof(TreeSearch));
        tree->info = data;
        tree->left = NULL;
        tree->right = NULL;
    } else if (tree->info > data) {
        tree->left = insert_tree_search(tree->left, data);
    } else if (tree->info < data) {
        tree->right = insert_tree_search(tree->right, data);
    } else {
        printf("Element already belongs a tree.\n");
    }
    return tree;
}

TreeSearch* find_max(TreeSearch* tree) {
    while (tree->right != NULL) {
        tree = tree->right;
    }
    return tree;
}

TreeSearch* delete_node(TreeSearch* tree) {
    TreeSearch* temp;
    if (tree->left == NULL) {
        temp = tree->right;
        free(tree);
        return temp;
    }
    if (tree->right == NULL) {
        temp = tree->left;
        free(tree);
        return temp;
    }
    temp = find_max(tree->left);
    tree->info = temp->info;
    tree->left = delete_tree_search(tree->left, temp->info);

    return tree;
}

TreeSearch* delete_tree_search(TreeSearch* tree, int data) {
    if (tree != NULL) {
        if (data < tree->info) {
            tree->left = delete_tree_search(tree->left, data);
        } else if (data > tree->info) {
            tree->right = delete_tree_search(tree->right, data);
        } else {
            tree = delete_node(tree);
        }
    }
    return tree;
}


TreeAVL* create_tree_avl(void) {
    return NULL;
}

TreeAVL* search_tree_avl(TreeAVL* tree, int data) {
    if (tree != NULL) {
        if (data == tree->val) return tree;

        if (data < tree->val) {
            search_tree_avl(tree->left_child, data);
        } else if (data > tree->val) {
            search_tree_avl(tree->right_child, data);
        }
    }
    printf("Element not found.\n");
    return tree;
}

TreeAVL *left_to_left_rotation(TreeAVL *ptr) {
    TreeAVL *aptr = ptr->left_child;
    ptr->left_child = aptr->right_child;
    aptr->right_child = ptr;
    ptr->balance = 0;
    aptr->balance = 0;
    return aptr;
}

TreeAVL *right_to_right_rotation(TreeAVL *ptr) {
    TreeAVL *aptr = ptr->right_child;
    ptr->right_child = aptr->left_child;
    aptr->left_child = ptr;
    ptr->balance = 0;
    aptr->balance = 0;
    return aptr;
}

TreeAVL *left_to_right_rotation(TreeAVL *ptr) {
    TreeAVL *aptr = ptr->left_child;
    TreeAVL *bptr = aptr->right_child;
    aptr->right_child = bptr->left_child;
    bptr->left_child = aptr;
    ptr->left_child = bptr->right_child;
    bptr->right_child = ptr;

    if (bptr->balance == 1) {
        ptr->balance = -1;
    } else {
        ptr->balance = 0;
    }

    if (bptr->balance == -1) {
        aptr->balance = 1;
    } else {
        aptr->balance = 0;
    }

    bptr->balance = 0;
    return bptr;
}

TreeAVL *right_to_left_rotation(TreeAVL *ptr) {
    TreeAVL *aptr = ptr->right_child;
    TreeAVL *bptr = aptr->left_child;
    aptr->left_child = bptr->right_child;
    bptr->right_child = aptr;
    ptr->right_child = bptr->left_child;
    bptr->left_child = ptr;

    if (bptr->balance == -1) {
        ptr->balance = 1;
    } else {
        ptr->balance = 0;
    }

    if (bptr->balance == 1) {
        aptr->balance = -1;
    } else {
        aptr->balance = 0;
    }

    bptr->balance = 0;
    return bptr;
}

TreeAVL *insert_tree_avl(TreeAVL *ptr, int data, int *ht_inc) {
    if (ptr == NULL) {
        ptr = (TreeAVL *) malloc(sizeof(TreeAVL));
        ptr->val = data;
        ptr->left_child = NULL;
        ptr->right_child = NULL;
        ptr->balance = 0;
        *ht_inc = 1;
        return ptr;
    }

    if (data < ptr->val) {
        ptr->left_child = insert_tree_avl(ptr->left_child, data, ht_inc);
        if (*ht_inc == 1) {
            if (ptr->balance == 1) {
                TreeAVL *aptr = ptr->left_child;
                if (aptr->balance == 1) {
                    printf("Left to Left Rotation\n");
                    ptr = left_to_left_rotation(ptr);
                } else {
                    printf("Left to Right Rotation\n");
                    ptr = left_to_right_rotation(ptr);
                }
                *ht_inc = 0;
            } else if (ptr->balance == 0) {
                ptr->balance = 1;
            } else {
                ptr->balance = 0;
                *ht_inc = 0;
            }
        }
    }

    if (data > ptr->val) {
        ptr->right_child = insert_tree_avl(ptr->right_child, data, ht_inc);
        if (*ht_inc == 1) {
            if (ptr->balance == -1) {
                TreeAVL *aptr = ptr->right_child;
                if (aptr->balance == -1) {
                    printf("Right to Right Rotation\n");
                    ptr = right_to_right_rotation(ptr);
                } else {
                    printf("Right to Left Rotation\n");
                    ptr = right_to_left_rotation(ptr);
                }
                *ht_inc = 0;
            } else if (ptr->balance == 0) {
                ptr->balance = -1;
            } else {
                ptr->balance = 0;
                *ht_inc = 0;
            }
        }
    }

    return ptr;
}
