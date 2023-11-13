#include "showlist.h"

void ListDefault(char listArtis[100][50], Map listAlbum){
    int idx;

    printf("Daftar penyanyi :\n");
    for (int i = 0; i < banyakArtis; ++i)
    {
        printf("  %d. %s\n", i + 1, listArtis[i]);
    }

    printf("Ingin melihat album yang ada?(Y/N): ");
    ADVWORD();
    if (isEqual(-1, "Y"))
    {
        printf("Pilih penyanyi untuk melihat album mereka: ");
        ADVWORD();
        if (GetIdx(listAlbum, currentWord.TabWord) == -1)   /* cek apakah penyanyi ada atau tidak*/
        {
            printf("Penyanyi tidak ditemukan !\n");
            return;
        }
        
        idx = 1;
        for (int i = 0; i < listAlbum.Count; ++i)
        {
            if (CompareString(listAlbum.Elements[i].Value, currentWord.TabWord))
            {
                printf("%d. %s\n", idx ++, getSet(listAlbum, i).Name);
            }
        }

        printf("Ingin melihat lagu yang ada?(Y/N): ");
        ADVWORD();
        if (isEqual(-1, "Y"))
        {
            printf("Pilih album untuk melihat lagu yang ada di album : ");
            ADVWORD();

            if (IsMemberMap(listAlbum, currentWord.TabWord))
            {
                idx = 0;
                while (!CompareString(getSet(listAlbum, idx).Name, currentWord.TabWord)) idx++;
                for (int i = 0; i < getSet(listAlbum, idx).Count; ++i)
                {
                    printf("%d. %s\n", i + 1, getSet(listAlbum, idx).Elements[i]);
                }
            }
            else
            {
                printf("Album tidak ditemukan !\n");
                return;
            }
        }
        else return;
    }
    else
    {
        return;
    }
}

void SelectSong(char listArtis[100][50], Map listAlbum, char* target){
    int idx;
    char input[NMax];
    printf("Daftar penyanyi :\n");
    for (int i = 0; i < banyakArtis; ++i)
    {
        printf("  %d. %s\n", i + 1, listArtis[i]);
    }

    printf("Masukkan Nama Penyanyi : ");
    ADVWORD();
    if (GetIdx(listAlbum, currentWord.TabWord) == -1)   /* cek apakah penyanyi ada atau tidak*/
    {
        printf("Penyanyi tidak ditemukan !\n");
        return;
    }
    
    idx = 1;
    for (int i = 0; i < listAlbum.Count; ++i)
    {
        if (CompareString(listAlbum.Elements[i].Value, currentWord.TabWord))
        {
            printf("%d. %s\n", idx ++, getSet(listAlbum, i).Name);
        }
    }

    printf("Masukkan Nama Album yang dipilih : ");
    ADVWORD();

    if (IsMemberMap(listAlbum, currentWord.TabWord))
    {
        idx = 0;
        while (!CompareString(getSet(listAlbum, idx).Name, currentWord.TabWord)) idx++;
        for (int i = 0; i < getSet(listAlbum, idx).Count; ++i)
        {
            printf("%d. %s\n", i + 1, getSet(listAlbum, idx).Elements[i]);
        }
    }
    else
    {
        printf("Album tidak ditemukan !\n");
        return;
    }

    printf("Masukkan ID Lagu yang dipilih : ");
    ADVWORD();
    getWord(0, input);
    if (stringToInt(input) <= 0 || stringToInt(input) > getSet(listAlbum, idx).Count)
    {
        printf("ID yang dimasukkan tidak ada\n");
        return;
    }
    stringCopy(target, getSet(listAlbum, idx).Elements[stringToInt(input) - 1]);
}
