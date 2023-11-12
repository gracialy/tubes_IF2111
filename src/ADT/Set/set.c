#include "set.h"

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S){
        (*S).Count = NilS;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

void RenameSet(Set *S, char* str){
        int i;
        for (i = 0; str[i] != '\0'; ++i)
        {
                S->Name[i] = str[i];
        }
        S->Name[i] = '\0';
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S){
        return S.Count == NilS;
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFull(Set S){
        return S.Count == MaxElS;
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void InsertSet(Set *S, infotypeS* Elmt){
        if (!IsMember(*S, Elmt)){
                int i;
                for (i = 0; Elmt[i] != '\0'; ++i)
                {
                        S->Elements[S->Count][i] = Elmt[i];
                }
                S->Elements[S->Count][i] = '\0';
                S->Count++;
        }        
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

// void Delete(Set *S, infotypeS Elmt){
//         if(IsMember(*S, Elmt)){
//                 int i = 0;
//                 while((*S).Elements[i] != Elmt){
//                 i++;
//                 }
//                 while(i < (*S).Count){
//                 (*S).Elements[i] = (*S).Elements[i+1];
//                 i++;
//                 }
//                 (*S).Count--;
//         }   
// }
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMember(Set S, infotypeS* Elmt){
        int i = 0;
        while(i < S.Count){
                if(CompareStringS(S.Elements[i], Elmt)){
                return true;
                }
                i++;
        }
        return false;
}
/* Mengembalikan true jika Elmt adalah member dari S */

// Set SetUnion(Set s1, Set s2){
//         Set setunion;
//         CreateEmpty(&setunion);

//         for (int i=0; i<s1.Count; i++){
//                 InsertSet(&setunion, s1.Elements[i]);
//         }
//         // full handler?
//         int i=0;
//         while (i<s2.Count && !IsFull(setunion)){
//                 InsertSet(&setunion, s2.Elements[i]);
//                 i++;
//         }

//         return setunion;
// }
// Mengembalikan set baru yang berisi elemen-elemen yang terdapat pada s1 atau s2
// Contoh: [1, 2] U [2, 3] = [1, 2, 3]

// Set SetIntersection(Set s1, Set s2){
//         Set setintersect;
//         CreateEmpty(&setintersect);

//         for (int i=0; i<s1.Count; i++){
//                 if (IsMember(s2, s1.Elements[i])){\
//                         InsertSet(&setintersect, s1.Elements[i]);
//                 }
//         }

//         return setintersect;
// }
// Mengembalikan set baru yang berisi elemen-elemen dari s1 dan s2 yang terdapat pada kedua set
// Contoh: [1, 2] ∩ [2, 3] = [2]

// Set SetSymmetricDifference(Set s1, Set s2){
//         Set setsd;
//         CreateEmpty(&setsd);

//         for (int i=0; i<s1.Count; i++){
//                 if (!IsMember(s2, s1.Elements[i])){\
//                         InsertSet(&setsd, s1.Elements[i]);
//                 }
//         }

//         for (int i=0; i<s2.Count; i++){
//                 if (!IsMember(s1, s2.Elements[i])){\
//                         InsertSet(&setsd, s2.Elements[i]);
//                 }
//         }


//         return setsd;
// }
// Mengembalikan set baru yang berisi elemen yang ada di s1 atau s2, tapi tidak pada keduanya
// Contoh: [1, 2] ⊖ [2, 3] = [1, 3]

// Set SetSubtract(Set s1, Set s2){
//         Set setsubs;
//         CreateEmpty(&setsubs);

//         for (int i=0; i<s1.Count; i++){
//                 if (!IsMember(s2, s1.Elements[i])){\
//                         InsertSet(&setsubs, s1.Elements[i]);
//                 }
//         }

//         return setsubs;
// }
// Mengembalikan set baru yang berupa hasil pengurangan s1 dengan s2
// Contoh:
// s1 = [1, 2] s2 = [2, 3]
// s1 - s2 = [1]

void PrintSet(Set s){
        for (int i = 0; i < s.Count; ++i)
        {
                printf("%d. %s\n", i + 1, s.Elements[i]);
        }
}

boolean CompareStringS(char* a, char*b){
    int idx = 0;
    while (a[idx] == b[idx] && (a[idx] != '\0' || b[idx] != '\0'))
    {
        idx++;
    }
    if (a[idx] != b[idx]) return false;
    return true;
}