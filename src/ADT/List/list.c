#include <stdio.h>
#include "list.h"

List MakeList(){
    List GE;
    GE.Capacity = InitialSize;
    GE.Neff = 0;
    GE.A = (ElTypeL*) malloc(InitialSize * sizeof(ElTypeL));
    return GE;
}

void DeallocateArrayDIN(List *GE){
    free(GE->A);
    GE->A = NULL;
    GE -> Capacity = 0;
    GE -> Neff = 0;
}

boolean IsEmptyL(List GE){
    return(GE.Neff == 0);
}

int lengthL(List GE){
    return(GE.Neff);
}

ElTypeL GetL(List GE, IdxTypeL i){
    return(GE.A[i]);  
}

int GetCapacity(List GE){
    return(GE.Capacity);
}

void AddElementL(List* GE, char* playlistName){
    if ((GE->Neff)==(GE->Capacity))
    {
        int Capacity2 = 2*((*GE).Capacity);
        ElTypeL *temp = (ElTypeL*) realloc(GE->A, Capacity2 * sizeof(ElTypeL));
        if (temp != NULL)
        {
            GE->A = temp;
            GE->Capacity = Capacity2;   
        }
    }
    stringCopy(GE->A[GE->Neff].Name, playlistName);
    GE->A[GE->Neff].First = NilLL;
    GE->Neff ++;
}

void DeleteAt(List *GE, IdxTypeL i){
    for(int j = i; j< (*GE).Neff;j++){
        (*GE).A[j] = (*GE).A[j+1];
    }
    (*GE).Neff --;
}

void DisplayList(List L){
    for (int i = 0; i < L.Neff; ++i)
    {
        printf("  %d. %s\n", i + 1, L.A[i].Name);
    }
}