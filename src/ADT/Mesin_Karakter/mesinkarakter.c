#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOL;
static FILE *pita;
int retval = 1;

void START() {
    /* Mesin siap dioperasikan. Pita disiapkan ... */
    /* Algoritma */
    pita = fopen("src/Command/konfigurasi.txt", "r");
    ADV();
}

void ADV() {
    /* Pita dimajukan satu karakter. ... */
    /* Algoritma */
    retval = fscanf(pita, "%c", &currentChar);
    // if (!retval) 
    // {
    //     fclose(pita);
    // }
}

boolean isEOF(){
    return feof(pita);
}
