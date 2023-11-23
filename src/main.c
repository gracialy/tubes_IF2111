#include "main.h"

char currentSong[NMax];
char currentPlaylist[NMax];

char listArtis[maxA][maxAN];
Map listAlbum;
List listPlaylist;
Queue songQueue;
Stack songHistory;

int main(){
    char command[NMax];
    char currentAlbum[NMax];
    CreateQueue(&songQueue);
    CreateEmptySt(&songHistory);
    listPlaylist = MakeList();
    CreateMapEmpty(&listAlbum);
    printf("\n");
    // welcome();
    printf("\n");
    printf(">> ");
    STARTWORD();

    boolean loaded = false;
    while (!loaded)
    {
        ADVWORD();
        getWord(0, command);
        if (isEqual(-1, "START"))
        {
            konfigurasi("konfigurasi.txt");
            loaded = true;
        }
        else if (isEqual(0, "LOAD"))
        {
            getWord(1, command);
            konfigurasi(command);
            loaded = true;
        }
        else if (isEqual(0,"HELP"))
        {
            helpBeforeLoad();
            printf(">> ");
        }
        else if (isEqual(0, "QUIT")) QuitBeforeLoaded();
        else if (isEqual(0, "SAVE")) save();
        else
        {
            printf("Command yang dimasukkan tidak valid\n");
            printf(">> ");
        }
    }
    while (loaded)
    {
        printf(">> ");
        ADVWORD();
        if (isEqual(0, "LIST"))
        {
            if (isEqual(1, "DEFAULT")) ListDefault();
            else if (isEqual(1, "PLAYLIST")) showPlaylist();
            else printf("Command yang dimasukkan tidak valid\n");
        }
        else if (isEqual(0, "PLAY"))
        {
            if (isEqual(1, "SONG")) playSong();
            else if (isEqual(1, "PLAYLIST")) playPlaylist();
            else printf("Command yang dimasukkan tidak valid\n");
        }
        else if (isEqual(0, "QUEUE"))
        {
            if (isEqual(1, "SONG")) queueSong();
            else if (isEqual(1, "PLAYLIST")) queuePlaylist();
            else if (isEqual(1, "SWAP")) queueSwap();
            else if (isEqual(1, "REMOVE")) queueRemove();
            else if (isEqual(1, "CLEAR")) queueClear();
            else printf("Command yang dimasukkan tidak valid\n");
        }
        else if (isEqual(0, "SONG"))
        {
            if (isEqual(1, "NEXT")) songNext();
            else if (isEqual(1, "PREVIOUS")) songPrevious();
            else printf("Command yang dimasukkan tidak valid\n");
        }
        else if (isEqual(0, "PLAYLIST"))
        {
            if (isEqual(1, "CREATE")) CreatePlaylist();
            else if (isEqual(1, "ADD"))
            {
                if (isEqual(2, "SONG")) InsertPlaylist();
                else if (isEqual(2, "ALBUM")) InsertAlbumToPlaylist();
                else printf("Command yang dimasukkan tidak valid\n");
            }
            else if (isEqual(1, "REMOVE")) playlistRemove();
            else if (isEqual(1, "DELETE")) playlistDelete();
            else if (isEqual(1, "SWAP")) playlistSwap();
            else printf("Command yang dimasukkan tidak valid\n");
        }
        else if (isEqual(0, "STATUS")) status();
        else if (isEqual(0, "SAVE")) save();
        else if (isEqual(0, "QUIT")) QuitAfterLoaded();
        else if (isEqual(0, "HELP")) helpAfterLoad();
        else printf("Command yang dimasukkan tidak valid\n");
    }
}

