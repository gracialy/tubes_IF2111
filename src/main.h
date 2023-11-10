#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../Command/boolean.h"
#include "../ADT/list/list.h"
#include "../ADT/Map/map.h"
#include "../ADT/Mesin_Karakter/mesinkarakter.h"
#include "../ADT/Mesin_Kata/mesinkata.h"
#include "../ADT/Mesin_Baris/mesinbaris.h"
#include "../ADT/Queue/circular_queue.h"
#include "../ADT/Stack/stack.h"


#ifndef HEADER_H
#define HEADER_H

// Daftar Header Command

extern Word listArtis;
extern int nlistArtis;

void loadKonfigurasi();

#endif