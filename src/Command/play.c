#include "play.h"

void playSong (char* currentSong, char listArtis[100][50], Map listAlbum, Queue* songQueue, char* currentPlaylist){
    SelectSong(listArtis, listAlbum, currentSong);
    stringCopy(currentPlaylist, "\0");
    CreateQueue(songQueue);
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
    addressLL p = listPlaylist.A[idx].First;
    for (int i = 0; i < NbElmt(listPlaylist.A[idx]); ++i)
    {
        if (i == 0) stringCopy(currentSong, p->info);
        else
        {
            enqueue(songQueue, p->info);
            Push(songHistory, p->info);
        }
        p = p->next;
    }
}