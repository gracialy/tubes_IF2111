#include "status.h"

void status(Queue queue, Stack songHistory, char* current_playlist, char* currentSong, Map listAlbum){
    // current playlist
    if (current_playlist[0] != '\0'){
        printf("Current Playlist: %s\n", current_playlist);
    }

    // now playing
    if (currentSong[0] == '\0')
    {
        printf("Now Playing:\nNo songs have been played yet. Please search for a song to begin playback.\n");
    }
    else
    {
        char artist[NMax], album[NMax];
        getArtist(currentSong, artist, listAlbum);
        getAlbum(currentSong, album, listAlbum);
        printf("Now Playing:\n%s - %s - %s\n", artist, currentSong, album);
    }

    printf("Queue:\n");
    if (IsEmptyQ(queue)) 
    {
        printf("Your queue is empty.\n");
        
    }
    else{
        for (int i = queue.idxHead; i <= queue.idxTail; ++i)
        {
            char artist[NMax], album[NMax];
            getArtist(queue.Tab[i % (IDX_MAX + 1)], artist, listAlbum);
            getAlbum(queue.Tab[i % (IDX_MAX + 1)], album, listAlbum);
            printf("%d. %s - %s - %s\n", i - queue.idxHead + 1, artist,  queue.Tab[i], album);
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
            getArtist(InfoTop(songHistory), artist, listAlbum);
            getAlbum(InfoTop(songHistory), album, listAlbum);
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