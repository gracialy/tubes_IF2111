#include <stdio.h>
#include "circular_queue.c"

int main(){
    Queue Q1,Q2;
    CreateQueue(&Q1);
    CreateQueue(&Q2);
    for (int i = 1; i <= 100; ++i) {
        enqueue(&Q1, i);
    }
    if (IsFull(Q1)) {
        printf("Q1 penuh");
    }

}