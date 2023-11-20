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

    InsVFirst(&myList, elem1);
    InsVLast(&myList, elem2);
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
    addressLL foundElem = SearchLL(myList, searchElem);

    if (foundElem != NilLL) {
        printf("Elemen \"%s\" ada di dalam list.\n", searchElem);
    } else {
        printf("Element \"%s\" tidak ada di dalam list list.\n", searchElem);
    }

    // Hapus elemen pertama
    char deletedElem1[NMax];
    DelVFirst(&myList, deletedElem1);
    printf("Elemen pertama yang dihapus: %s\n", deletedElem1);

    // Display setelah dihapus
    printf("Linked List: \n");
    displayLinkedList(myList);
    printf("\n");

    // Hapus Elemen Terakhir
    char deletedElem2[NMax];
    DelVLast(&myList, deletedElem2);
    printf("Elemen terakhir yang dihapus: %s\n", deletedElem2);

    // Display setelah dihapus
    printf("Linked List: \n");
    displayLinkedList(myList);
    printf("\n");

    return 1;
}

// gcc src/ADT/Linked_List/driver_listlinier.c src/ADT/Linked_list/listlinier.c src/ADT/Mesin_Kata/mesinkata.c -o main
