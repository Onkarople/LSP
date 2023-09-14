#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>


//server for named pipe

int main()
{
  int fd=0;
  char *path="/tmp/mypipe";

  fd=mkfifo(path,0666);
  if(fd==-1)
  {
    printf("Unable to create named pipe\n");
  }

  return 0;
}
