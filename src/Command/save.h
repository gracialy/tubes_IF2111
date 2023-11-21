#include "konfigurasi.h"
#include "showlist.h"
#include "../ADT/Mesin_Karakter/mesinkarakter.h"

#ifndef __SAVE__
#define __SAVE__

void save(char listArtis[maxA][maxAN], Map* listAlbum, char* currentSong, 
    Queue* songQueue, Stack* songHistory, List* listPlaylist);

#endif