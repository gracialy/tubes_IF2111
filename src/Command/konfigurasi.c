#include "konfigurasi.h"

void konfigurasi(char** listArtis, Map* listAlbum){
    STARTFILE();
    ADVFILE(true);
    int banyakArtis = currentInt;
    for (int i = 0; i < banyakArtis; ++i) // ngebaca artis
    {
        ADVFILE(true);
        int banyakAlbum = currentInt;
        listArtis[i] = currentLine.TabWord;

        for (int j = 0; j < banyakAlbum; ++j) //ngebaca album
        {
            Set currentAlbum;
            CreateEmpty(&currentAlbum);
            ADVFILE(true);
            int banyakLagu = currentInt;
            RenameSet(&currentAlbum, &currentLine.TabWord);

            for (int k = 0; k < banyakLagu; ++k) //ngebaca lagu
            {
                ADVFILE(false);
                InsertSet(&currentAlbum, currentLine.TabWord);
            }

            Insert(listAlbum, currentAlbum, listArtis[i]);
        }
    }

}