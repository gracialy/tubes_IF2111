#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main() {
    LinkedList myList;
    CreateEmptyLL(&myList);

    // Input elemen ke dalam List
    char elem1[] = "A";
    char elem2[] = "B";
    char elem3[] = "C";
    char elem4[] = "D";

    InsertLastLL(&myList, elem1);
    InsertLastLL(&myList, elem2);
    InsertLastLL(&myList, elem3);
    InsertLastLL(&myList, elem4);

    // Display the linked list
    printf("Linked List: \n");
    displayLinkedList(myList);
    printf("\n");

    // Swap elements at positions 1 and 2
    swapLinkedList(&myList, 1, 2);

    // Contoh menampilkan list
    printf("List setelah Swap: \n");
    displayLinkedList(myList);
    printf("\n");

    // Mencari sebuah elemen di List
    char searchElem[] = "B";
    boolean foundElem = isMemberLL(myList, searchElem);

    if (foundElem) {
        printf("Elemen \"%s\" ada di dalam list.\n", searchElem);
    } else {
        printf("Element \"%s\" tidak ada di dalam list list.\n", searchElem);
    }

    // Hapus elemen pertama
    RemoveLL(&myList, 1);
    printf("Elemen pertama berhasil dihapus\n");

    // Display setelah dihapus
    printf("Linked List: \n");
    displayLinkedList(myList);
    printf("\n");

    // Hapus Elemen Terakhir
    char deletedElem2[NMax];
    RemoveLL(&myList, NbElmt(myList));
    printf("Elemen terakhir berhasil dihapus\n");

    // Display setelah dihapus
    printf("Linked List: \n");
    displayLinkedList(myList);
    printf("\n");

    return 1;
}

// gcc src/ADT/Linked_List/driver_listlinier.c src/ADT/Linked_list/listlinier.c src/ADT/Mesin_Kata/mesinkata.c -o main
