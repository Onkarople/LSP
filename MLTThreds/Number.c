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
  pthread_t tid1,tid2,tid3,tid4,tid5,tid6,tid7;
  int ret1=0,ret2=0,ret3=0,ret4=0,ret5=0,ret6=0,ret7=0;
  int No=10;

 // printf("Enter Number\n");
  //scanf("%d",&No);

  pthread_mutex_init(&lock,NULL);

  ret1=pthread_create(&tid1,NULL,ThreadProc1,(int *)No);

  if(ret1!=0)
  {
    printf("Unable to create thread1\n");
    return -1;
  }     



  ret2=pthread_create(&tid2,NULL,ThreadProc2,(int *)No);

  if(ret2!=0)
  {
    printf("Unable to create thread\n");
    return -1;
  }     

  
  ret3=pthread_create(&tid3,NULL,ThreadProc3,(int *)No);

  if(ret3!=0)
  {
    printf("Unable to create thread\n");
    return -1;
  }     

  ret4=pthread_create(&tid4,NULL,ThreadProc4,(int *)No);

  if(ret4!=0)
  {
    printf("Unable to create thread\n");
    return -1;
  }     

  ret5=pthread_create(&tid5,NULL,ThreadProc5,(int *)No);

  if(ret5!=0)
  {
    printf("Unable to create thread\n");
    return -1;
  }     

  ret6=pthread_create(&tid6,NULL,ThreadProc6,(int *)No);

  if(ret6!=0)
  {
    printf("Unable to create thread\n");
    return -1;
  }     

  ret7=pthread_create(&tid7,NULL,ThreadProc7,(int *)No);

  if(ret7!=0)
  {
    printf("Unable to create thread\n");
    return -1;
  }     

  pthread_join(tid1,NULL);  
  pthread_join(tid2,NULL); 
  pthread_join(tid3,NULL);  
  pthread_join(tid4,NULL); 
  pthread_join(tid5,NULL);  
  pthread_join(tid6,NULL);       
  pthread_join(tid7,NULL);        
  pthread_mutex_destroy(&lock);                                  
  printf("End of main thread\n");                                                

  return 0;
}
