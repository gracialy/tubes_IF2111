#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "Command/boolean.h"
#include "Command/konfigurasi.h"
#include "Command/showlist.h"
#include "Command/queue_song.h"
#include "Command/playlist.h"
#include "Command/status.h"
#include "Command/play.h"
#include "Command/song.h"
#include "Command/help.h"
#include "Command/welcome.h"

// #include "ADT/list/list.h"
// #include "ADT/Map/map.h"
// #include "ADT/Mesin_Karakter/mesinkarakter.h"
// #include "ADT/Mesin_Kata/mesinkata.h"
// #include "ADT/Mesin_Baris/mesinbaris.h"
// #include "ADT/Queue/circular_queue.h"
// #include "ADT/Stack/stack.h"


#ifndef HEADER_H
#define HEADER_H

// Daftar Header Command

extern char currentSong[NMax];
extern char currentPlaylist[NMax];

extern char listArtis[100][50];
extern Map listAlbum;
extern List listPlaylist;
extern Queue songQueue;
extern Stack songHistory;

#endif