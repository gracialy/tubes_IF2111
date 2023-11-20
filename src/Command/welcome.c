#include <stdio.h>
#include <stdlib.h>
#include "welcome.h"
#include <time.h>
#include <math.h>
void loading() 
/* loading.. */
{
/* KAMUS LOKAL */
    int i, j, delay;

/* ALGORITMA */
    printf("accessing WayangWave ");

    for(i = 0; i < 10; i++) { // jumlah '>'
        for(j = 0; j < 100000000; j++) { // buat delay prosesnya
            delay = j;
        }
        printf(">");
    }

    printf(" [COMPLETE]\n\n");

    for(j = 0; j < 100099999 ; j++) { //delay lagi
        delay = j;
        }
}

void welcome()
{
    /* ALGORITMA */
    loading();
    printf("        ***********  W  E  L  C  O  M  E     T  O  *********** \n");
    printf("               _   _   _   _   _   _   _   _   _   _  \n");
    printf("              / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ \n");
    printf("             ( W | A | Y | A | N | G | W | A | V | E )\n");
    printf("              \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \n");
    printf("                                                                    \n");
    printf("    ******************************************************************** \n");
    printf("                    c h o o s e  << START >>  o r  << LOAD >> \n"); 
    printf("                          o r >> HELP << to see command \n");
    }