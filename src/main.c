#include "main.h"

char listArtis[100][50];
Map listAlbum;

int main(){
    CreateMapEmpty(&listAlbum);
    konfigurasi(listArtis, &listAlbum);
    PrintMap(listAlbum);
}

