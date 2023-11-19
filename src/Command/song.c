#include "song.h"

void songNext(char* currentSong, Queue* songQueue, Stack* songHistory, Map listAlbum){
    char artist[NMax];
    Push(songHistory, currentSong);
    if (IsEmptyQ(*songQueue))
    {
        if (currentSong[0] == '\0')
        {
            printf("Tidak ada lagu yang diputar!\n");
            return;
        }
        getArtist(currentSong, artist, listAlbum);
        printf("Queue kosong, memutar kembali lagu \n%s oleh %s\n", currentSong, artist);
    }
    else
    {
        dequeue(songQueue, currentSong);
        getArtist(currentSong, artist, listAlbum);
        printf("Memutar lagu selanjutnya %s oleh %s\n", currentSong, artist);
    }
}

void songPrevious(char* currentSong, Queue* songQueue, Stack* songHistory, Map listAlbum){
    char artist[NMax];
    enqueue(songQueue, currentSong);
    if (IsEmptyQ(*songQueue))
    {
        if (currentSong[0] == '\0')
        {
            printf("Tidak ada lagu yang diputar!\n");
            return;
        }
        getArtist(currentSong, artist, listAlbum);
        printf("Queue kosong, memutar kembali lagu \n%s oleh %s\n", currentSong, artist);
    }
    else
    {
        Pop(songHistory, currentSong);
        getArtist(currentSong, artist, listAlbum);
        printf("Memutar lagu selanjutnya %s oleh %s\n", currentSong, artist);
    }
}