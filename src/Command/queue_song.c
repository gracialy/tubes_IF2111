#include "queue_song.h"

void queueSong(Map listAlbum, char listArtis[maxA][maxAN], Queue* q){
    char song[NMax];
    if (SelectSong(listArtis, listAlbum, song)) return; // if song is not found then return
    enqueue(q, song);
    char artist[NMax];
    getArtist(song, artist, listAlbum);
    printf("Berhasil menambahkan lagu \"%s\" oleh \"%s\" ke queue\n", song, artist);
}

void queuePlaylist(List listPlaylist, Queue* songQueue, char* currentAlbum){
    printf("Daftar playlist yang kamu miliki : \n");
    if (listPlaylist.Neff == 0) 
    {
        printf("Kamu tidak memiliki playlist.\n");
        return;
    }
    DisplayList(listPlaylist);
    printf("Masukkan ID playlist : ");
    ADVWORD();
    int idx = stringToInt(currentWord.TabWord) - 1;
    if (idx < 0 || idx > listPlaylist.Neff-1)
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
    printf("Berhasil menambahkan playlist \"%s\" ke queue\n", listPlaylist.A[idx].Name);
}

void queueSwap(Queue* songQueue){
    char xstr[NMax], ystr[NMax];
    getWord(2, xstr); getWord(3, ystr);

    // queue number is not completed
    if (CompareString(xstr, " ") || CompareString(ystr, " "))
    {
        printf("Command yang dimasukkan tidak valid\n");
        return;
    }

    int x = stringToInt(xstr), y = stringToInt(ystr);
    
    // queue number is not valid
    if ((x > LengthQ(*songQueue) || x<=0) && (y > LengthQ(*songQueue) || y<=0))
    {
        printf("Lagu dengan urutan ke %d dan %d tidak terdapat dalam queue\n", x, y);
        return;
    }
    else if (x > LengthQ(*songQueue) || x<=0)
    {
        printf("Lagu dengan urutan ke %d tidak terdapat dalam queue\n", x);
        return;
    }
    else if (y > LengthQ(*songQueue) || y<=0)
    {
        printf("Lagu dengan urutan ke %d tidak terdapat dalam queue\n", y);
        return;
    }

    stringCopy(xstr, songQueue->Tab[(songQueue->idxHead + x-1) % (IDX_MAX + 1)]);
    stringCopy(ystr, songQueue->Tab[(songQueue->idxHead + y-1) % (IDX_MAX + 1)]);

    stringCopy(songQueue->Tab[(songQueue->idxHead + x-1) % (IDX_MAX + 1)], ystr);
    stringCopy(songQueue->Tab[(songQueue->idxHead + y-1) % (IDX_MAX + 1)], xstr);

    printf("Lagu \"%s\" berhasil ditukar dengan \"%s\"\n", xstr, ystr);
}

void queueRemove(Queue* songQueue){
    char idxstr[NMax];
    getWord(2, idxstr);
    // queue number is not completed
    if (CompareString(idxstr, " "))
    {
        printf("Command yang dimasukkan tidak valid\n");
        return;
    }

    int idx = stringToInt(idxstr);
    if (idx > LengthQ(*songQueue) || idx<=0)
    {
        printf("Lagu dengan urutan ke %d tidak terdapat dalam queue\n", idx);
        return;
    }

    char temp[IDX_MAX + 1][NMax];
    int n = 0;
    char artist[NMax];
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
        else{
            stringCopy(idxstr, temp[i]);
            getArtist(idxstr, artist, listAlbum);
        }
    }
    printf("Lagu \"%s\" oleh \"%s\" telah dihapus dari queue!\n", idxstr, artist);
}

void queueClear(Queue* songQueue){
    char temp[NMax];
    while (!IsEmptyQ(*songQueue)) dequeue(songQueue, temp);
    printf("Queue berhasil dikosongkan\n");
}