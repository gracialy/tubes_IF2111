#include <stdio.h>
#include "mesinkarakter.h"

int main() {
    // Mulai membaca file
    START("src/ADT/Mesin_Karakter/contoh.txt");

    // Membaca dan mencetak setiap karakter sampai EOF
    while (!isEOF()) {
        printf("%c", currentChar);
        ADV();
    }

    // Menutup file
    closeFile();

    return 0;
}

// gcc src/ADT/Mesin_Karakter/driv_kar.c src/ADT/Mesin_Karakter/mesinkarakter.c -o tes