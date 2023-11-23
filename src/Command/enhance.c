#include "enhance.h"

int rng(int lower_bound, int upper_bound){
    return (rand() % (upper_bound - lower_bound + 1)) + lower_bound;
}

void enhance(){
    if (listPlaylist.Neff == 0) 
    {
        printf("Kamu tidak memiliki playlist.\n");
        return;
    }
    printf("Daftar playlist pengguna : \n");
	DisplayList(listPlaylist);
	printf("Masukkan ID Playlist yang dipilih : ");
	ADVWORD();
    int idx = stringToInt(currentWord.TabWord) - 1;
    if (idx < 0 || idx >= listPlaylist.Neff)
	{
		printf("ID playlist tidak ada !\n");
		return;
	}
    char songName[NMax], artist[NMax];
    Set album = getSet(listAlbum, rng(0, listAlbum.Count - 1));
    stringCopy(songName, album.Elements[rng(0, album.Count - 1)]);
    InsertLastLL(&listPlaylist.A[idx], songName);
    getArtist(songName, artist);
    printf("Berhasil menambahkan lagu %s dari %s ke dalam playlist %s\n", songName, artist, listPlaylist.A[idx].Name);
}