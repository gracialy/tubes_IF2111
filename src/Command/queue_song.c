#include "queue_song.h"

void queueSong(Map listAlbum, char listArtis[maxA][maxAN], Queue* q){
    char song[NMax];
    if (SelectSong(listArtis, listAlbum, song)) return;
    enqueue(q, song);
}

void queuePlaylist(List listPlaylist, Queue* songQueue, char* currentAlbum){
    showPlaylist(listPlaylist);
    printf("Masukkan ID playlist : ");
    ADVWORD();
    int idx = stringToInt(currentWord.TabWord) - 1;
    if (idx < 0 || idx > listPlaylist.Neff)
    {
        printf("ID yang dimasukkan tidak ada\n");
        return;
    }
    addressLL p = listPlaylist.A[idx].First;
    for (int i = 0; i < NbElmt(listPlaylist.A[idx]); ++i)
    {
        enqueue(songQueue, p->info);
        p = p->next;
    }
}

void queueSwap(Queue* songQueue){
    char xstr[NMax], ystr[NMax];
    getWord(2, xstr); getWord(3, ystr);
    int x = stringToInt(xstr), y = stringToInt(ystr);
    if (x > y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    if (x > LengthQ(*songQueue))
    {
        printf("ID yang dimasukkan tidak valid!\n");
        return;
    }

    int idx;
    char tempstr[NMax];

    for (int i = 0; i <= IDX_MAX; ++i)
    {
        if (i == songQueue->idxHead + x - 1)
        {
            idx = i;
            stringCopy(tempstr, songQueue->Tab[i]);
        }
        else if (i == songQueue->idxHead + y - 1)
        {
            stringCopy(songQueue->Tab[idx], songQueue->Tab[i]);
            stringCopy(songQueue->Tab[i], tempstr);
        }
    }
    printf("Queue berhasil diswap!\n");

}

void queueRemove(Queue* songQueue){
    char idxstr[NMax];
    getWord(2, idxstr);
    int idx = stringToInt(idxstr);
    char temp[IDX_MAX + 1][NMax];
    int n = 0;
    while(!IsEmptyQ(*songQueue))
    {
        dequeue(songQueue, temp[n]);
        n++;
    }
    for (int i = 0; i < n; ++i)
    {
        if (i != idx - 1)
        {
            enqueue(songQueue, temp[i]);
        }
    }
    printf("Berhasil menghapus lagu dari queue\n");
}

void queueClear(Queue* songQueue){
    char temp[NMax];
    while (!IsEmptyQ(*songQueue)) dequeue(songQueue, temp);
}