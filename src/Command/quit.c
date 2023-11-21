#include <stdio.h>
#include <stdlib.h>
#include "quit.h"

void loadingQuit() 
/* loading.. */
{
/* KAMUS LOKAL */
    int i, j, delay;

/* ALGORITMA */
    printf("\n");
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

void bannerQuit(){
    printf("\n");
    printf("        	  ***********  G O O D   B Y E  *********** \n");
    printf("					                				\n");
    printf("          		Anda keluar dari WayangWave	\n");
    printf("           Sampai Bertemu di waktu dimana kita akan dipertemukan kembali \n");
    printf("               		       See u ^__^                    \n");
    printf("                                                                    \n");
    printf("    ************************************************************************ \n");
    printf("\n");
}
void QuitBeforeLoaded(){
    loadingQuit();
    bannerQuit();
    exit(0);
}

void QuitAfterLoaded(){
    printf("Apakah kamu ingin menyimpan data sesi sekarang?(Y/N) ");
    ADVWORD();
    if (isEqual(-1, "Y"))
    {
        save();
        loadingQuit();       
        bannerQuit();
    }
    else if(isEqual(-1, "N"))
    {
        loadingQuit();       
        bannerQuit();
    }
    else
    {
        printf("Command yang anda masukkan tidak valid. Silahkan pilih Y/N.\n");
        printf(">> ");
        QuitAfterLoaded();
    }
    
    exit(0);
}