#include "user.h"

void CreateLUser(){
  for (int i = 0; i < maxuser; ++i)
  {
    stringCopy(listUser.username[i], "");
    stringCopy(listUser.nowplaying[i], "");
    CreateQueue(&listUser.queue[i]);
    CreateEmptySt(&listUser.history[i]);
    listUser.playlist[i] = MakeList();
  }
}

void login(){
  printf("Masukkan username User Wayangwave: ");
  ADVWORD();
  getWord(0, username);

  int idx = UserIdx(username);
  if (idx != -1)
  {
    stringCopy(currentSong, listUser.nowplaying[idx]);
    songQueue = listUser.queue[idx];
    songHistory = listUser.history[idx];
    listPlaylist = listUser.playlist[idx];
    printf("Selamat datang, %s!\n", username);
  }
  else
  {
    printf("Tidak ada user dengan username \"%s\"\n", username);
    login();
  }
}

void logout(){
  int idx = UserIdx(username);
  stringCopy(currentSong, listUser.nowplaying[idx]);
  listUser.queue[idx] = songQueue;
  listUser.history[idx] = songHistory;
  listUser.playlist[idx] = listPlaylist;

  stringCopy(currentSong, "");
  CreateQueue(&songQueue);
  CreateEmptySt(&songHistory);
  printf("masuk\n");
  DeallocateArrayDIN(&listPlaylist);
  listPlaylist = MakeList(); // dealloc?
  printf("Berhasil keluar. Sampai jumpa lagi, %s!\n", username);
  username[0] = '\0';
}

int UserIdx(char* temp){
  int idx = -1;
  for (int i = 0; i < banyakUser; ++i)
  {
    if (CompareString(listUser.username[i], temp))
    {
      idx = i;
      break;
    }
  }
  return idx;
}