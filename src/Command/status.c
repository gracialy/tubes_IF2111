#include "status.h"
#include "../ADT/Queue/circular_queue.h"

void status(Queue queue, char* current_playlist){
    if (IsEmpty(queue))
    {
        printf("Now Playing:\nNo songs have been played yet. Please search for a song to begin playback.\n\nQueue:\nYour queue is empty.\n");
    }
    else if (Length(queue) == 1)
    {
        printf("Now Playing:\n%s\n\nQueue:\nYour queue is empty.\n", HEAD(queue));
    }
    else if (current_playlist[0] == "\0")
    {
        printf("Now Playing:\n%s\n\nQueue:\n", HEAD(queue));
        for (int i = queue.idxHead + 1; i <= queue.idxTail; ++i)
        {
            printf("%d. %s\n", i - queue.idxHead, queue.Tab[i]);
        }
    }
    else
    {
        printf("Current Playlist: %s\n", current_playlist);
        printf("Now Playing:\n%s\n\nQueue:\n", HEAD(queue));
        for (int i = queue.idxHead + 1; i <= queue.idxTail; ++i)
        {
            printf("%d. %s\n", i - queue.idxHead, queue.Tab[i]);
        }
    }

}