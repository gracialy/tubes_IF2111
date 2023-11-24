#ifndef multiuser_H
#define multiuser_H

#include "boolean.h"
#include "../ADT/Mesin_Kata/mesinkata.h"
#include "../ADT/Queue/circular_queue.h"
#include "../ADT/Stack/stack.h"
#include "../ADT/List/list.h"
#include "../main.h"

#define maxuser 10

typedef struct { 
  char username[maxuser][NMax];
  char nowplaying[maxuser][NMax];
  Queue queue[maxuser];
  Stack history[maxuser];
  List playlist[maxuser];
} User;

extern User listUser;
extern char username[NMax];

void CreateLUser();

void login();

void logout();

int UserIdx(char* temp);

#endif