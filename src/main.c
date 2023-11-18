#include "main.h"
#include<stdio.h>
char currentSong[NMax];
char currentPlaylist[NMax];

char listArtis[100][50];
Map listAlbum;
List listPlaylist;
Queue songQueue;
Stack songHistory;

int main(){
    char command[NMax];
    char currentAlbum[NMax];
    CreateQueue(&songQueue);
    CreateEmptySt(&songHistory);
    MakeList(&listPlaylist);
    CreateMapEmpty(&listAlbum);
    printf(">> ");
    STARTWORD();
    ADVWORD();

    boolean loaded = false;
    while (!loaded)
    {
        getWord(0, command);
        if (isEqual(-1, "START"))
        {
            konfigurasi(listArtis, &listAlbum, "konfigurasi.txt", currentSong, &songQueue, &songHistory, &listPlaylist);
            loaded = true;
        }
        else if (isEqual(0, "LOAD"))
        {
            getWord(1, command);
            konfigurasi(listArtis, &listAlbum, command, currentSong, &songQueue, &songHistory, &listPlaylist);
            loaded = true;
        }
        else if (isEqual(-1, "HELP"))
        {
            helpBeforeLoad();
        }
        else printf("Command yang dimasukkan tidak valid\n");
    }
}