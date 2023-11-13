#include <stdio.h>
#include <time.h>
#include "mesinbaris.h"

boolean EndWord;
Word currentLine;
int currentInt;

void IgnoreNewline()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == NEWLINE && !isEOF())
    {
        ADV();
    }
}

void STARTFILE(char* path)
{
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START(path);
    IgnoreNewline();
}

void ADVFILE(boolean readDigit)
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreNewline();
    CopyLine(readDigit);
    // if (!retval)
    // {
    //     CopyLine(readDigit);
    // }
}

void CopyLine(boolean readDigit)
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    currentLine.Length = 0;
    
    if (readDigit)
    {
        while(currentChar != BLANK && currentChar != NEWLINE && !isEOF())
        {
            currentLine.TabWord[currentLine.Length++] = currentChar;
            ADV();
        }
        currentLine.TabWord[currentLine.Length] = '\0';
        currentInt = stringToInt(currentLine.TabWord);
        currentLine.Length = 0;
    }
    while(currentChar == BLANK) ADV();

    while(currentChar != NEWLINE && !isEOF())
    {
        currentLine.TabWord[currentLine.Length] = currentChar;
        currentLine.Length++;
        ADV();
    }
    currentLine.TabWord[currentLine.Length] = '\0';
}

int stringToInt(char* str){
    int res = 0;
    for (int i = 0; str[i] != '\0'; ++i){
        res = res * 10 + (str[i] - '0');
    }
    return res;
}
