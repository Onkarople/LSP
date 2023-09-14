#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>





int main()
{
    int Ret=0;
    int cpid=0;
    int Exit_status=0;
   
    Ret=fork();

    if(Ret==0)
    {
       execl("./chilp","NULL",NULL);  
    }
      
    else
    {
        printf("Parent is running with PID : %d\n",getpid());
        cpid=wait(&Exit_status);
        printf("child process terminated having PID %d with status %d\n",cpid,Exit_status);

        
    }

    return 0;
}
