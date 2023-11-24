#include <stdio.h>
#include "help.h"

void helpBeforeLoad()
{
    printf("==========================================================================++++++++++++++++++++++++\n");
    printf("  +:*+.+:*+.+:*+.+:*+.+:*+.  H E L P  M E N U   W A Y A N G W A V E.+*:+.+*:+.+*:+.+*:+.+*:+. \n\n");
    printf("1.  START               : Masuk ke sesi baru\n");
<<<<<<< HEAD
    printf("2.  LOAD <namafile.txt> : Mulai sesi Berdasarkan file Konfigurasi\n");
=======
    printf("2.  LOAD                : Mulai sesi Berdasarkan file Konfigurasi\n");
    printf("3.  HELP                : Mengeluarkan deskripsi menu\n");
    printf("5.  QUIT                : Keluar dari aplikasi WayangWave\n");
>>>>>>> 14c58e06280976d0cc0bbdbe1e6a183d01a78498
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
<<<<<<< HEAD
    printf("1.  LIST                    : Berisi perintah umum untuk menampilkan lagu dan playlist. Silahkan pilih salah satu dari command berikut:\n");
    printf("    a.  LIST DEFAULT        : Berisi daftar penyanyi yang ada pada program\n");
    printf("    b.  LIST PLAYLIST       : Berisi daftar Playlist yang ada\n");
    printf("\n");
    printf("2.  PLAY                    : Berisi perintah umum untuk memutar lagu dan Playlist.Silahkan pilih salah satu dari command berikut:\n");
    printf("    a.  PLAY SONG           : Memutar yang ada pada program\n");
    printf("    b.  PLAY PLAYLIST       : Memutar Playlist yang ada\n");
    printf("\n");
    printf("3.  QUEUE                   : Berisi perintah umum tentang antrian lagu yang dapat dimanipulasi oleh Pengguna. Silahkan pilih salah satu dari command berikut:\n");
    printf("    a.  QUEUE SONG          : Menambahkan lagu ke dalam antrian\n");
    printf("    b.  QUEUE PLAYLIST          : Menambahkan lagu yang ada dalam playlist ke antrian\n");
    printf("    c.  QUEUE SWAP              : Menukar urutan dua buah lagu\n");
    printf("    d.  QUEUE REMOVE <id>       : Menghapus lagu dari antrian\n");
    printf("    e.  QUEUE CLEAR             : Mengosongkan antrian lagu\n");
    printf("\n");
    printf("4.  SONG                        : Perintah umum untuk Navigasi Lagu.Silahkan pilih salah satu dari command berikut:\n");
    printf("    a.  SONG NEXT               : Memutar lagu selanjutnya yang ada dalam antrian.\n");
    printf("    b.  SONG PREVIOUS           : Memutar lagu yang terakhir kali diputar\n");
    printf("\n");
    printf("5.  PLAYLIST                    : Basic Command untuk Playlist.Silahkan pilih salah satu dari command berikut:\n");
    printf("    a.  PLAYLIST CREATE         : Membuat playlist baru\n");
    printf("    b.  PLAYLIST ADD            : Menambahkan lagu pada suatu playlist yang telah ada\n");
    printf("    c.  PLAYLIST SWAP <id> <x> <y>  : Menukar \n");
    printf("    d.  PLAYLIST REMOVE     : Menghapus lagu dari antrian\n");
    printf("    e.  PLAYLIST DELETE     : Mengosongkan antrian lagu\n");
    printf("\n");
    printf("6.  STATUS                  : Menampilkan lagu yang sedang dimainkan & Queue song yang ada ,dari playlist mana lagu itu diputar\n");
    printf("7.  SAVE <namafile.txt>     : Menyimpan state aplikasi terbaru\n");
    printf("8.  SHOWPLAYLIST            : Menampilkan Playlist yang ada\n");
    printf("9.  QUIT                    : Keluar dari aplikasi WayangWave\n");
=======
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
>>>>>>> 14c58e06280976d0cc0bbdbe1e6a183d01a78498
    printf("==================================================================================================\n");
}
/* I.S. sembarang */
/* F.S. mengembalikan output berupa daftar command yang dapat dimasukkan berikut fungsinya */