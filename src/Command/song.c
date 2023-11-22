#include "song.h"

void songNext(){
    char artist[NMax];
    Push(&songHistory, currentSong);
    if (IsEmptyQ(songQueue))
    {
        if (currentSong[0] == '\0')
        {
            printf("Tidak ada lagu yang diputar!\n");
            return;
        }
        getArtist(currentSong, artist);
        printf("Queue kosong, memutar kembali lagu \n%s oleh %s\n", currentSong, artist);
    }
    else
    {
        dequeue(&songQueue, currentSong);
        getArtist(currentSong, artist);
        printf("Memutar lagu selanjutnya %s oleh %s\n", currentSong, artist);
    }
}

void songPrevious(){
    char artist[NMax];
    insertFirstQueue(&songQueue, currentSong);
    if (IsEmptyQ(songQueue))
    {
        if (currentSong[0] == '\0')
        {
            printf("Tidak ada lagu yang diputar!\n");
            return;
        }
        getArtist(currentSong, artist);
        printf("Queue kosong, memutar kembali lagu \n%s oleh %s\n", currentSong, artist);
    }
    else
    {
        Pop(&songHistory, currentSong);
        getArtist(currentSong, artist);
        printf("Memutar lagu sebelumnya %s oleh %s\n", currentSong, artist);
    }
}