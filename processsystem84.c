#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<sys/shm.h>


//server for named pipe

int main()
{
  int shmid=0;
  int shmsize=100;
  int key=1234;

  printf("Server application renning...\n");

  shmid=shmget(key,shmsize,IPC_CREAT | 0666);

  printf("shared memroy allocated succesfully..\n");

  return 0;
}
