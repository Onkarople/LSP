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
    char name[256];
    

    
    if(argc!=3)
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
   
    
    while((entry=readdir(dp))!=NULL)
    {
        if(strcmp(argv[2],entry->d_name)==0)
        {
          printf("File is presnet \n");
          sprintf(name,"%s/%s",argv[1],argv[2]);
          remove(name);
          printf("File is succesfully deleted\n");
          break;
        }      
    }
        

    if(entry==NULL)
    {
        printf("there no such file\n");
        return -1;
    }
    closedir(dp);

   


    return 0;
}
