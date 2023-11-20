#include <stdio.h>
#include "../ADT/Mesin_Kata/mesinkata.h"
#include "../ADT/Map/map.h"
#include "../ADT/Mesin_Baris/mesinbaris.h"
#include "../ADT/List/list.h"
#include "konfigurasi.h"

#ifndef __list__
#define __list__

void ListDefault(char listArtis[100][50], Map listAlbum);

int SelectSong(char listArtis[100][50], Map listAlbum, char* target);

void showPlaylist(List listPlaylist);

void getArtist(char *song, char* artist, Map listAlbum);

void getAlbum(char *song, char* album, Map listAlbum);

#endif