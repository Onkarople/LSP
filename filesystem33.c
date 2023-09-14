#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
   int fd=0;

   if(argc!=2)
   {
    printf("insufficient arguments..\n");
    return -1;
   }

   fd=open(argv[1],O_RDWR);
   if(fd!=-1)
   {
    printf("file is existing %d\n",fd);
   }
   else
   {
    fd=creat(argv[1],0777);
    if(fd!=-1)
    {
        printf("New file is created\n");
    }
   }


    return 0;
}
