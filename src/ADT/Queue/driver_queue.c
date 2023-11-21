#include <stdio.h>
#include "circular_queue.h"

int main() {
    Queue Q;
    CreateQueue(&Q);

    char song1[] = "Song 1";
    char song2[] = "Song 2";
    char song3[] = "Song 3";

    enqueue(&Q, song1);
    enqueue(&Q, song2);
    enqueue(&Q, song3);

    displayQueue(Q);

    char target[NMax];
    dequeue(&Q, target);
    printf("Dequeued: %s\n", target);

    displayQueue(Q);

    char song4[] = "Song 4";
    insertFirstQueue(&Q, song4);
    printf("After inserting at the beginning:\n");
    displayQueue(Q);

    return 0;
}
