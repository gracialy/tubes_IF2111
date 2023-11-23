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
#include "Command/welcome.h"
#include "Command/help.h"
#include "Command/save.h"
#include "Command/quit.h"
#include "Command/enhance.h"

#ifndef HEADER_H
#define HEADER_H

// Daftar Header Command

extern char currentSong[NMax];
extern char currentPlaylist[NMax];

extern char listArtis[maxA][maxAN];
extern Map listAlbum;
extern List listPlaylist;
extern Queue songQueue;
extern Stack songHistory;

#endif