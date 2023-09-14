#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc,char *argv[])
{
    int fd=0;

    printf("Usage : name _Of_Executable Name_Of__File \n");

    if(argc!=2)
    {
        printf("invalid number of arguments\n");
        return -1;
    }


    fd=creat(argv[1],0777);
    if(fd==-1)
    {
        printf("Unable to open file\n");
    }
    else
    {
        printf("File is succesfully opened with fd : %d\n",fd);
    }

    return 0;
}

//O_RDONLY
//O_RDWR
//o-WRONLY
//O_CREATE