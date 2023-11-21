#include <stdio.h>
#include <stdlib.h>
#include "quit.h"

void loadingQuit() 
/* loading.. */
{
/* KAMUS LOKAL */
    int i, j, delay;

/* ALGORITMA */
    for(i = 0; i < 10; i++) { // jumlah '>'
        for(j = 0; j < 100000000; j++) { // buat delay prosesnya
            delay = j;
        }
        printf(">");
    }

    printf("        Quit from WayangWave        ");

    for(i = 0; i < 10; i++) { // jumlah '>'
        for(j = 0; j < 100000000; j++) { // buat delay prosesnya
            delay = j;
        }
        printf("<");
    }

    printf(" [COMPLETE]\n\n");

    for(j = 0; j < 100099999 ; j++) { //delay lagi
        delay = j;
        }
}
void QuitBeforeLoaded(){
    loadingQuit();
    printf("        	  ***********  G O O D   B Y E  *********** \n");
    printf("					                				\n");
    printf("          		Anda keluar dari WayangWave	\n");
    printf("           Sampai Bertemu di waktu dimana kita akan dipertemukan kembali \n");
    printf("               		       See u ^__^                    \n");
    printf("                                                                    \n");
    printf("    ************************************************************************ \n");
    printf("\n");
    exit(0);
}

void QuitAfterLoaded(){
    printf("Apakah kamu ingin menyimpan data sesi sekarang?");
    ADVWORD();
    if (isEqual(-1, "Y"))
    {
        save();
    }
    loadingQuit();       
    printf("        	  ***********  G O O D   B Y E  *********** \n");
    printf("					                				\n");
    printf("          		Anda keluar dari WayangWave	\n");
    printf("           Sampai Bertemu di waktu dimana kita akan dipertemukan kembali \n");
    printf("               		       See u ^__^                    \n");
    printf("                                                                    \n");
    printf("    ************************************************************************ \n");
    printf("\n");
    exit(0);
}