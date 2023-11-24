#include "status.h"

void status(){
    printf("Logged in as %s\n", username);

    // current playlist
    if (currentPlaylist[0] != '\0'){
        printf("Current Playlist: %s\n", currentPlaylist);
    }

    // now playing
    if (currentSong[0] == '\0')
    {
        printf("Now Playing:\nNo songs have been played yet. Please search for a song to begin playback.\n");
    }
    else
    {
        char artist[NMax], album[NMax];
        getArtist(currentSong, artist);
        getAlbum(currentSong, album);
        printf("Now Playing:\n%s - %s - %s\n", artist, currentSong, album);
    }

    printf("Queue:\n");
    if (IsEmptyQ(songQueue)) 
    {
        printf("Your queue is empty.\n");
        
    }
    else{
        for (int i = songQueue.idxHead; i <= songQueue.idxTail; ++i)
        {
            char artist[NMax], album[NMax];
            getArtist(songQueue.Tab[i % (IDX_MAX + 1)], artist);
            getAlbum(songQueue.Tab[i % (IDX_MAX + 1)], album);
            printf("%d. %s - %s - %s\n", i - songQueue.idxHead + 1, artist,  songQueue.Tab[i], album);
        }
    }
    
    // song history (opsional)
    if (IsEmptySt(songHistory))
    {
        printf("Song History:\nYour history is empty.\n");
    }
    else
    {
        printf("Song History:\n");
        Stack temp; CreateEmptySt(&temp);
        char val[NMax]; int i=1;
        while (!IsEmptySt(songHistory))
        {
            char artist[NMax], album[NMax];
            getArtist(InfoTop(songHistory), artist);
            getAlbum(InfoTop(songHistory), album);
            printf("%d. %s - %s - %s\n", i, artist, InfoTop(songHistory), album);
            Pop(&songHistory, val);
            Push(&temp, val);
            i++;
        }
        while (!IsEmptySt(temp))
        {
            Pop(&temp, val);
            Push(&songHistory, val);
        }
    }
}