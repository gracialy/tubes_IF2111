#include "save.h"

void save(){
    char path[NMax];
    FILE* f;
    getWord(1, path);
    char a[] = "src/save/", b[NMax];
    konkatString(b, a, path);
    f = fopen(b, "w");

    char savetemp[NMax];
    int artistCount = 0;
    while (listArtis[artistCount][0] != '\0') artistCount++;
    fprintf(f, "%d\n", artistCount);   // 2
    for (int i = 0; i < artistCount; ++i)
    {
        int banyakAlbum = 0;
        for (int j = 0; j < listAlbum.Count; ++j)
        {
            if (CompareString(listArtis[i], listAlbum.Elements[j].Value)) banyakAlbum++;
        }
        fprintf(f, "%d %s\n", banyakAlbum, listArtis[i]); // 2 BLACKPINK

        for (int j = 0; j < listAlbum.Count; ++j)
        {
            if (CompareString(listArtis[i], listAlbum.Elements[j].Value))
            {
                fprintf(f, "%d %s\n", getSet(listAlbum, j).Count, getSet(listAlbum, j).Name);  // 4 BORNPINK
                for (int k = 0; k < getSet(listAlbum, j).Count; ++k)
                {
                    fprintf(f, "%s\n", getSet(listAlbum, j).Elements[k]); // Pink Venom
                }
            }
        }
    }
    char artistTemp[NMax], albumTemp[NMax], songTemp[NMax];
    fprintf(f, "%d\n", banyakUser);
    for (int u = 0; u < banyakUser; ++u)
    {
        fprintf(f, "%s\n", listUser.username[u]);
        getArtist(listUser.nowplaying[u], artistTemp); getAlbum(listUser.nowplaying[u], albumTemp);
        fprintf(f, "%s;%s;%s\n", artistTemp, albumTemp, listUser.nowplaying[u]);

        // QUEUE
        if (listUser.queue[u].idxHead == IDX_UNDEF) fprintf(f, "0\n");
        else 
        {
            if (listUser.queue[u].idxHead > listUser.queue[u].idxTail) fprintf(f, "%d", 99 - listUser.queue[u].idxHead + listUser.queue[u].idxTail + 2);
            else fprintf(f, "%d\n", listUser.queue[u].idxTail - listUser.queue[u].idxHead + 1);
            int idx = listUser.queue[u].idxHead;
            while (idx != (listUser.queue[u].idxTail + 1) % 100)
            {
                stringCopy(songTemp, listUser.queue[u].Tab[idx]);
                getArtist(songTemp, artistTemp); getAlbum(songTemp, albumTemp);
                fprintf(f, "%s;%s;%s\n", artistTemp, albumTemp, songTemp);
                idx++;
            }
        }

        // STACK
        if (IsEmptySt(listUser.history[u])) fprintf(f, "0\n");
        else
        {
            fprintf(f, "%d\n", listUser.history[u].TOP);
            for (int i = 0; i <= listUser.history[u].TOP; ++i)
            {
                stringCopy(songTemp, listUser.history[u].T[i]);
                getArtist(songTemp, artistTemp); getAlbum(songTemp, albumTemp);
                fprintf(f, "%s;%s;%s\n", artistTemp, albumTemp, songTemp);
            }
        }

        // PLAYLIST

        fprintf(f, "%d\n", listUser.playlist[u].Neff);
        for (int i = 0; i < listUser.playlist[u].Neff; ++i)
        {
            fprintf(f, "%d %s\n", NbElmt(listUser.playlist[u].A[i]), listUser.playlist[u].A[i].Name);
            if (listUser.playlist[u].A[i].First != NilLL)
            {
                addressLL p = listUser.playlist[u].A[i].First;
                while (p->next != NilLL)
                {
                    stringCopy(songTemp, p->info);
                    getArtist(songTemp, artistTemp); getAlbum(songTemp, albumTemp);
                    fprintf(f, "%s;%s;%s\n", artistTemp, albumTemp, songTemp);
                    p = p->next;
                }
                stringCopy(songTemp, p->info);
                getArtist(songTemp, artistTemp); getAlbum(songTemp, albumTemp);
                fprintf(f, "%s;%s;%s\n", artistTemp, albumTemp, songTemp);
            }
        }
    }


    fclose(f);
}

