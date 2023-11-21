#include <stdio.h>
#include <stdlib.h>
#include "quit.h"

void QuitBeforeLoaded(){
    printf("Anda keluar dari WayangWave\n See u when I see u ^_^ ...\n");
    exit(0);
}

void QuitAfterLoaded(){
    printf("Apakah kamu ingin menyimpan data sesi sekarang?");
    ADVWORD();
    if (isEqual(-1, "Y"))
    {
        save();
    }        
    printf("\nAnda keluar dari WayangWave\n See u when I see u ^_^ ...\n");
    exit(0);
}