//
// Created by Victor on 27/01/2025.
//
#include <stdbool.h>
#include "../interfaces/sorting.h"

#include <stdio.h>
#include <stdlib.h>

int partition(int *v, int n);
void swap(int *a, int *b);
void merge(int arr[], int beg, int mid, int end);
void heapify(int *heap, int n);
void restore_heap_down(int *heap, int index, int n);

void bubble_sort(int size, int *array) {
    int i, j, temp;
    bool trocou;

    for (i = size - 1; i > 0; i--) {
        trocou = false;

        for (j = 0; j < i; j++) {
            if (array[j] > array[j + 1]) {
                // Troca os valores
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                trocou = true;
            }
        }

        if (!trocou) {
            break;
        }
    }
}

void quick_sort(int n, int *v) {
    if (n > 1) {
        int pivot_index = partition(v, n);
        quick_sort(pivot_index, v);
        quick_sort(n - pivot_index - 1, v + pivot_index + 1);
    }
}

int partition(int *v, int n) {
    int pivot = v[0];  // Pivô
    int left = 1;      // Índice que avança da esquerda
    int right = n - 1; // Índice que retrocede da direita

    while (1) {
        while (left < n && v[left] <= pivot) left++;
        while (v[right] > pivot) right--;

        if (left < right) {
            swap(&v[left], &v[right]);
            left++;
            right--;
        } else {
            break;
        }
    }

    // Coloca o pivô na posição correta
    swap(&v[0], &v[right]);
    return right; // Retorna o índice do pivô
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(int size, int *arr) {
    int i, j, temp;
    for (i = 1; i < size; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(int arr[], int beg, int mid, int end) {
    int i = beg, j = mid + 1, index = beg, *temp, k;

    temp = (int *)malloc((end - beg + 1) * sizeof(int));

    if (temp == NULL) {
        return;
    }

    while ((i <= mid) && (j <= end)) {
        if (arr[i] < arr[j]) {
            temp[index - beg] = arr[i];
            i++;
        } else {
            temp[index - beg] = arr[j];
            j++;
        }
        index++;
    }

    if (i > mid) {
        while (j <= end) {
            temp[index - beg] = arr[j];
            j++;
            index++;
        }
    } else {
        while (i <= mid) {
            temp[index - beg] = arr[i];
            i++;
            index++;
        }
    }

    for (k = beg; k <= end; k++) {
        arr[k] = temp[k - beg];
    }

    free(temp);
}

void merge_sort(int size, int arr[]) {
    int beg = 0, end = size - 1, mid;

    if (beg < end) {
        mid = (beg + end) / 2;
        merge_sort(mid + 1, arr);
        merge_sort(mid, arr);
        merge(arr, beg, mid, end);
    }
}

void heap_sort(int size, int *heap) {
    int j;
    // Construir o heap
    for (j = size / 2; j >= 1; j--) {
        restore_heap_down(heap, j, size); // Rearranja os elementos para formar um heap
    }

    // Ordenação
    for (j = size; j >= 2; j--) {
        int temp = heap[1];
        heap[1] = heap[j];
        heap[j] = temp; // Troca a raiz com o último elemento

        // Restabelece o heap
        restore_heap_down(heap, 1, j - 1); // Heapify após a troca
    }
}

void restore_heap_down(int *heap, int index, int n) {
    int val = heap[index];
    int j = index * 2;  // Filho esquerdo

    while (j <= n) {
        if (j < n && heap[j] < heap[j + 1]) { // Se o filho direito for maior
            j++; // Vai para o filho direito
        }
        if (val >= heap[j]) {
            break; // Se o valor do nó já for maior ou igual aos filhos, interrompe
        }
        heap[index] = heap[j];
        index = j;
        j = index * 2; // Filho esquerdo
    }
    heap[index] = val;
}
