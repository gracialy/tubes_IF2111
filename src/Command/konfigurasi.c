#include "konfigurasi.h"

int banyakArtis;

void konfigurasi(char listArtis[100][50], Map* listAlbum, char* path, char* currentSong, 
    Queue* songQueue, Stack* songHistory, List* listPlaylist){
    if (!isPathValid(path))
    {
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n");
        return;
    }
    char a[] = "src/save/", b[NMax];
    konkatString(b, a, path);
    STARTFILE(b);
    ADVFILE(true);
    int banyakArtis = currentInt;
    for (int i = 0; i < banyakArtis; ++i) // ngebaca artis
    {
        ADVFILE(true);
        int banyakAlbum = currentInt;
        stringCopy(listArtis[i], currentLine.TabWord);

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
    if (!isEOF())
    {
        char song[NMax];
        ADVFILE(false);
        getSong(song);
        stringCopy(currentSong, song);
        ADVFILE(true);
        int banyakQueue = currentInt;
        for (int i = 0; i < banyakQueue; ++i)
        {
            ADVFILE(false);
            getSong(song);
            enqueue(songQueue, song);
        }
        ADVFILE(true);
        int banyakStack = currentInt;
        for (int i = 0; i < banyakStack; ++i)
        {
            ADVFILE(false);
            getSong(song);
            Push(songHistory, song);
        }
        ADVFILE(true);
        int banyakPlaylist = currentInt;
        for (int i = 0; i < banyakPlaylist; ++i)
        {
            ADVFILE(true);
            int banyakIsiPlaylist = currentInt;
            AddElementL(listPlaylist, currentLine.TabWord);
            CreateEmptyLL(&listPlaylist->A[i]);
            for (int j = 0; j < banyakIsiPlaylist; ++j)
            {
                ADVFILE(false);
                getSong(song);
                InsertLastLL(&listPlaylist->A[i], song);
            }
        }



    }

    printf("File konfigurasi berhasil dibaca. WayangWave berhasil dijalankan!\n");
}

boolean isPathValid(char* path){
    char a[] = "src/save/", b[NMax];
    konkatString(b, a, path);
    FILE *pita = fopen(b, "r");
    boolean valid = true;
    if (pita == NULL)
    {
        valid = false;
    }
    fclose(pita);
    return valid;
}