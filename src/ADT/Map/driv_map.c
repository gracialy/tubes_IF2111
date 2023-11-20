#include <stdio.h>
#include "map.h"

int main() {
    // Membuat map kosong
    Map M;
    CreateMapEmpty(&M);

    // Memeriksa apakah map kosong
    if (IsMapEmpty(M)) {
        printf("Map kosong.\n");
    }

    // Menambahkan elemen ke map
    Set k1;
    char v1[] = "1";
    InsertMap(&M, k1, v1);

    Set k2;
    char v2[] = "2";
    InsertMap(&M, k2, v2);

    // Mencetak map
    PrintMap(M);

    // Mendapatkan nilai dari sebuah kunci
    printf("Nilai dari kunci pertama: %s\n", Value(M, "Key1"));

    // Memeriksa apakah sebuah kunci adalah anggota dari map
    if (IsMemberMap(M, "1")) {
        printf("1 adalah anggota dari map.\n");
    }

    // Menghapus elemen dari map
    DeleteMap(&M, "1");

    // Mencetak map setelah penghapusan
    PrintMap(M);

    return 0;
}
// gcc src/ADT/Map/driv_map.c src/ADT/Map/map.c src/ADT/Mesin_Kata/mesinkata.c src/ADT/Set/set.c -o tes