#include <stdio.h>
#include "help.h"

void helpBeforeLoad()
{
    printf("==========================================================================++++++++++++++++++++++++\n");
    printf("  +:*+.+:*+.+:*+.+:*+.+:*+.  H E L P  M E N U   W A Y A N G W A V E.+*:+.+*:+.+*:+.+*:+.+*:+. \n\n");
    printf("1.  START               : Masuk ke sesi baru\n");
    printf("2.  LOAD <namafile.txt> : Mulai sesi Berdasarkan file Konfigurasi\n");
    printf("==================================================================================================\n");
}
/* I.S. sembarang */
/* F.S. mengembalikan output berupa daftar command yang dapat dimasukkan berikut fungsinya */

void helpAfterLoad(){
    printf("==========================================================================++++++++++++++++++++++++\n");
    printf("  +:*+.+:*+.+:*+.+:*+.+:*+.  H E L P  M E N U   W A Y A N G W A V E.+*:+.+*:+.+*:+.+*:+.+*:+. \n\n");
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
    printf("==================================================================================================\n");
}
/* I.S. sembarang */
/* F.S. mengembalikan output berupa daftar command yang dapat dimasukkan berikut fungsinya */