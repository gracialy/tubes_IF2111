#include <stdio.h>
#include "mesinkata.h"

Word currentWord;
char currentInput;

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentInput == MARK || currentInput == NEWLINE)
    {
        currentInput = getc(stdin);
    }
}

void STARTWORD(){
    currentInput = getc(stdin);
}

void ADVWORD()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks();
    CopyWord();
}

void CopyWord()
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    currentWord.Length = 0;
    while (currentInput != MARK && currentInput != NEWLINE)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentInput;
            currentInput = getc(stdin);
        }
        else
            break;
    }
    currentWord.TabWord[currentWord.Length] = '\0';
}

boolean isEqual(char* str){
    boolean isEqual = true;
    for (int i = 0; i < currentWord.Length; ++i)
    {
        if (currentWord.TabWord[i] != str[i] 
        && currentWord.TabWord[i] != str[i] + 32 
        && currentWord.TabWord[i] != str[i] - 32) 
        {
            isEqual = false;
        }
    }
    return isEqual;
}