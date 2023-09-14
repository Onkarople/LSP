#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

//void *_______ (void *______)
//{}
void *ThreadProc(void *ptr)
{
  printf("Inside thread\n");
}

int main()
{
  pthread_t tid;
  int ret=0;

  ret=pthread_create(&tid,NULL,ThreadProc,NULL); //1.address od pthread_attr_t struture object
                                                // thread attributes
                                                //address of callback function
                                                //parameters to call back function

  if(ret!=0)
  {
    printf("Unable to create thread\n");
    return -1;
  }     

  printf("Thread is created with ID: %d\n",tid);                                         
                                                    

  return 0;
}
