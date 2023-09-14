#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

int sum=0;

void *ThreadProc(void *ptr)
{
  int *val=(int *)ptr;
  for(int i=1;i<=2;i++)
  {
    sum=sum+val[i];
  }
  printf("%d\n",sum);
  pthread_exit(0);
   
}

int main()
{
  pthread_t tid;
  int ret=0;
  int no[2]={10,11};
  int value=0;

  ret=pthread_create(&tid,NULL,ThreadProc,(void *)no);

  if(ret!=0)
  {
    printf("Unable to create thread\n");
    return -1;
  }     

  printf("Thread is created with ID: %lu\n",tid);   
  pthread_join(tid,NULL);                                      
  printf("End of main thread\n");
  printf("return value from thread is : %d\n",sum);                                                  

  return 0;
}
