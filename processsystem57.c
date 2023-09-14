#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    printf("Inside child process-PID of child process is %d\n",getpid());


    return 0;
}
