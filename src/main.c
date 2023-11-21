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
    MakeList(&listPlaylist);
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
            // if (isPathValid(command)) 
            // {
            //     loaded = true;
            // }
            // else{
            //     printf(">> ");
            // }
            loaded = true;
        }
        else if (isEqual(0,"HELP"))
        {
            helpBeforeLoad();
            printf(">> ");
        }
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
            if (isEqual(1, "DEFAULT")) ListDefault(listArtis, listAlbum);
            else if (isEqual(1, "PLAYLIST")) showPlaylist(listPlaylist);
        }
        else if (isEqual(0, "HELP"))
        {
            helpAfterLoad();
        }
        
        else if (isEqual(0, "PLAY"))
        {
            if (isEqual(1, "SONG")) playSong(currentSong, listArtis, listAlbum, &songQueue, currentPlaylist);
            else if (isEqual(1, "PLAYLIST")) playPlaylist(currentSong, &songQueue, listPlaylist, &songHistory, currentPlaylist);
        }
        else if (isEqual(0, "QUEUE"))
        {
            if (isEqual(1, "SONG")) queueSong(listAlbum, listArtis, &songQueue);
            else if (isEqual(1, "PLAYLIST")) queuePlaylist(listPlaylist, &songQueue, currentAlbum);
            else if (isEqual(1, "SWAP")) queueSwap(&songQueue);
            else if (isEqual(1, "REMOVE")) queueRemove(&songQueue);
            else if (isEqual(1, "CLEAR")) queueClear(&songQueue);
        }
        else if (isEqual(0, "SONG"))
        {
            if (isEqual(1, "NEXT")) songNext(currentSong, &songQueue, &songHistory, listAlbum);
            else if (isEqual(1, "PREVIOUS")) songPrevious(currentSong, &songQueue, &songHistory, listAlbum);
        }
        else if (isEqual(0, "PLAYLIST"))
        {
            if (isEqual(1, "CREATE")) CreatePlaylist(&listPlaylist, listArtis, listAlbum);
            else if (isEqual(1, "ADD"))
            {
                if (isEqual(2, "SONG")) InsertPlaylist(&listPlaylist, listArtis, listAlbum);
                else if (isEqual(2, "ALBUM")) InsertAlbumToPlaylist(&listPlaylist, listArtis, listAlbum);
            }
            else if (isEqual(1, "DELETE")) playlistDelete(&listPlaylist);
            else if (isEqual(1, "SWAP")) playlistSwap(&listPlaylist);
        }
        else if (isEqual(0, "STATUS")) status(songQueue, currentPlaylist, currentSong, listAlbum);
        else if (isEqual(0, "SAVE")) save(listArtis, &listAlbum, currentSong, &songQueue, &songHistory, &listPlaylist);


        else if(isEqual(0, "SHOWPLAYLIST"))
        {
            addressLL p = listPlaylist.A[0].First;
            for (int i = 0; i < NbElmt(listPlaylist.A[0]); ++i)
            {
                printf("%s\n", p->info);
                p = p->next;
            }
        }
    }
    

}

