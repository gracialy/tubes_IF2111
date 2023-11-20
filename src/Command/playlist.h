#include "../ADT/List/list.h"
#include "../ADT/Linked_List/listlinier.h"
#include "../ADT/Map/map.h"
#include "../ADT/Mesin_Kata/mesinkata.h"
#include "../ADT/Mesin_Baris/mesinbaris.h"
#include "showlist.h"
#include <stdio.h>

#ifndef PLAYLIST
#define PLAYLIST

void CreatePlaylist(List* playlist, char listArtis[100][50], Map listAlbum);

void InsertPlaylist(List* playlist, char listArtis[100][50], Map listAlbum);

void InsertAlbumToPlaylist(List* playlist, char listArtis[100][50], Map listAlbum);

void playlistSwap(List* listPlaylist);

void playlistDelete(List* listPlaylist);

#endif