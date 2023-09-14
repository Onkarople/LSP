#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc,char *argv[])
{
    DIR *dp =NULL;
    struct dirent *entry=NULL;

    
    if(argc!=2)
    {
        printf("Insufficient parameters");
        return -1;

    }

    dp=opendir(argv[1]);
    if(dp==NULL)
    {
        printf("Unable to open directory");
        return -1;
    }
    printf("--------------------------------------------------------------------------\n");

    printf("Entries from the directory file are: \n");
    printf("--------------------------------------------------------------------------\n");
    printf("Inode number \t\t file Number\n");


    while((entry=readdir(dp))!=NULL)
    {
        printf("%20s:%ld\n",entry->d_name,entry->d_ino);
    }
    closedir(dp);


    return 0;
}
