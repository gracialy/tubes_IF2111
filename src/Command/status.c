#include "status.h"

void status(Queue queue, char* current_playlist, char* currentSong, Map listAlbum){
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
    if (current_playlist[0] == '\0')
    {
        printf("Queue:\n", HEAD(queue));
        if (IsEmptyQ(queue)) 
        {
            printf("Your queue is empty.\n");
            return;
        }
        for (int i = queue.idxHead; i <= queue.idxTail; ++i)
        {
            char artist[NMax], album[NMax];
            getArtist(queue.Tab[i % (IDX_MAX + 1)], artist, listAlbum);
            getAlbum(queue.Tab[i % (IDX_MAX + 1)], album, listAlbum);
            printf("%d. %s - %s - %s\n", i - queue.idxHead + 1, artist,  queue.Tab[i], album);
        }
    }
    else
    {
        printf("Current Playlist: %s\n", current_playlist);
        printf("Queue:\n", HEAD(queue));
        if (IsEmptyQ(queue)) 
        {
            printf("Your queue is empty.\n");
            return;
        }
        for (int i = queue.idxHead; i <= queue.idxTail; ++i)
        {
            char artist[NMax], album[NMax];
            getArtist(queue.Tab[i % (IDX_MAX + 1)], artist, listAlbum);
            getAlbum(queue.Tab[i % (IDX_MAX + 1)], album, listAlbum);
            printf("%d. %s - %s - %s\n", i - queue.idxHead + 1, artist, album, queue.Tab[i]);
        }
    }

}