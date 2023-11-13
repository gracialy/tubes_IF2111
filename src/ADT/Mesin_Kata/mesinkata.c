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

boolean isEqual(int idx, char* str){
    boolean isEqual = true;
    int i;
    if (idx == - 1)
    {
        for (i = 0; i < currentWord.Length; ++i)
        {
            if (currentWord.TabWord[i] != str[i] 
            && currentWord.TabWord[i] != str[i] + 32 
            && currentWord.TabWord[i] != str[i] - 32) 
            {
                isEqual = false;
            }
        }
    }
    else
    {
        char temp[NMax];
        getWord(idx, temp);
        for (i = 0; temp[i] != '\0'; ++i)
        {
            if (temp[i] != str[i] 
            && temp[i] != str[i] + 32 
            && temp[i] != str[i] - 32) 
            {
                isEqual = false;
            }
        }
    }
    if (str[i] != '\0') isEqual = false;
    return isEqual;
}

void getWord(int idx, char* output){
    int outputLen = 0;
    for (int i = 0; i < currentWord.Length; ++i)
    {
        if (idx > 0 && currentWord.TabWord[i] == BLANK) idx--;
        else if (idx == 0)
        {
            if (currentWord.TabWord[i] == BLANK) break;
            output[outputLen++] = currentWord.TabWord[i];
        }
    }
    output[outputLen] = '\0';
}

void stringCopy(char* target, char* copy){
    int i;
    for (i = 0; copy[i] != '\0'; ++i)
    {
        target[i] = copy[i];
    }
    target[i] = '\0';
}