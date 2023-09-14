#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>





int main()
{
    int Ret=0;
   
    Ret=fork();

    if(Ret==0)
    {
       execl("./chilp","Demo","Hello","Marvellous",NULL);  
       //parameter 1: Name of ecutable
       // parameter 2 : Multiple values separetd by, which are considerd as command line arguments
       // argv[0] : demo
       //argv[1]:hello
       //argv[2]:marvellos
       // parameterb3:  environment variable (NULL)
    }
    else
    {
        printf("Parent is running with PID : %d\n",getpid());
    }

    return 0;
}
