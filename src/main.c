#include "main.h"

char listArtis[100][50];
Map listAlbum;

int main(){
    char command[NMax];
    char currentAlbum[NMax];
    Queue songQueue;
    CreateQueue(&songQueue);
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
            konfigurasi(listArtis, &listAlbum, "src/save/konfigurasi.txt");
            loaded = true;
        }
        else if (isEqual(0, "LOAD"))
        {
            getWord(1, command);
            //konfigurasi(listArtis, &listAlbum, currentWord.TabWord);
            loaded = true;
        }
        else if (isEqual(-1, "HELP"))
        {
            //HELP();
        }
    }
    while (loaded)
    {
        printf("\n === MAIN MENU ===\n\n");
        printf(">> ");
        ADVWORD();
        if (isEqual(0, "LIST"))
        {
            if (isEqual(1, "DEFAULT")) ListDefault(listArtis, listAlbum);
            else continue;
        }
        else if (isEqual(0, "PLAY"))
        {
            continue;
        }
        else if (isEqual(0, "QUEUE"))
        {
            if (isEqual(1, "SONG")) queueSong(listAlbum, listArtis, &songQueue);
        }
        else if (isEqual(0, "DISPLAY"))
        {
            displayQueue(songQueue);
            printf("%d\n", Length(songQueue));
        }
        //else if (isEqual)
    }
    

}

