#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>




int main()
{
  int FD[2];
  int iRet=0;
  char Arr[]="Marvellous Infosystems";
  char Buffer[512];

  pipe(FD);

  iRet=fork();

  if(iRet==0)
  {
    printf("child process schdeuled for writing from pipr\n");
    close(FD[0]);
    write(FD[1],Arr,strlen(Arr));
    exit(0);
  }
  else
  {
    printf("Parent process schdeuled for reading from pipr\n");
    close(FD[1]);
    read(FD[0],Buffer,sizeof(Buffer));
    printf("Data from PIPE is : %s\n",Buffer);
  }
                                             

  return 0;
}
