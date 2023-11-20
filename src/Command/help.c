#include <stdio.h>
#include "help.h"

void helpBeforeLoad()
{
    printf("==========================================================================++++++++++++++++++++++++\n");
    printf("  +:*+.+:*+.+:*+.+:*+.+:*+.  H E L P  M E N U   W A Y A N G W A V E.+*:+.+*:+.+*:+.+*:+.+*:+. \n\n");
    printf("1.  START               : Masuk ke sesi baru\n");
    printf("2.  LOAD                : Mulai sesi Berdasarkan file Konfigurasi\n");
    printf("==================================================================================================\n");
}
/* I.S. sembarang */
/* F.S. mengembalikan output berupa daftar command yang dapat dimasukkan berikut fungsinya */

void helpAfterLoad(){
    printf("==========================================================================++++++++++++++++++++++++\n");
    printf("  +:*+.+:*+.+:*+.+:*+.+:*+.  H E L P  M E N U   W A Y A N G W A V E.+*:+.+*:+.+*:+.+*:+.+*:+. \n\n");
    printf("1.  LIST                    : Berisi daftar penyanyi dan daftar playlist\n");
    printf("2.  PLAY                    : Untuk memutar lagu dan Playlist\n");
    printf("3.  QUEUE                   : Berisi antrian lagu yang dapat dimanipulasi oleh Pengguna\n");
    printf("4.  SONG                    : Untuk Navigasi Lagu\n");
    printf("5.  PLAYLIST                : Basic Command untuk Playlist\n");
    printf("6.  STATUS                  : Menampilkan lagu yang sedang dimainkan & Queue song yang ada ,dari playlist mana lagu itu diputar\n");
    printf("7.  SAVE<filename.txt>      : Menyimpan state aplikasi terbaru\n");
    printf("8.  SHOWPLAYLIST            : Menampilkan Playlist yang ada\n");
    printf("9.  QUIT                    : Keluar dari aplikasi WayangWave\n");
    printf("==================================================================================================\n");
}
/* I.S. sembarang */
/* F.S. mengembalikan output berupa daftar command yang dapat dimasukkan berikut fungsinya */