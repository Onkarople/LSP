#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<sys/shm.h>


//server for shared pipe

int main()
{
  int shmid=0;
  int shmsize=100;
  int key=1234;
  char *ptr=NULL;

  printf("Server application renning...\n");

  shmid=shmget(key,shmsize,IPC_CREAT | 0666);

  printf("shared memroy allocated succesfully..\n");

  ptr=shmat(shmid,NULL,0);

  if(ptr!=NULL)
  {
    printf("shared memory attched succesfully..\n");
  }

  return 0;
}
