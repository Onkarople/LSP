#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    

    fork();

    printf("hello world:%d\n",getpid());

    return 0;
}
