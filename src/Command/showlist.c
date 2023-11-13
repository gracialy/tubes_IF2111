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
    if (isEqual("Y") || isEqual("y"))
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
        if (isEqual("Y"))
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
