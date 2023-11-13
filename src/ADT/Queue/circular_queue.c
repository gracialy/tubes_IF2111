#include <stdio.h>
#include "circular_queue.h"

boolean IsEmpty (Queue Q) {
    return (IDX_HEAD(Q) == IDX_UNDEF) && (IDX_TAIL(Q) == IDX_UNDEF);
}

boolean IsFull (Queue Q) {
    if (IDX_HEAD(Q) > IDX_TAIL(Q)) {
        return IDX_HEAD(Q) - IDX_TAIL(Q) == 1;
    } else {
        return IDX_HEAD(Q) == 0 && IDX_TAIL(Q) == IDX_MAX; 
    }
}

int Length (Queue Q) {
    if (IsEmpty(Q)) {
        return 0;
    } else if (IDX_HEAD(Q) > IDX_TAIL(Q)) {
        return IDX_MAX - IDX_HEAD(Q) + IDX_TAIL(Q) + 2;
    } else {
        return IDX_TAIL(Q) - IDX_HEAD(Q) + 1;
    }
}

void CreateQueue (Queue * Q) {
    IDX_HEAD(*Q) = IDX_UNDEF;
    IDX_TAIL(*Q) = IDX_UNDEF;
}

void enqueue (Queue * Q, ElType* X) {
    if (IsEmpty(*Q)) {
        IDX_HEAD(*Q) = 0;
        IDX_TAIL(*Q) = 0;
    } else {
        if (IDX_TAIL(*Q) == IDX_MAX) {
            IDX_TAIL(*Q) = 0;
        } else {
            IDX_TAIL(*Q)++;
        }
    }
    setElementQueue(TAIL(*Q), X);
}

void dequeue (Queue * Q, char* target) {
    setElementQueue(target, HEAD(*Q));
    if (IDX_HEAD(*Q) == IDX_TAIL(*Q)) {
        IDX_HEAD(*Q) = IDX_UNDEF;
        IDX_TAIL(*Q) = IDX_UNDEF;
    } else {
        if (IDX_HEAD(*Q) == IDX_MAX) {
            IDX_HEAD(*Q) = 0;
        } else {
            IDX_HEAD(*Q)++;
        }
    }
}

void displayQueue (Queue Q) {
    if (IsEmpty(Q)) {
        printf("[]\n");
    } else {
        int i = IDX_HEAD(Q);
        printf("[");
        while (i != IDX_TAIL(Q)) {
            printf("%s,", Q.Tab[i]);
            if (i == IDX_MAX) {
                i = 0;
            } else {
                i++;
            }
        }
        printf("%s]\n", Q.Tab[i]);
    }
}

void setElementQueue(char* target, char* copy){
    int i;
    for (i = 0; copy[i] != '\0'; ++i)
    {
        target[i] = copy[i];
    }
    copy[i] =  '\0';
}