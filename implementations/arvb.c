#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../interfaces/arvb.h"

int eh_primo(int data);
ArvB* find_max_arvb(ArvB* tree);
ArvB* delete_node_arvb(ArvB* tree);
int tem_filhos(ArvB * arvb);
int verificar_condicoes(ArvB* arvb);

struct arvb {
    int data;
    ArvB* left;
    ArvB* right;
};

ArvB* create_arvb(void) {
    return NULL;
}

int is_empty_arvb(ArvB* tree) {
    return tree == NULL;
}

void destroy_arvb(ArvB* tree) {
    if (tree != NULL) {
        destroy_arvb(tree->left);
        destroy_arvb(tree->right);
        free(tree);
    }
}

ArvB* arvb_node(ArvB* ts, const int data) {
    if (ts == NULL || ts->data == data) return ts;
    if (ts->data < data) return arvb_node(ts->right, data);
    if (ts->data > data) return arvb_node(ts->left, data);
    return ts;
}

void print_arvb(ArvB* tree) {
    if (tree != NULL) {
        print_arvb(tree->left);
        printf("%d ", tree->data);
        print_arvb(tree->right);
    }
}

ArvB* insert_arvb(ArvB* tree, const int data) {
    if (tree == NULL) {
        tree = (ArvB*)malloc(sizeof(ArvB));
        tree->data = data;
        tree->left = NULL;
        tree->right = NULL;
    } else if (tree->data > data) {
        tree->left = insert_arvb(tree->left, data);
    } else if (tree->data < data) {
        tree->right = insert_arvb(tree->right, data);
    } else {
        printf("Element already belongs a tree.\n");
    }
    return tree;
}

ArvB* find_max_arvb(ArvB* tree) {
    while (tree->right != NULL) {
        tree = tree->right;
    }
    return tree;
}

ArvB* delete_node_arvb(ArvB* tree) {
    ArvB* temp;
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
    temp = find_max_arvb(tree->left);
    tree->data = temp->data;
    tree->left = delete_arvb(tree->left, temp->data);

    return tree;
}

ArvB* delete_arvb(ArvB* tree, const int data) {
    if (tree != NULL) {
        if (data < tree->data) {
            tree->left = delete_arvb(tree->left, data);
        } else if (data > tree->data) {
            tree->right = delete_arvb(tree->right, data);
        } else {
            tree = delete_node_arvb(tree);
        }
    }
    return tree;
}

int folhas_primos(ArvB* tree) {
    if (tree == NULL) return 0;
    if (tree->right == NULL && tree->left == NULL) {
        int count = eh_primo(tree->data);
        return count + folhas_primos(tree->left) + folhas_primos(tree->right);
    }
    return folhas_primos(tree->left) + folhas_primos(tree->right);
}

int eh_primo(const int data) {
    if (data < 2) return 0;

    int isPrime = 1;
    for (int i = 2; i * i <= data; i++) {
        if (data % i == 0) {
            isPrime = 0;
            break;
        }
    }
    return isPrime;
}

int dois_filhos(ArvB* tree) {
    if (tree == NULL) return 0;
    int count = tem_filhos(tree);
    return count + dois_filhos(tree->left) + dois_filhos(tree->right);
}

int tem_filhos(ArvB * arvb) {
    if (arvb->left != NULL &&
        arvb->right != NULL) return 1;
    return 0;
}

int nos_igual_altura(ArvB* tree) {
    if (tree == NULL) return 0;
    int count = verificar_condicoes(tree);
    return count + nos_igual_altura(tree->left) + nos_igual_altura(tree->right);
}

int verificar_condicoes(ArvB* arvb) {
    if (arvb->left != NULL &&
        arvb->right != NULL &&
        arv_altura(arvb->left) == arv_altura(arvb->right)) return 1;
    return 0;
}

int arv_altura(ArvB* tree) {
    if (tree == NULL) return -1;

    const int left_height = arv_altura(tree->left);
    const int right_height = arv_altura(tree->right);

    if (left_height > right_height) return 1 + left_height;
    return 1 + right_height;
}

int iguais(ArvB* tree1, ArvB* tree2) {
    if (tree1 == NULL && tree2 == NULL) return 1;
    if (tree1 == NULL || tree2 == NULL) return 0;
    if (tree1->data != tree2->data) return 0;
    return iguais(tree1->left, tree2->left) && iguais(tree1->right, tree2->right);
}

// Teste
int main() {
    ArvB* arv1 = create_arvb();
    arv1 = insert_arvb(arv1, 19);
    arv1 = insert_arvb(arv1, 5);
    arv1 = insert_arvb(arv1, 21);
    arv1 = insert_arvb(arv1, 4);
    arv1 = insert_arvb(arv1, 43);
    arv1 = insert_arvb(arv1, 11);
    arv1 = insert_arvb(arv1, 17);

    printf("Altura da arvore: %d\n", arv_altura(arv1));
    printf("Qtd folhas primos: %d\n", folhas_primos(arv1));
    printf("Qtd de nos dois filhos: %d\n", dois_filhos(arv1));
    printf("Nos igual altura: %d\n", nos_igual_altura(arv1));

    ArvB* arv2 = create_arvb();
    arv2 = insert_arvb(arv2, 7);
    arv2 = insert_arvb(arv2, 6);
    arv2 = insert_arvb(arv2, 11);

    ArvB* arv3 = create_arvb();
    arv3 = insert_arvb(arv3, 7);
    arv3 = insert_arvb(arv3, 6);
    arv3 = insert_arvb(arv3, 11);

    print_arvb(arv1);
    printf("\n");
    print_arvb(arv2);
    printf("\n");

    int comp = iguais(arv1, arv2);
    printf("Arvores iguais: %d\n", comp);

    comp = iguais(arv2, arv3);
    printf("Arvores iguais: %d\n", comp);

    destroy_arvb(arv1);
    destroy_arvb(arv2);
    destroy_arvb(arv3);

    // O código a seguir verifica o SO em que o programa
    // é executado, pois este foi escrito em IDE instalada em linux.
    // Desconsidere se sua máquina roda Windows.
    #ifdef _WIN32
        system("PAUSE");
    #else
        getchar();
    #endif

return 0;
}