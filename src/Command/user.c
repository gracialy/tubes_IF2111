#include "user.h"

void CreateLUser(){
  stringCopy(&listUser->username, "");
  for (int i = 0; i < maxuser; ++i)
  {
    stringCopy(&listUser->nowplaying[i], "");
    CreateQueue(&listUser->queue[i]);
    CreateEmptySt(&listUser->history[i]);
    &listUser->playlist[i] = MakeList();
  }

}

void login(){
  char username[NMax];
  printf("Masukkan username User Wayangwave: ");
  getWord(1, &username);

  int idx = UserIdx(listUser, username);
  if (idx != -1){
    stringCopy(currentSong, listUser.nowplaying[idx]);
    songQueue = listUser.queue[idx];
    songHistory = listUser.history[idx];
    listPlaylist = listUser.playlist[idx];
    printf("Selamat datang, %s!\n", username);
  } else {
    printf("Tidak ada user dengan username \"%s\"\n", username);
    login();
  }
}

void logout(){
  int idx = UserIdx(listUser, currentWord.TabWord);
  stringCopy(currentSong, listUser.nowplaying[idx]);
  listUser.queue[idx] = songQueue;
  listUser.history[idx] = songHistory;
  listUser.playlist[idx] = listPlaylist;

  stringCopy(currentSong, "");
  CreateQueue(&songQueue);
  CreateEmptySt(&songHistory);
  listPlaylist = MakeList(); // dealloc?
  printf("Berhasil keluar. Sampai jumpa lagi, %s!\n", currentWord.TabWord);
}

int UserIdx(){
  int idx = -1;
  for (int i = 0; i < listUser.Count; ++i)
  {
    if (CompareString(listUser.Elements[i].username, currentWord.TabWord))
    {
      idx = i;
      break;
    }
  }
  return idx;
}