#include <stdio.h>
#include "mesinkata.h"

int main() {
    // Mulai membaca file
    STARTWORD();

    // Membaca dan mencetak setiap kata sampai MARK
    while (currentInput != MARK) {
        printf("%s\n", currentWord.TabWord);
        ADVWORD();
    }

    // Membandingkan dua string
    char str1[] = "Hello ";
    char str2[] = "World";
    if (CompareString(str1, str2)) {
        printf("String sama.\n");
    } else {
        printf("String berbeda.\n");
    }

// Membandingkan dua string
    char str3[] = "ALSTRUKDAT";
    char str4[] = "ALSTRUKDAT";
    if (CompareString(str3, str4)) {
        printf("String sama.\n");
    } else {
        printf("String berbeda.\n");
    }
    // Menggabungkan dua string
    char output[NMax];
    konkatString(output, str1, str2);
    printf("String gabungan: %s\n", output);

    return 0;
}

// gcc src/ADT/Mesin_Kata/driv_kata.c src/ADT/Mesin_Kata/mesinkata.c src/ADT/Mesin_Karakter/mesinkarakter.c -o tes
