#include "../ADT/Queue/circular_queue.h"
#include "showlist.h"
#include <stdio.h>

#ifndef __status__
#define __status__

void status(Queue queue, char* current_playlist, char* currentSong, Map listAlbum);
/* Menerima daftar lagu dalam queue dalam argumen queue, dan nama playlist yang diputar
   dalam argumen current_playlist. Bila queue sekarang bukan dari playlist maka argumen
   current_playlist yang dimasukkan adalah string kosong ("") 
   I.S. Queue terdefinisi
   F.S. Menampilkan status sesuai spesifikasi
   */

#endif