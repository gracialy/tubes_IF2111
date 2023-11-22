#include "showlist.h"

void ListDefault(char listArtis[maxA][maxAN], Map listAlbum){
    int idx;

    printf("Daftar penyanyi :\n");
    for (int i = 0; listArtis[i][0] != '\0'; ++i)
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
                printf("  %d. %s\n", idx ++, getSet(listAlbum, i).Name);
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
                    printf("  %d. %s\n", i + 1, getSet(listAlbum, idx).Elements[i]);
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

int SelectSong(char listArtis[maxA][maxAN], Map listAlbum, char* target){
    int idx;
    char input[NMax];
    printf("Daftar penyanyi :\n");
    for (int i = 0; listArtis[i][0] != '\0'; ++i)
    {
        printf("  %d. %s\n", i + 1, listArtis[i]);
    }

    printf("Masukkan Nama Penyanyi : ");
    ADVWORD();
    if (GetIdx(listAlbum, currentWord.TabWord) == -1)   /* cek apakah penyanyi ada atau tidak*/
    {
        printf("Penyanyi tidak ditemukan !\n");
        return 1;
    }
    // Word Singer = currentWord; // Singer.TabWord
    
    idx = 1;
    for (int i = 0; i < listAlbum.Count; ++i)
    {
        if (CompareString(listAlbum.Elements[i].Value, currentWord.TabWord))
        {
            printf("  %d. %s\n", idx ++, getSet(listAlbum, i).Name);
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
            printf("  %d. %s\n", i + 1, getSet(listAlbum, idx).Elements[i]);
        }
    }
    else
    {
        printf("Album tidak ditemukan !\n");
        return 1;
    }

    printf("Masukkan ID Lagu yang dipilih : ");
    ADVWORD();
    getWord(0, input);
    if (stringToInt(input) <= 0 || stringToInt(input) > getSet(listAlbum, idx).Count)
    {
        printf("ID yang dimasukkan tidak ada\n");
        return 1;
    }
    stringCopy(target, getSet(listAlbum, idx).Elements[stringToInt(input) - 1]);
    return 0;
}

void showPlaylist(List listPlaylist){
    printf("Daftar playlist yang kamu miliki : \n");
    if (listPlaylist.Neff == 0) 
    {
        printf("Kamu tidak memiliki playlist.\n");
        return;
    }
    DisplayList(listPlaylist);
    printf("Ingin melihat playlist yang ada?(Y/N) : ");
    ADVWORD();
    if (!isEqual(0, "Y")) return;
    printf("Masukkan ID playlist yang ingin dilihat : ");
    ADVWORD();
    char temp[NMax];
    getWord(0, temp);
    int id = stringToInt(temp);
    if (id <= 0 || id > listPlaylist.Neff)
    {
        printf("Playlist tidak ditemukan\n");
        return;
    }
    displayLinkedList(listPlaylist.A[id - 1]);
}

void getArtist(char *song, char* artist, Map listAlbum){
    for (int i = 0; i < listAlbum.Count; ++i)
    {
        for (int j = 0; j < getSet(listAlbum, i).Count; ++j)
        {
            if (CompareString(getSet(listAlbum, i).Elements[j], song))
            {
                stringCopy(artist, listAlbum.Elements[i].Value);
                return;
            }
        }
    }
}

void getAlbum(char *song, char* album, Map listAlbum){
    for (int i = 0; i < listAlbum.Count; ++i)
    {
        for (int j = 0; j < getSet(listAlbum, i).Count; ++j)
        {
            if (CompareString(getSet(listAlbum, i).Elements[j], song))
            {
                stringCopy(album, listAlbum.Elements[i].Key.Name);
                return;
            }
        }
    }

}