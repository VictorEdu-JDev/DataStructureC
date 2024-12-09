#include <stdlib.h>
#include "interfaces/queue.h"

int main(void) {

    Queue* queue = que_create();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60);

    que_print(queue);

    dequeue(queue);

    que_print(queue);

    dequeue(queue);

    que_print(queue);

    dequeue(queue);

    que_print(queue);

    que_destroy(queue);

    return EXIT_SUCCESS;
}
