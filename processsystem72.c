#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>


void *ThreadProc1(void *ptr)
{
  int i=0;
  printf("Inside thread 1\n");
  pthread_exit(NULL);
  
}


void *ThreadProc2(void *ptr)
{
  int i=0;
  printf("Inside thread 2\n");
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

  printf("Thread1 is created with ID: %u\n",tid1);

  ret2=pthread_create(&tid2,NULL,ThreadProc2,NULL); 
  if(ret2!=0)
  {
    printf("Unable to create thread2\n");
    return -1;
  }     

  printf("Thread2 is created with ID: %u\n",tid2);   


  pthread_join(tid1,NULL);                                
  pthread_join(tid2,NULL);                                      
                                                    

  printf("End of main thread\n");                                                  

  return 0;
}
