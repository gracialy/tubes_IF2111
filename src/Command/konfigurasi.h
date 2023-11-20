#ifndef __KONFIGURASI__
#define __KONFIGURASI__

#include "../ADT/Mesin_Baris/mesinbaris.h"
#include "../ADT/Mesin_Kata/mesinkata.h"
#include "../ADT/Mesin_Karakter/mesinkarakter.h"
#include "../ADT/Map/map.h"
#include "playlist.h"
#include "queue_song.h"
#include "../ADT/Stack/stack.h"
#include"../main.h"

extern int banyakArtis;

void konfigurasi(char listArtis[100][50], Map* listAlbum, char* path, char* currentSong, 
    Queue* songQueue, Stack* songHistory, List* listPlaylist);

boolean isPathValid(char* path);

#endif