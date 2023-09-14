#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret=0;
    int PID=0;

    Ret=fork();

    if(Ret==0)   //child
    {
      printf("Child process is running \n");
      printf("child says:PID of parent process is %d\n",getppid());
      printf("child says:PID of child process is %d\n",getpid());


    }
    else     //parent
    {
       printf("parent process is running\n");
       printf("parent says:PID of child process is %d\n",Ret);
       printf("parent says:PID of parent process is %d\n",getpid());
       printf("parent says:PID of parent process of parent ie Terminal is %d\n",getppid());


    }



    return 0;
}
