#include <stdio.h>
#include "../ADT/Mesin_Kata/mesinkata.h"
#include "../ADT/Map/map.h"
#include "../ADT/Mesin_Baris/mesinbaris.h"
#include "../ADT/List/list.h"
#include "konfigurasi.h"

#ifndef __list__
#define __list__
#include "../main.h"

void ListDefault();

int SelectSong(char* target);

void showPlaylist();

void getArtist(char *song, char* artist);

void getAlbum(char *song, char* album);

#endif