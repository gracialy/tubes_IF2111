#include <stdio.h>
#include "help.h"

void helpBeforeLoad()
{
    printf("==========================================================================++++++++++++++++++++++++\n");
    printf("  +:*+.+:*+.+:*+.+:*+.+:*+.  H E L P  M E N U   W A Y A N G W A V E.+*:+.+*:+.+*:+.+*:+.+*:+. \n\n");
    printf("1.  START               : Masuk ke sesi baru\n");
    printf("2.  LOAD                : Mulai sesi Berdasarkan file Konfigurasi\n");
    printf("3.  HELP                : Mengeluarkan deskripsi menu\n");
    printf("5.  QUIT                : Keluar dari aplikasi WayangWave\n");
    printf("==================================================================================================\n");
}
/* I.S. sembarang */
/* F.S. mengembalikan output berupa daftar command yang dapat dimasukkan berikut fungsinya */

void helpBeforeLog()
{
    printf("1.  LOGIN               : Masuk sebagai seorang user\n");
    printf("2.  HELP                : Mengeluarkan deskripsi menu\n");
    printf("3.  QUIT                : Keluar dari aplikasi WayangWave\n");
    printf("4.  SAVE <filename.txt> : Menyimpan state aplikasi terbaru\n");
    printf("==================================================================================================\n");
}

void helpAfterLoad(){
    printf("==========================================================================++++++++++++++++++++++++\n");
    printf("  +:*+.+:*+.+:*+.+:*+.+:*+.  H E L P  M E N U   W A Y A N G W A V E.+*:+.+*:+.+*:+.+*:+.+*:+. \n\n");
    printf("1.  LIST DEFAULT                : Berisi daftar penyanyi, album, dan lagu\n");
    printf("2.  LIST PLAYLIST               : Berisi daftar playlist dan isinya\n");
    printf("3.  PLAY SONG                   : Untuk memutar lagu \n");
    printf("4.  PLAYLIST                    : Untuk memutar playlist\n");
    printf("5.  QUEUE SONG                  : Untuk menambahkan lagu ke antrian\n");
    printf("6.  QUEUE PLAYLIST              : Untuk menambahkan playlist ke queue\n");
    printf("7.  QUEUE SWAP <x> <y>          : Untuk menukar posisi lagu di queue\n");
    printf("8.  QUEUE REMOVE <id>           : Untuk menghapus lagu pilihan dari queue\n");
    printf("9.  QUEUE CLEAR                 : Untuk menghapus semua lagu yang ada di queue\n");
    printf("10.  SONG NEXT                  : Untuk memutar lagu selanjutnya dari queue\n");
    printf("11.  SONG PREV                  : Untuk memutar lagu sebelumnya dari queue\n");
    printf("12.  PLAYLIST CREATE            : Untuk membuat sebuah playlist baru\n");
    printf("13.  PLAYLIST ADD SONG          : Untuk menambahkan lagu ke playlist\n");
    printf("14.  PLAYLIST ADD ALBUM         : Untuk menambahkan album ke playlist\n");
    printf("15.  PLAYLIST REMOVE <id> <n>   : Untuk menghapus lagu dari playlist\n");
    printf("16.  PLAYLIST DELETE            : Untuk menghapus playlist\n");
    printf("17.  PLAYLIST SWAP <id> <x> <y> : Untuk menukar posisi lagu pada playlist\n");
    printf("18.  STATUS                     : Menampilkan lagu yang sedang dimainkan, playlist yang sedang diputar, queue song dan history song\n");
    printf("19.  SAVE <filename.txt>        : Menyimpan state aplikasi terbaru\n");
    printf("20.  QUIT                       : Keluar dari aplikasi WayangWave\n");
    printf("21.  HELP                       : Mengeluarkan deskripsi menu\n");
    printf("22.  ENHANCE                    : Menambahkan rekomendasi random ke dalam playlist\n");
    printf("23.  LOGOUT                     : Keluar dari akun\n");
    printf("==================================================================================================\n");
}
/* I.S. sembarang */
/* F.S. mengembalikan output berupa daftar command yang dapat dimasukkan berikut fungsinya */