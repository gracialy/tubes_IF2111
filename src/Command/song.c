#include "song.h"

void songNext(){
    char artist[NMax];
    if (IsEmptyQ(songQueue))
    {
        if (currentSong[0] == '\0')
        {
            printf("Tidak ada lagu yang dapat diputar!\n");
            return;
        }
        Push(&songHistory, currentSong);
        getArtist(currentSong, artist);
        printf("Queue kosong, memutar kembali lagu \n%s oleh %s\n", currentSong, artist);
    }
    else
    {
        Push(&songHistory, currentSong);
        dequeue(&songQueue, currentSong);
        getArtist(currentSong, artist);
        printf("Memutar lagu selanjutnya %s oleh %s\n", currentSong, artist);
    }
}

void songPrevious(){
    char artist[NMax];
    if (IsEmptySt(songHistory))
    {
        if (currentSong[0] == '\0')
        {
            printf("Tidak ada lagu yang dapat diputar!\n");
            return;
        }
        insertFirstQueue(&songQueue, currentSong);
        getArtist(currentSong, artist);
        printf("Queue kosong, memutar kembali lagu \n%s oleh %s\n", currentSong, artist);
    }
    else
    {
        insertFirstQueue(&songQueue, currentSong);
        Pop(&songHistory, currentSong);
        getArtist(currentSong, artist);
        printf("Memutar lagu sebelumnya %s oleh %s\n", currentSong, artist);
    }
}