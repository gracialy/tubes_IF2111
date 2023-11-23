#include <stdio.h>
#include <stdlib.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOL;
static FILE *pita;
int retval = 1;

void START(char* path) {
    /* Mesin siap dioperasikan. Pita disiapkan ... */
    /* Algoritma */
    pita = fopen(path, "r");
    ADV();
}

void ADV() {
    /* Pita dimajukan satu karakter. ... */
    /* Algoritma */
    retval = fscanf(pita, "%c", &currentChar);
    // if (isEOF()) 
    // {
    //     fclose(pita);
    // }
}

boolean isEOF(){
    return feof(pita);
}

void closeFile(){
    fclose(pita);
}