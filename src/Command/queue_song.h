#include "showlist.h"
#include "../ADT/Queue/circular_queue.h"
#include <stdio.h>

#ifndef queue_song
#define queue_song

void queueSong(Map listAlbum, char listArtis[maxA][maxAN], Queue* q);

void queuePlaylist(List listPlaylist, Queue* songQueue, char* currentAlbum);

void queueSwap(Queue* songQueue);

void queueRemove(Queue* songQueue);

void queueClear(Queue* songQueue);

#endif