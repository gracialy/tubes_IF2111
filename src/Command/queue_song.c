#include "queue_song.h"

void queueSong(Map listAlbum, char listArtis[100][50], Queue* q){
    char song[NMax];
    SelectSong(listArtis, listAlbum, song);
    enqueue(q, song);
}