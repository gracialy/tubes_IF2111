#include "../ADT/Mesin_Baris/mesinbaris.h"
#include "../ADT/Map/map.h"

#ifndef __KONFIGURASI__
#define __KONFIGURASI__

extern int banyakArtis;

void konfigurasi(char listArtis[100][50], Map* listAlbum, char* path);
void copyString(char* copy, char* target);

#endif