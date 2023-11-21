#include "listlinier.h"

boolean IsEmptyLL(LinkedList L)
{
    return First(L) == NilLL;
}

void CreateEmptyLL(LinkedList *L)
{
    First(*L) = NilLL;
}

addressLL AlokasiLL(infotypeLL* X)
{
    addressLL P;
    P = (addressLL) malloc(504*NMax);
    if (P != NilLL)
    {
        stringCopy(P->info, X);
        P->next = NilLL;
    }
    return P;
}

void Dealokasi(addressLL *P)
{
    free(*P);
}

addressLL SearchLL(LinkedList L, infotypeLL* X)
{
    addressLL P = First(L);
    boolean isFound = false;
    while (P != NilLL && !isFound)
    {
        if (CompareString(P->info, X)) isFound = true;
        else P = Next(P);
    }
    return P;
}

void InsVFirst(LinkedList *L, infotypeLL* X)
{
    addressLL P = AlokasiLL(X);
    if (P != NilLL)
        InsertFirst(L, P);
}

void InsertLastLL(LinkedList* L, infotypeLL* X){
    addressLL p = L->First;
    addressLL np = AlokasiLL(X);
    if (IsEmptyLL(*L))
    {
        L->First = np;
        return;
    }
    while (p->next != NilLL) p = p->next;
    p->next = np;
}

void InsVLast(LinkedList *L, infotypeLL* X)
{
    addressLL P = AlokasiLL(X);
    if (P != NilLL)
        InsertLast(L, P);
}

void DelVFirst(LinkedList *L, infotypeLL *X)
{
    addressLL P;
    DelFirst(L, &P);
    stringCopy(X, P->info);
    Dealokasi(&P);
}

void DelVLast(LinkedList *L, infotypeLL *X)
{
    addressLL P;
    DelLast(L, &P);
    stringCopy(X, P->info);
    Dealokasi(&P);
}

void InsertFirst(LinkedList *L, addressLL P)
{
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter(LinkedList *L, addressLL P, addressLL Prec)
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast(LinkedList *L, addressLL P)
{

    if (IsEmptyLL(*L))
        InsertFirst(L, P);
    else
    {
        addressLL last = First(*L);
        while (Next(last) != NilLL)
            last = Next(last);
        InsertAfter(L, P, last);
    }
}

void DelFirst(LinkedList *L, addressLL *P)
{
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P) = NilLL;
}

void DelP(LinkedList *L, infotypeLL* X)
{
    addressLL P = SearchLL(*L, X);
    if (P != NilLL)
    {
        if (P == First(*L))
            DelFirst(L, &P);
        else
        {
            addressLL Prec = First(*L);
            while (Next(Prec) != P)
                Prec = Next(Prec);
            DelAfter(L, &P, Prec);
        }
    }
}

void DelLast(LinkedList *L, addressLL *P)
{
    addressLL last = First(*L);
    addressLL Prec = NilLL;
    while (Next(last) != NilLL)
    {
        Prec = last;
        last = Next(last);
    }

    *P = last;
    if (Prec == NilLL)
        First(*L) = NilLL;
    else
        Next(Prec) = NilLL;
}

void DelAfter(LinkedList *L, addressLL *Pdel, addressLL Prec)
{
    *Pdel = Next(Prec);
    if (Next(Prec) != NilLL)
    {
        Next(Prec) = Next(Next(Prec));
        Next(*Pdel) = NilLL;
    }
}

void PrintInfo(LinkedList L)
{
    addressLL P;
    printf("[");
    if (!IsEmptyLL(L))
    {
        P = First(L);
        while (P != NilLL)
        {
            if (P != First(L))
                printf(",");
            printf("%s", Info(P));
            P = Next(P);
        }
    }
    printf("]\n");
}

int NbElmt(LinkedList L)
{
    if (IsEmptyLL(L)) return 0;
    int count = 1;
    addressLL P = First(L);
    while (P->next != NilLL)
    {
        P = Next(P);
        count++;
    }
    return count;
}

void displayLinkedList(LinkedList L){
    int idx = 1;
    addressLL P = First(L);
    while (P != NilLL)
    {
        printf("  %d. %s\n", idx, P->info);
        idx++;
        P = P->next;
    }
}

void swapLinkedList(LinkedList* L, int x, int y){
    if (x > y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    x--; y--;

    char temp[100][NMax];
    int n = 0;
    addressLL p = L->First;
    while (p != NULL)
    {
        stringCopy(temp[n], p->info);
        n++;
        p = p->next;
    }
    CreateEmptyLL(L);

    for (int i = 0; i < n; ++i)
    {
        if (i == x)
        {
            InsertLastLL(L, temp[y]);
        }
        else if (i == y)
        {
            InsertLastLL(L, temp[x]);
        }
        else
        {
            InsertLastLL(L, temp[i]);
        }
    }

}