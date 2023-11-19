#include "../ADT/Mesin_Kata/mesinkata.h"
#include "../ADT/Stack/stack.h"
#include "queue_song.h"
#include "showlist.h"

#ifndef _SONG_
#define _SONG_

void songNext(char* currentSong, Queue* songQueue, Stack* songHistory, Map listAlbum);

void songPrevious(char* currentSong, Queue* songQueue, Stack* songHistory, Map listAlbum);

#endif