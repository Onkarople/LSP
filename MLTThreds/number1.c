#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

pthread_mutex_t lock;

void *ThreadProc1(void *ptr)
{
  
  int i= (int)ptr;
  if(i%2==0)
  {
    printf("Its Even\n");
  }
  
  pthread_exit(NULL);
   
}


void *ThreadProc2(void *ptr)
{
  
   int i= (int)ptr;
   int iCnt=0;
    
  for(iCnt=2;iCnt<=i/2;iCnt++)
  {
    if(i%iCnt==0)
    {
       break;
    }
  }
    
  if(iCnt>i/2)   //if(icnt==(ino/2)+1)
  {
    printf("Its Prime\n");
  }
  else
  {
     printf("Its not Prime\n");
  }
     
   pthread_exit(NULL); 
}


void *ThreadProc3(void *ptr)
{
  
  int i= (int)ptr;
  int iCnt=0;
  int iSum=0;
      
    if(i<0)
    {
       i=-i;
    }

    for(iCnt=i/2;((iCnt>=1) && (iSum<=i));iCnt--)
     {
        if((i%iCnt)==0)
        {
            iSum=iSum+iCnt;
        }
          
    }

    if(iSum==i)
    {
        printf("Its perfect\n");
    }

    else
    {
      printf("Its not perfect\n");
    
    }
  
  pthread_exit(NULL);
   
}


void *ThreadProc4(void *ptr)
{
  
  int i= (int)ptr;
  int iCnt=0;
  int iCount=0;
  int iSum=0;
  for(iCnt=1;iCnt<=i/2;iCnt++)
  {
    if(i%iCnt==0)
    {
      iCount++;
    }
   }
   printf("factors count is %d",iCount);
  pthread_exit(NULL);
   
}


void *ThreadProc5(void *ptr)
{

  pthread_mutex_lock(&lock);
  
  int i= (int)ptr;
  if(i%2!=0)
  {
    printf("Its Odd\n");
  }
  pthread_mutex_unlock(&lock);
  pthread_exit(NULL);
   
}

void *ThreadProc6(void *ptr)
{
  
  int i= (int)ptr;
  int iCnt=0;
  for(iCnt=1;iCnt<=i/2;iCnt++)
  {
    if(i%iCnt==0)
    {
      printf("factor are:%d\n",iCnt);
    }
  }
  
  pthread_exit(NULL);
   
}



void *ThreadProc7(void *ptr)
{
  
  int i= (int)ptr;
  int iCnt=0;
  int iSum=0;
  for(iCnt=1;iCnt<=i/2;iCnt++)
  {
    if(i%iCnt==0)
    {
      iSum=iSum+iCnt;
    }
  }
  printf("sum of Factors:%d\n",iSum);
  
  pthread_exit(NULL);
   
}

int main()
{
  pthread_t tid[7];
  int ret[7];
  char name[20];
  int No=10;

 // printf("Enter Number\n");
  //scanf("%d",&No);

  pthread_mutex_init(&lock,NULL);

  for(int i=1;i<=7;i++)
  {
     sprintf(name,"%s%d",ThreadProc,i);
     ret[i]=pthread_create(tid[i],NULL,name,(int *)No);
     if(ret[i]!=0)
     {
      printf("Unable to create thread\n");
      return -1;
     }
     pthread_join(tid[i],NULL);

  }

 
  pthread_mutex_destroy(&lock);                                  
  printf("End of main thread\n");      
  pthread_exit(NULL);                                          

  return 0;
}
