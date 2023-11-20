#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    // Membuat stack kosong
    Stack S;
    CreateEmptySt(&S);

    // Memeriksa apakah stack kosong
    if (IsEmptySt(S)) {
        printf("Stack kosong.\n");
    }

    // Menambahkan elemen ke stack berdasarkan input pengguna
    char elemen[MaxEl];
    printf("Masukkan elemen untuk ditambahkan ke stack (ketik '0' untuk berhenti):\n");
    while (1) {
        fgets(elemen, MaxEl, stdin);
        elemen[strcspn(elemen, "\n")] = 0;  // Menghapus newline dari input
        if (strcmp(elemen, "0") == 0) {
            break;
        }
        Push(&S, elemen);
    }

    // Mencetak elemen-elemen dalam stack
    PrintStack(S);

    // Menghapus elemen dari stack berdasarkan input pengguna
    int jumlahHapus;
    printf("Masukkan jumlah elemen yang ingin dihapus dari stack:\n");
    scanf("%d", &jumlahHapus);
    for (int i = 0; i < jumlahHapus; i++) {
        char elemenHapus[MaxEl];
        Pop(&S, elemenHapus);
        printf("Elemen yang dihapus: %s\n", elemenHapus);
    }

    // Mencetak elemen-elemen dalam stack setelah penghapusan
    PrintStack(S);

    return 0;
}
// gcc src/ADT/Stack/driv_st.c src/ADT/Stack/stack.c src/ADT/Mesin_Kata/mesinkata.c -o tes