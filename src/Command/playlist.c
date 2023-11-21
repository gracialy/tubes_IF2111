#include "playlist.h"

void CreatePlaylist(List* playlist, char listArtis[maxA][maxAN], Map listAlbum){
	printf("Masukkan nama playlist yang ingin dibuat : ");
	ADVWORD();
    while (effName(currentWord)<3 || isAllSpace(currentWord)){
        printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist.\nSilahkan coba lagi\n");
        printf("Masukkan nama playlist yang ingin dibuat : ");
        ADVWORD();
    }
	AddElementL(playlist, currentWord.TabWord);
	printf("Playlist %s berhasil dibuat! \nSilakan masukkan lagu - lagu artis terkini kesayangan Anda!\n", currentWord.TabWord);
}

boolean isAllSpace(Word word){
    boolean allSpace = true;
    for (int i = 0; i < word.Length; ++i)
    {
        if (word.TabWord[i] != ' ')
        {
            allSpace = false;
            break;
        }
    }
    return allSpace;
}

int effName(Word word){
    int count = 0;
    for (int i = 0; i < word.Length; ++i)
    {
        if (word.TabWord[i] != ' ')
        {
            count++;
        }
    }
    return count;
}

void InsertPlaylist(List* playlist, char listArtis[maxA][maxAN], Map listAlbum){
	char song[NMax];
	if (SelectSong(listArtis, listAlbum, song)) return;
	printf("Daftar playlist pengguna : \n");
	DisplayList(*playlist);
    if (playlist->Neff == 0) return;
	printf("Masukkan ID Playlist yang dipilih : ");

	ADVWORD();
	int idx = stringToInt(currentWord.TabWord) - 1;
	if (idx < 0 || idx >= playlist->Neff)
	{
		printf("ID album tidak ada !\n");
		return;
	}
	InsertLastLL(&playlist->A[idx], song);
}

void InsertAlbumToPlaylist(List* playlist, char listArtis[maxA][maxAN], Map listAlbum){
	int idx;
	printf("Daftar penyanyi :\n");
    for (int i = 0; listArtis[i][0] != '\0'; ++i)
    {
        printf("  %d. %s\n", i + 1, listArtis[i]);
    }

    printf("Masukkan Nama Penyanyi : ");
    ADVWORD();
    if (GetIdx(listAlbum, currentWord.TabWord) == -1)   /* cek apakah penyanyi ada atau tidak*/
    {
        printf("Penyanyi tidak ditemukan !\n");
        return;
    }
    
    idx = 1;
    for (int i = 0; i < listAlbum.Count; ++i)
    {
        if (CompareString(listAlbum.Elements[i].Value, currentWord.TabWord))
        {
            printf("  %d. %s\n", idx ++, getSet(listAlbum, i).Name);
        }
    }

    printf("Masukkan Nama Album yang dipilih : ");
    ADVWORD();
	char album[NMax];
	stringCopy(album, currentWord.TabWord);

	printf("Daftar playlist yang kamu miliki : \n");
    if (listPlaylist.Neff == 0) 
    {
        printf("Kamu tidak memiliki playlist.\n");
        return;
    }
    DisplayList(listPlaylist);
    if (playlist->Neff == 0) return;
	printf("Masukkan ID Playlist yang dipilih : ");
	ADVWORD();
	int idxPlaylist = stringToInt(currentWord.TabWord) - 1;
	
	if (IsMemberMap(listAlbum, album))
    {
        idx = 0;
        while (!CompareString(getSet(listAlbum, idx).Name, album)) idx++;
        for (int i = 0; i < getSet(listAlbum, idx).Count; ++i)
        {
			InsVLast(&playlist->A[idxPlaylist], getSet(listAlbum, idx).Elements[i]);
        }
    }
    else
    {
        printf("Album tidak ditemukan !\n");
        return;
    }
}

void playlistRemove(List* listPlaylist){
    char idstr[NMax], nstr[NMax];
    getWord(2, idstr); getWord(3, nstr);
    int id = stringToInt(idstr), n = stringToInt(nstr);

    printf("Start checking\n");
    if (listPlaylist->Neff < id){
        printf("Tidak ada playlist dengan ID %d.\n", id);
        return;
    }
    char * namaplaylist = listPlaylist->A[id-1].Name;
    if (NbElmt(listPlaylist->A[id-1]) < n){
        printf("Tidak ada lagu urutan %d di playlist \"%s\"!\n", id, namaplaylist);
        return;
    }
    // char * namalagu = GetL(listPlaylist->A[id-1], n).;
    // char * namapenyanyi = GetL(listPlaylist->A[id-1], n);

    printf("Lagu \"\" oleh \"\" telah dihapus dari playlist \"%s\"", namaplaylist);
}

void playlistSwap(List* listPlaylist){
    char idxstr[NMax], xstr[NMax], ystr[NMax];
    getWord(2, idxstr); getWord(3, xstr); getWord(4, ystr);
    int idx = stringToInt(idxstr), x = stringToInt(xstr), y = stringToInt(ystr);
    if (idx > listPlaylist->Neff){
        printf("Tidak ada playlist dengan ID %d\n", idx);
        return;
    }
    if (x > NbElmt(listPlaylist->A[idx - 1]) || y > NbElmt(listPlaylist->A[idx - 1])){
        if (x > NbElmt(listPlaylist->A[idx - 1]) && y > NbElmt(listPlaylist->A[idx - 1])){
            printf("Tidak ada lagu dengan urutan %d atau %d di playlist %d\n", x, y, idx);
            return;
        }
        else if(x > NbElmt(listPlaylist->A[idx - 1])){
            printf("Tidak ada lagu dengan urutan %d di playlist %d\n", x, idx);
            return;
        }
        else if (y > NbElmt(listPlaylist->A[idx - 1])){
            printf("Tidak ada lagu dengan urutan %d di playlist %d\n", y, idx);
            return;
        }
    }
    // char namaplaylist[] = GetList(listPlaylist, idx-1);
    // char lagu1[] = getLLidx(listPlaylist->A[idx - 1], x - 1);
    // char lagu2[] = getLLidx(listPlaylist->A[idx - 1], y - 1);
    swapLinkedList(&listPlaylist->A[idx - 1], x, y);
    // printf("Berhasil menukar lagu dengan nama \"%s\" dan \"%s\" di playlist %d\n", lagu1, lagu2, namaplaylist);
}

void playlistDelete(List* listPlaylist){
    showPlaylist(*listPlaylist);
    if (listPlaylist->Neff == 0) return;
    printf("Masukkan ID playlist yang dipilih : ");
    ADVWORD();
    char temp[NMax];
    getWord(0, temp);
    int idx = stringToInt(temp) - 1;
    if (idx < 0 || idx >= listPlaylist->Neff)
    {
        printf("ID yang dimasukkan tidak valid !\n");
        return;
    }
    DeleteAt(listPlaylist, idx);
    printf("Playlist berhasil dihapus\n");
}
