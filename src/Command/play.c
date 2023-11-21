#include "play.h"

void playSong (char* currentSong, char listArtis[maxA][maxAN], Map listAlbum, Queue* songQueue, char* currentPlaylist){
    SelectSong(listArtis, listAlbum, currentSong);
    stringCopy(currentPlaylist, "\0"); // tidak ada playlist yang sedang diputar
    CreateQueue(songQueue); // tidak ada lagu dalam queue
}

void playPlaylist(char* currentSong, Queue* songQueue, List listPlaylist, Stack* songHistory, char* currentPlaylist){
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
    if (idx < 0 || idx > listPlaylist.Neff)
    {
        printf("ID yang dimasukkan tidak ada\n");
        return;
    }
    
    CreateQueue(songQueue);
    CreateEmptySt(songHistory);
    stringCopy(currentSong, "\0");

    char *Playlist = listPlaylist.A[idx].Name;
    stringCopy(currentPlaylist, Playlist);

    addressLL p = listPlaylist.A[idx].First;
    p = p->next;

    for (int i = 1; i < NbElmt(listPlaylist.A[idx]); ++i)
    {
        enqueue(songQueue, p->info);
        p = p->next;
    }

    for (int i = 1; i < NbElmt(listPlaylist.A[idx]); ++i)
    {
        dequeue(songQueue, currentSong);
        Push(songHistory, currentSong);
    }

    p = listPlaylist.A[idx].First;
    stringCopy(currentSong, p->info);
    p = p->next;
    for (int i = 1; i < NbElmt(listPlaylist.A[idx]); ++i)
    {
        enqueue(songQueue, p->info);
        p = p->next;
    }

    printf("Memutar playlist \"%s\"\n", Playlist);
}