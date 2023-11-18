#include <stdio.h>
#include "map.h"

void CreateMapEmpty(Map *M)
{
    M->Count = Nil;
}

boolean IsMapEmpty(Map M)
{
    return M.Count == Nil;
}

boolean IsMapFull(Map M)
{
    return M.Count == MaxElM;
}

valuetype Value(Map M, char *name)
{
    int i = 0;
    while (i < M.Count)
    {
        if (CompareString(M.Elements[i].Key.Name, name))
            ;
        {
            return M.Elements[i].Value;
        }
        i++;
    }
    return UndefinedM;
}

void InsertMap(Map *M, keytype k, valuetype v)
{
    if (!IsMapFull(*M))
    {
        M->Count++;
        M->Elements[M->Count - 1].Key = k;
        M->Elements[M->Count - 1].Value = v;
    }
}

void DeleteMap(Map *M, char *name)
{
    if (M->Count == 1)
    {
        M->Count = Nil;
    }
    else
    {
        if (IsMemberMap(*M, name))
        {
            int i = 0;
            while (i < M->Count && !CompareString(M->Elements[i].Key.Name, name))
            {
                i++;
            }
            while (i < M->Count)
            {
                M->Elements[i].Key = M->Elements[i + 1].Key;
                M->Elements[i].Value = M->Elements[i + 1].Value;
                i++;
            }
            M->Count--;
        }
    }
}

boolean IsMemberMap(Map M, char *name)
{
    int i = 0;
    while (i < M.Count)
    {
        if (CompareString(M.Elements[i].Key.Name, name))
        {
            return true;
        }
        i++;
    }
    return false;
}

// Map UnionMap(Map m1, Map m2, boolean key_based )
// {
// 	Map m3;
// 	CreateMapEmpty(&m3);
// 	for(int i=0; i<m1.Count ; i++){
// 		Insert(&m3,m1.Elements[i].Key,m1.Elements[i].Value);
// 	}
// 	for(int j=0; j<m2.Count ; j++){
// 		Insert(&m3,m2.Elements[j].Key,m2.Elements[j].Value);
// 	}
// 	if (key_based) {
// 		for (int k=0 ; k<m3.Count-1 ; k++){
// 			for (int l=k+1; l<m3.Count ; l++){
// 				if (wordToInt(m3.Elements[k].Key) > wordToInt(m3.Elements[l].Key)){
// 					info temp;
// 					temp=m3.Elements[k];
// 					m3.Elements[k]=m3.Elements[l];
// 					m3.Elements[l]=temp;
// 				}
// 			}
// 		}
// 	}
// 	else{
// 		for (int k=0 ; k<m3.Count-1 ; k++){
// 			for (int l=k+1; l<m3.Count ; l++){
// 				if (m3.Elements[k].Value>m3.Elements[l].Value){
// 					info temp;
// 					temp=m3.Elements[k];
// 					m3.Elements[k]=m3.Elements[l];
// 					m3.Elements[l]=temp;
// 				}
// 				else if (m3.Elements[k].Value==m3.Elements[l].Value) {
// 					if (wordToInt(m3.Elements[k].Key) > wordToInt(m3.Elements[l].Key)){
// 						info temp;
// 						temp=m3.Elements[k];
// 						m3.Elements[k]=m3.Elements[l];
// 						m3.Elements[l]=temp;
// 					}
// 				}
// 			}
// 		}
// 	}
// 	return m3;
// }

void PrintMap(Map m)
{
    for (int i = 0; i < m.Count; ++i)
    {
        printf("<%s, %s>\n", m.Elements[i].Value, m.Elements[i].Key.Name);

        for (int j = 0; j < m.Elements[i].Key.Count; ++j)
        {
            printf("%d. %s\n", j + 1, m.Elements[i].Key.Elements[j]);
        }
    }
}

int GetIdx(Map m, valuetype artistName)
{
    for (int i = 0; i < m.Count; ++i)
    {
        if (CompareString(m.Elements[i].Value, artistName))
        {
            return i;
        }
    }
    return -1;
}
