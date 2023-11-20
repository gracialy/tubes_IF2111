#include <stdio.h>
#include "set.h"

int main() {
    // Membuat set kosong
    Set S;
    CreateEmpty(&S);

    // Memeriksa apakah set kosong
    if (IsEmpty(S)) {
        printf("Set kosong.\n");
    }

    // Menambahkan elemen ke set
    char elemen1[] = "1";
    InsertSet(&S, elemen1);

    char elemen2[] = "2";
    InsertSet(&S, elemen2);

    char elemen3[] = "3";
    InsertSet(&S, elemen3);

    char elemen4[] = "4";
    InsertSet(&S, elemen4);

    // Mencetak elemen-elemen dalam set
    PrintSet(S);

    // Memeriksa apakah sebuah elemen adalah anggota dari set
    if (IsMember(S, elemen1)) {
        printf("%s adalah anggota dari set.\n", elemen1);
    }

    // Mengubah nama set
    char namaBaru[] = "Set Baru";
    RenameSet(&S, namaBaru);

    return 1;
}

// gcc src/ADT/Set/driv_set.c src/ADT/Set/set.c -o tes