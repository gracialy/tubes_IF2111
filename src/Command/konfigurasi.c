#include "konfigurasi.h"

int banyakArtis;

void konfigurasi(char* path){
    if (!isPathValid(path))
    {
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n");
        exit(0);
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
            RenameSet(&getSet(listAlbum, listAlbum.Count), currentLine.TabWord);
            CreateEmpty(&getSet(listAlbum, listAlbum.Count));
            for (int k = 0; k < banyakLagu; ++k) //ngebaca lagu
            {
                ADVFILE(false);
                InsertSet(&getSet(listAlbum, listAlbum.Count), currentLine.TabWord);
            }
            listAlbum.Elements[listAlbum.Count].Value = listArtis[i];
            listAlbum.Count ++;
        } 
    }
    ADVFILE(true);
    int banyakUser = currentInt;
    for (int i = 0; i < banyakUser; ++i) //ngebaca nama user
    {
        ADVFILE(false);
        stringCopy(listUser[i].username, currentLine.TabWord);
    }
    if (!isEOF())
    {
        for (int i = 0; i < banyakUser; ++i) //ngebaca data user
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
                enqueue(&songQueue, song);
            }
            ADVFILE(true);
            int banyakStack = currentInt;
            for (int i = 0; i < banyakStack; ++i)
            {
                ADVFILE(false);
                getSong(song);
                Push(&songHistory, song);
            }
            ADVFILE(true);
            int banyakPlaylist = currentInt;
            for (int i = 0; i < banyakPlaylist; ++i)
            {
                ADVFILE(true);
                int banyakIsiPlaylist = currentInt;
                AddElementL(&listPlaylist, currentLine.TabWord);
                CreateEmptyLL(&listPlaylist.A[i]);
                for (int j = 0; j < banyakIsiPlaylist; ++j)
                {
                    ADVFILE(false);
                    getSong(song);
                    InsertLastLL(&listPlaylist.A[i], song);
                }
            }
        }
    }
    while (!isEOF()) ADVFILE(false);
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