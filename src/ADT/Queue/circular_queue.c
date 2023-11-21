#include <stdio.h>
#include "circular_queue.h"

boolean IsEmptyQ (Queue Q) {
    return (IDX_HEAD(Q) == IDX_UNDEF) && (IDX_TAIL(Q) == IDX_UNDEF);
}

boolean IsFullQ (Queue Q) {
    if (IDX_HEAD(Q) > IDX_TAIL(Q)) {
        return IDX_HEAD(Q) - IDX_TAIL(Q) == 1;
    } else {
        return IDX_HEAD(Q) == 0 && IDX_TAIL(Q) == IDX_MAX; 
    }
}

int LengthQ (Queue Q) {
    if (IsEmptyQ(Q)) {
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
    if (IsEmptyQ(*Q)) {
        IDX_HEAD(*Q) = 0;
        IDX_TAIL(*Q) = 0;
    } else {
        if (IDX_TAIL(*Q) == IDX_MAX) {
            IDX_TAIL(*Q) = 0;
        } else {
            IDX_TAIL(*Q)++;
        }
    }
    stringCopy(TAIL(*Q), X);
}

void dequeue (Queue * Q, char* target) {
    stringCopy(target, HEAD(*Q));
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
    int i = IDX_HEAD(Q), idx = 1;
    printf("[");
    while (i != IDX_TAIL(Q)) {
        printf("%d. %s\n", idx, Q.Tab[i]);
        idx ++;
        if (i == IDX_MAX) 
        {
            i = 0;
        } 
        else 
        {
            i++;
        }
    }
    printf("%sQ]\n", Q.Tab[i]);
}

void insertFirstQueue(Queue* q, char* song){
    char temp[100][NMax], songTemp[NMax];
    int n = 0;
    while (!IsEmptyQ(*q))
    {
        dequeue(q, songTemp);
        stringCopy(temp[n], songTemp);
    }
    enqueue(q, song);
    for (int i = 0; i < n; ++i)
    {
        enqueue(q, temp[i]);
    }
}