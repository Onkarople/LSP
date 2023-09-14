#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>



int main()
{

   int fd=0;
   char Buffer[512];
   int iCnt=0;
   int iRet=0;


   fd=open("demo.txt",O_RDONLY);

   while((iRet=read(fd,Buffer,sizeof(Buffer)))!=0)
   {
     for(int i=0;i<iRet;i++)
     {
        if((Buffer[i]>='A')&&(Buffer[i]<='Z'))
        {
            iCnt++;
        }
     }
   }
   printf("Number of Capital leters are:%d\n",iCnt);

   close(fd);
    

    return 0;
}
