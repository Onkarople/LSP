#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/stat.h>
#include<dirent.h>



void *ThreadProc1(void *ptr)
{
    DIR *dp =NULL;
    struct dirent *entry=NULL;
    struct stat sobj; 
    char name[256];
    int iMax=0;
    char fname[50]={"\0"};

   

    dp=opendir(".");
    if(dp==NULL)
    {
        printf("Unable to open directory");
    }
   

    while((entry=readdir(dp))!=NULL)
    {
        
         sprintf(name,"%s/%s",".",entry->d_name);
          stat(name,&sobj);
          if(S_ISREG(sobj.st_mode))
          {
           
            if(sobj.st_size>1024)
            {
                remove(name);
            }

          }
   }

  printf("files are removed of size > 1mb\n");
          
    closedir(dp);
   pthread_exit(NULL);
  
}


void *ThreadProc2(void *ptr)
{
  
    DIR *dp =NULL;
    struct dirent *entry=NULL;
    struct stat sobj; 
    char name[256];
    int iMax=0;
    char fname[50]={"\0"};

  

    dp=opendir(".");
    if(dp==NULL)
    {
        printf("Unable to open directory");
    }
   

    while((entry=readdir(dp))!=NULL)
    {
        
         sprintf(name,"%s/%s",".",entry->d_name);
          stat(name,&sobj);
          if(S_ISREG(sobj.st_mode))
          {
           
            if(sobj.st_size==0)
            {
                remove(name);
            }

          }
   }

      printf("files are removed of size < 100kb\n");
          
    closedir(dp);
    pthread_exit(NULL);
  
}
int main()
{
  pthread_t tid1,tid2;
  int ret1=0,ret2=0;

  ret1=pthread_create(&tid1,NULL,ThreadProc1,NULL); 
  if(ret1!=0)
  {
    printf("Unable to create thread\n");
    return -1;
  }     

  printf("Thread1 is created with ID: %lu\n",tid1);

  ret2=pthread_create(&tid2,NULL,ThreadProc2,NULL); 
  if(ret2!=0)
  {
    printf("Unable to create thread2\n");
    return -1;
  }     

  printf("Thread2 is created with ID: %lu\n",tid2);   


  pthread_join(tid1,NULL);                                
  pthread_join(tid2,NULL);                                      
                                                    

  printf("End of main thread\n");                                                  

  return 0;
}
