#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    int fd=0;
    int fdnew=0;

    fd=open("demo.txt",O_RDONLY);
    printf("Fule opeened with fd :%d\n",fd);

    fdnew=dup(fd);
     printf("duplicate  fd :%d\n",fdnew);


   return 0;	
}
