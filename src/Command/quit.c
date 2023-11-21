#include <stdio.h>
#include <stdlib.h>
#include "quit.h"

void Quit(char listArtis[maxA][maxAN], Map* listAlbum, char* currentSong, 
    Queue* songQueue, Stack* songHistory, List* listPlaylist){
    printf("Apakah kamu ingin menyimpan data sesi sekarang?");
    ADVWORD();
    if (isEqual(-1, "Y"))
    {
        save(listArtis[maxA][maxAN], listAlbum, currentSong, 
        songQueue, songHistory, listPlaylist);
    }        
    printf("\nAnda keluar dari WayangWave\n See u when I see u ^_^ ...\n");
    exit(0);
}