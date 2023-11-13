#include "konfigurasi.h"

int banyakArtis;

void konfigurasi(char listArtis[100][50], Map* listAlbum, char* path){
    STARTFILE(path);
    ADVFILE(true);
    banyakArtis = currentInt;
    for (int i = 0; i < banyakArtis; ++i) // ngebaca artis
    {
        ADVFILE(true);
        int banyakAlbum = currentInt;
        copyString(listArtis[i], currentLine.TabWord);

        for (int j = 0; j < banyakAlbum; ++j) //ngebaca album
        {
            ADVFILE(true);
            int banyakLagu = currentInt;
            RenameSet(&getSet(*listAlbum, listAlbum->Count), currentLine.TabWord);
            CreateEmpty(&getSet(*listAlbum, listAlbum->Count));
            for (int k = 0; k < banyakLagu; ++k) //ngebaca lagu
            {
                ADVFILE(false);
                InsertSet(&getSet(*listAlbum, listAlbum->Count), currentLine.TabWord);
            }
            listAlbum->Elements[listAlbum->Count].Value = listArtis[i];
            listAlbum->Count ++;
        }
    }
    printf("File konfigurasi berhasil dibaca. WayangWave berhasil dijalankan!\n");
}

void copyString(char* copy, char* target){
    int i;
    for (i = 0; target[i] != '\0'; ++i)
    {
        copy[i] = target[i];
    }
    copy[i] = '\0';
}