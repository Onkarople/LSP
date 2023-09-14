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

    printf("FIle name is %s\n",argv[1]);
    printf("file size is :%d\n",sobj.st_size);
    printf("Number of links:%d\n",sobj.st_nlink);
    printf("Inode Number:%d\n",sobj.st_ino);
    printf("file system number:%d\n",sobj.st_dev);
    printf("number of blocks :%d\n",sobj.st_blocks);


    return 0;
}
