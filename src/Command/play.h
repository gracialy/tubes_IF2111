#include "showlist.h"
#include "queue_song.h"
#include "playlist.h"
#include "../ADT/Mesin_Kata/mesinkata.h"
#include "../ADT/Stack/stack.h"
#include "../ADT/Queue/circular_queue.h"

#ifndef play_song
#define play_song

void playSong (char* currentSong, char listArtis[100][50], Map listAlbum, Queue* songQueue, char* currentPlaylist);

void playPlaylist(char* currentSong, Queue* songQueue, List listPlaylist, Stack* songHistory, char* currentPlaylist);

#endif