#include "play.h"

void playSong (){
    if (SelectSong(currentSong)==0){
        stringCopy(currentPlaylist, "\0"); // tidak ada playlist yang sedang diputar
        CreateQueue(&songQueue); // tidak ada lagu dalam queue
        char artist[NMax]; getArtist(currentSong, artist);
        printf("Memutar lagu \"%s\" oleh \"%s\"\n", currentSong, artist);
    }
}

void playPlaylist(){
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
    
    CreateQueue(&songQueue);
    CreateEmptySt(&songHistory);
    stringCopy(currentPlaylist, "\0");
    stringCopy(currentSong, "\0");

    if (NbElmt(listPlaylist.A[idx])==0)
    {
        printf("Playlist yang dipilih kosong !\n");
        return;
    }

    char *Playlist = listPlaylist.A[idx].Name;
    stringCopy(currentPlaylist, Playlist);

    addressLL p = listPlaylist.A[idx].First;
    p = p->next;

    for (int i = 1; i < NbElmt(listPlaylist.A[idx]); ++i)
    {
        enqueue(&songQueue, p->info);
        p = p->next;
    }

    for (int i = 1; i < NbElmt(listPlaylist.A[idx]); ++i)
    {
        dequeue(&songQueue, currentSong);
        Push(&songHistory, currentSong);
    }

    p = listPlaylist.A[idx].First;
    stringCopy(currentSong, p->info);
    p = p->next;
    for (int i = 1; i < NbElmt(listPlaylist.A[idx]); ++i)
    {
        enqueue(&songQueue, p->info);
        p = p->next;
    }

    printf("Memutar playlist \"%s\"\n", Playlist);
}