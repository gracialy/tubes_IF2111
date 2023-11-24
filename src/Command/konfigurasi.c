#include "konfigurasi.h"

int banyakArtis;
int banyakUser;

void konfigurasi(char* path){
    char song[NMax];
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
    if (!isEOF())
    {
        ADVFILE(true);
        banyakUser = currentInt;
        for (int u = 0; u < banyakUser; ++u)
        {
            ADVFILE(false);
            stringCopy(listUser.username[u], currentLine.TabWord);
            ADVFILE(false);
            getSong(listUser.nowplaying[u]);
            ADVFILE(true);
            int banyakQueue = currentInt;
            for (int i = 0; i < banyakQueue; ++i)
            {
                ADVFILE(false);
                getSong(song);
                enqueue(&listUser.queue[u], song);
            }
            ADVFILE(true);
            int banyakStack = currentInt;
            for (int i = 0; i < banyakStack; ++i)
            {
                ADVFILE(false);
                getSong(song);
                Push(&listUser.history[u], song);
            }
            ADVFILE(true);
            int banyakPlaylist = currentInt;
            for (int i = 0; i < banyakPlaylist; ++i)
            {
                ADVFILE(true);
                int banyakIsiPlaylist = currentInt;
                AddElementL(&listUser.playlist[u], currentLine.TabWord);
                CreateEmptyLL(&listUser.playlist[u].A[i]);
                for (int j = 0; j < banyakIsiPlaylist; ++j)
                {
                    ADVFILE(false);
                    getSong(song);
                    InsertLastLL(&listUser.playlist[u].A[i], song);
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