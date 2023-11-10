#include "main.h"

Word listArtis[100];
int nlistArtis = 0;

int main(){

}


void loadKonfigurasi(){
    STARTFILE();
    ADVFILE(true);
    int banyakArtis = currentInt;
    for (int i = 0; i < banyakArtis; ++i)
    {
        ADVFILE(true);
        int banyakAlbum = currentInt;
        listArtis[nlistArtis++] = currentLine;

        for (int j = 0; j < banyakAlbum; ++j)
        {
            ADVFILE(true);
            int banyakLagu = currentInt;
            
        }
    }

}