#include "mesinbaris.h"

int main(){
    char path[NMax] = "src/ADT/Mesin_Baris/contoh.txt";
    STARTFILE(path);
    ADVFILE(true);
    printf("=== ADVFILE(true) ===\n");
    printf("currentInt : %d\n", currentInt);
    printf("currentLine : %s\n", currentLine.TabWord);
    printf("isEOF : ");

    ADVFILE(false);
    printf("\n=== ADVFILE(false) ===\n");
    printf("currentInt : %d\n", currentInt);
    printf("currentLine : %s\n", currentLine.TabWord);
    printf("isEOF : ");

    while (!isEOF()) ADVFILE(false);
    printf(isEOF() ? "true" : "false");
}

// gcc src/ADT/Mesin_Baris/driv_baris.c src/ADT/Mesin_Baris/mesinbaris.c -o tes