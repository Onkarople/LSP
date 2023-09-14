#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    struct stat sobj;
   

    if(argc!=2)
    {
        printf("Insufficient parameters");
        return -1;

    }
    

    stat(argv[1],&sobj);

    if(S_ISREG(sobj.st_mode))
    {
        printf("Its a regular file\n");
    }
    else if(S_ISDIR(sobj.st_mode))
    {
        printf("Its a directory\n");
    }
    else if(S_ISLNK(sobj.st_mode))
    {
        printf("Its suboloc link\n");
    }


    return 0;
}
