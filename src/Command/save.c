#include "save.h"

void save(){
    char path[NMax];
    getWord(1, path);
    char a[] = "src/save/", b[NMax];
    konkatString(b, a, path);
    FILE* f = fopen(b, "w");

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
    getArtist(currentSong, artistTemp, listAlbum); getAlbum(currentSong, albumTemp, listAlbum);
    fprintf(f, "%s;%s;%s\n", artistTemp, albumTemp, currentSong);
    // QUEUE
    if (songQueue.idxHead == IDX_UNDEF) fprintf(f, "0\n");
    else 
    {
        if (songQueue.idxHead > songQueue.idxTail) fprintf(f, "%d", 99 - songQueue.idxHead + songQueue.idxTail + 2);
        else fprintf(f, "%d\n", songQueue.idxTail - songQueue.idxHead + 1);
        int idx = songQueue.idxHead;
        while (idx != (songQueue.idxTail + 1) % 100)
        {
            stringCopy(songTemp, songQueue.Tab[idx]);
            getArtist(songTemp, artistTemp, listAlbum); getAlbum(songTemp, albumTemp, listAlbum);
            fprintf(f, "%s;%s;%s\n", artistTemp, albumTemp, songTemp);
            idx++;
        }
    }
    
    // STACK
    if (IsEmptySt(songHistory)) fprintf(f, "0\n");
    else
    {
        for (int i = 0; i <= songHistory.TOP; ++i)
        {
            stringCopy(songTemp, songHistory.T[i]);
            getArtist(songTemp, artistTemp, listAlbum); getAlbum(songTemp, albumTemp, listAlbum);
            fprintf(f, "%s;%s;%s\n", artistTemp, albumTemp, songTemp);
        }
    }

    // PLAYLIST

    fprintf(f, "%d\n", listPlaylist.Neff);
    for (int i = 0; i < listPlaylist.Neff; ++i)
    {
        fprintf(f, "%d %s\n", NbElmt(listPlaylist.A[i]), listPlaylist.A[i].Name);
        if (listPlaylist.A[i].First != NilLL)
        {
            addressLL p = listPlaylist.A[i].First;
            while (p->next != NilLL)
            {
                stringCopy(songTemp, p->info);
                getArtist(songTemp, artistTemp, listAlbum); getAlbum(songTemp, albumTemp, listAlbum);
                fprintf(f, "%s;%s;%s\n", artistTemp, albumTemp, songTemp);
                p = p->next;
            }
            stringCopy(songTemp, p->info);
            getArtist(songTemp, artistTemp, listAlbum); getAlbum(songTemp, albumTemp, listAlbum);
            fprintf(f, "%s;%s;%s\n", artistTemp, albumTemp, songTemp);
        }
    }
    fclose(f);
}

