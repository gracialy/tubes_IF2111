#include "../ADT/List/list.h"
#include "../ADT/Linked_List/listlinier.h"
#include "../ADT/Map/map.h"
#include "../ADT/Mesin_Kata/mesinkata.h"
#include "../ADT/Mesin_Baris/mesinbaris.h"
#include "showlist.h"
#include <stdio.h>

#ifndef PLAYLIST
#define PLAYLIST

#include "../main.h"

void CreatePlaylist();

boolean isAllSpace(Word word);
int effName(Word word);

void InsertPlaylist();

void InsertAlbumToPlaylist();

void playlistSwap();

void playlistRemove();

void playlistDelete();

void setCurrentPlaylist();

#endif