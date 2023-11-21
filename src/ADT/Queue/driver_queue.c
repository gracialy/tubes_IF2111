#include <stdio.h>
#include "circular_queue.h"

int main(){
    Queue Q1,Q2;
    char* temp;
    CreateQueue(&Q1);
    CreateQueue(&Q2);
    for (int i =1; i <= 100; ++i) {
        enqueue(&Q1, i);
    }
    if (IsFull(Q1)){
        for(int i=1;i <= 50;i++)
        {
            dequeue(&Q1, temp);
            enqueue(&Q2,i);
        }
        insertFirstQueue(&Q1, "inserted");
        displayQueue(Q1);
        displayQueue(Q2);
        int a = Length(Q1);
        int b = Length(Q2);
        printf("Banyak elemen pada Q1 adalah %d dan Banyak elemen pada Q2 adalah %d", a,b);
    }
}