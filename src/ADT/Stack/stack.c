#include "stack.h"
#include <stdio.h>

/* *** Konstruktor/Kreator *** */
void CreateEmptySt (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
    S->TOP = NilSt;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptySt (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (S.TOP == NilSt);
}

boolean IsFullSt (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return (Top(S)==MaxEl-1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infotypeSt* X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    S->TOP ++;
    stringCopy(S->T[S->TOP], X);
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infotypeSt* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    stringCopy(X, S->T[S->TOP]);
    S->TOP --;
}
