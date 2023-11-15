#include <stdio.h>
#include "circular_queue.c"

int main(){
    Queue Q;
    CreateQueue(&Q);
    enqueue(&Q, 1);
    enqueue(&Q, 2);
    enqueue(&Q, 3);
    enqueue(&Q, 4);
    enqueue(&Q, 5);
    displayQueue(Q);
}