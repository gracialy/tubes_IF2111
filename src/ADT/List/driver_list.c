#include <stdio.h>
#include "list.h"

int main() {
    
    List myList = MakeList();

   
    if (IsEmptyL(myList)) {
        printf("List is empty.\n");
    }

    
    char playlist1[] = "Playlist 1";
    AddElementL(&myList, playlist1);

    char playlist2[] = "Playlist 2";
    AddElementL(&myList, playlist2);
    DisplayList(myList);

  
    DeleteAt(&myList, 1);
    DisplayList(myList);

    return 1;
}
// gcc src/ADT/List/driver_list.c src/ADT/List/list.c src/ADT/Linked_list/listlinier.c src/ADT/Mesin_Kata/mesinkata.c -o main

