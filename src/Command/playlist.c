#include "playlist.h"

void CreatePlaylist(){
	printf("Masukkan nama playlist yang ingin dibuat : ");
	ADVWORD();
    while (effName(currentWord)<3 || isAllSpace(currentWord)){
        printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist.\nSilahkan coba lagi\n");
        // printf("Masukkan nama playlist yang ingin dibuat : ");
        // ADVWORD();
        return;
    }
	AddElementL(&listPlaylist, currentWord.TabWord);
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

void InsertPlaylist(){
	if (listPlaylist.Neff == 0) 
    {
        printf("Kamu tidak memiliki playlist.\n");
        return;
    }
	// if (SelectSong(listArtis, listAlbum, song)) return;
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
        printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi !\n", currentWord.TabWord);
        return;
    }
    
    printf("Daftar album oleh %s :\n", currentWord.TabWord);
    idx = 1;
    for (int i = 0; i < listAlbum.Count; ++i)
    {
        if (CompareString(listAlbum.Elements[i].Value, currentWord.TabWord))
        {
            printf("  %d. %s\n", idx ++, getSet(listAlbum, i).Name);
        }
    }

    printf("Masukkan Judul Album yang dipilih : ");
    ADVWORD();
	char album[NMax];
	stringCopy(album, currentWord.TabWord);
    if (!IsMemberMap(listAlbum, album))
    {
        printf("Album %s tidak ada dalam daftar. Silakan coba lagi !\n", album);
        return;
    }

    idx = 0;
    while (!CompareString(getSet(listAlbum, idx).Name, currentWord.TabWord)) idx++;
    for (int i = 0; i < getSet(listAlbum, idx).Count; ++i)
    {
        printf("  %d. %s\n", i + 1, getSet(listAlbum, idx).Elements[i]);
    }
    printf("Masukkan ID Lagu yang dipilih : ");
    ADVWORD();
    char input[NMax]; getWord(0, input);
    if (stringToInt(input) <= 0 || stringToInt(input) > getSet(listAlbum, idx).Count)
    {
        printf("ID yang dimasukkan tidak ada\n");
        return;
    }
    char song[NMax];
    stringCopy(song, getSet(listAlbum, idx).Elements[stringToInt(input) - 1]);
    
    printf("Daftar playlist pengguna : \n");
	DisplayList(listPlaylist);
	printf("Masukkan ID Playlist yang dipilih : ");
	ADVWORD();
	idx = stringToInt(currentWord.TabWord) - 1;
	if (idx < 0 || idx >= listPlaylist.Neff)
	{
		printf("ID playlist tidak ada !\n");
		return;
	}

	InsertLastLL(&listPlaylist.A[idx], song);
    album[NMax]; char singer[NMax]; char playname[NMax];
    getAlbum(song, album);
    getArtist(song, singer);
    stringCopy(playname, listPlaylist.A[idx].Name);
    printf("Lagu dengan judul \"%s\" pada album %s oleh penyanyi %s berhasil ditambahkan ke dalam playlist %s\n", song, album, singer, playname);
}

void InsertAlbumToPlaylist(){
    if (listPlaylist.Neff == 0) 
    {
        printf("Kamu tidak memiliki playlist.\n");
        return;
    }
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
        printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi !\n", currentWord.TabWord);
        return;
    }
    
    printf("Daftar album oleh %s :\n", currentWord.TabWord);
    idx = 1;
    for (int i = 0; i < listAlbum.Count; ++i)
    {
        if (CompareString(listAlbum.Elements[i].Value, currentWord.TabWord))
        {
            printf("  %d. %s\n", idx ++, getSet(listAlbum, i).Name);
        }
    }

    printf("Masukkan Judul Album yang dipilih : ");
    ADVWORD();
	char album[NMax];
	stringCopy(album, currentWord.TabWord);
    if (!IsMemberMap(listAlbum, album))
    {
        printf("Album %s tidak ada dalam daftar. Silakan coba lagi !\n", album);
        return;
    }

	printf("Daftar playlist yang kamu miliki : \n");
    DisplayList(listPlaylist);
	printf("Masukkan ID Playlist yang dipilih : ");
	ADVWORD();
	int idxPlaylist = stringToInt(currentWord.TabWord) - 1;
    if (idx < 0 || idxPlaylist >= listPlaylist.Neff)
	{
		printf("ID playlist tidak ada !\n");
		return;
	}

    idx = 0;
    while (!CompareString(getSet(listAlbum, idx).Name, album)) idx++;
    for (int i = 0; i < getSet(listAlbum, idx).Count; ++i)
    {
        InsVLast(&listPlaylist.A[idxPlaylist], getSet(listAlbum, idx).Elements[i]);
    }
    printf("Album dengan judul %s berhasil ditambahkan pada playlist pengguna \"%s\"\n", album, listPlaylist.A[idxPlaylist].Name);
}

void playlistRemove(){
    char idstr[NMax], nstr[NMax];
    getWord(2, idstr); getWord(3, nstr);
    int id = stringToInt(idstr), n = stringToInt(nstr);

    if (id > listPlaylist.Neff || id<=0){
        printf("ID Playlist tidak valid\n");
        return;
    }
    char namaplaylist[NMax]; 
    stringCopy(namaplaylist, listPlaylist.A[id-1].Name);
    if ((n > NbElmt(listPlaylist.A[id - 1]) || n<=0)){
        printf("Urutan lagu tidak valid\n");
        return;
    }
    char namalagu[NMax]; char namapenyanyi[NMax];
    stringCopy(namalagu, GetLL(listPlaylist.A[id - 1], n-1));
    getArtist(namalagu, namapenyanyi);
    printf("Lagu \"%s\" oleh \"%s\" telah dihapus dari playlist \"%s\"\n", namalagu, namapenyanyi, namaplaylist);
    
}

void playlistSwap(){
    char idxstr[NMax], xstr[NMax], ystr[NMax];
    getWord(2, idxstr); getWord(3, xstr); getWord(4, ystr);
    // if (CompareString(idxstr, " ") || CompareString(xstr, " ") || CompareString(ystr, " "))
    // {
    //     printf("Command yang dimasukkan tidak valid\n");
    //     return;
    // }

    int idx = stringToInt(idxstr), x = stringToInt(xstr), y = stringToInt(ystr);
    if (idx > listPlaylist.Neff || idx<=0){
        printf("ID Playlist tidak valid\n");
        return;
    }
    char namaplay[NMax]; 
    stringCopy(namaplay, listPlaylist.A[idx-1].Name);
    if ((x > NbElmt(listPlaylist.A[idx - 1]) || x<=0) && (y > NbElmt(listPlaylist.A[idx - 1]) || y<=0)){
        printf("Urutan lagu tidak valid\n");
        return;
    }

    char lagu1[NMax];
    stringCopy(lagu1, GetLL(listPlaylist.A[idx - 1], x-1));
    char lagu2[NMax]; 
    stringCopy(lagu2, GetLL(listPlaylist.A[idx - 1], y-1));
    swapLinkedList(&listPlaylist.A[idx - 1], x, y);
    printf("Berhasil menukar lagu dengan nama \"%s\" dan \"%s\" di playlist %s\n", lagu1, lagu2, namaplay);
}

void playlistDelete(){
    printf("Daftar playlist yang kamu miliki : \n");
    if (listPlaylist.Neff == 0) 
    {
        printf("Kamu tidak memiliki playlist.\n");
        return;
    }
    DisplayList(listPlaylist);
    printf("Masukkan ID playlist yang dipilih : ");
    ADVWORD();
    char temp[NMax];
    getWord(0, temp);
    int idx = stringToInt(temp) - 1;
    if (idx < 0 || idx >= listPlaylist.Neff)
    {
        printf("Tidak ada playlist dengan ID %d dalam daftar playlist pengguna.\nSilakan coba lagi !\n", idx+1);
        return;
    }
    char namaplay[NMax]; 
    stringCopy(namaplay, listPlaylist.A[idx].Name);
    DeleteAt(&listPlaylist, idx);
    printf("Playlist ID %d dengan judul \"%s\" berhasil dihapus\n", idx+1, namaplay);
}
