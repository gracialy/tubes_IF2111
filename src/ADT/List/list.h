#include "../Linked_List/listlinier.h"
#include "../Mesin_Kata/mesinkata.h"
#include "../../Command/boolean.h"

#ifndef __ARRAY_DINAMIK__
#define __ARRAY_DINAMIK__

// Boolean

#define InitialSize 10

typedef int IdxTypeL;
typedef LinkedList ElTypeL;
typedef struct {
    ElTypeL *A;
    int Capacity;
    int Neff;
} List;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
List MakeList();

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDIN(List *array);

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmptyL(List array);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int lengthL(List array);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElTypeL GetL(List array, IdxTypeL i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(List array);

void AddElementL(List* GE, char* playlistName);


/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(List *array, IdxTypeL i);

void DisplayList(List L);

#endif