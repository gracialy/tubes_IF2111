#include "main.h"

char listArtis[100][50];
Map listAlbum;

int main(){
    CreateMapEmpty(&listAlbum);
    printf(">> ");
    STARTWORD();
    ADVWORD();

    boolean loaded = false;
    while (!loaded)
    {
        if (isEqual("START"))
        {
            konfigurasi(listArtis, &listAlbum, "src/save/konfigurasi.txt");
            loaded = true;
        }
        else if (isEqual("LOAD"))
        {
            ADVWORD();
            konfigurasi(listArtis, &listAlbum, currentWord.TabWord);
            loaded = true;
        }
        else if (isEqual("HELP"))
        {
            //HELP();
        }
    }
    while (loaded)
    {
        printf(">> ");
        ADVWORD();
        if (isEqual("LIST DEFAULT")) ListDefault(listArtis, listAlbum);
    }
    

}

