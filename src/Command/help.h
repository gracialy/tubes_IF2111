#include <stdio.h>

#ifndef __HELP__
#define __HELP__

void helpBeforeLoad();
/* I.S. aplikasi WayangWave belum dimulai */
/* F.S. mengembalikan output berupa daftar command yang dapat dimasukkan berikut fungsinya */

void helpBeforeLog();
/* I.S. aplikasi WayangWave sudah dimulai, pengguna belum login */ 
/* F.S. mengembalikan output berupa daftar command yang dapat dimasukkan berikut fungsinya */

void helpAfterLoad();
/* I.S. aplikasi WayangWave sudah dimulai, pengguna sudah login */
/* F.S. mengembalikan output berupa daftar command yang dapat dimasukkan berikut fungsinya */

#endif