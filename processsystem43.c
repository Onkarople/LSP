#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int PID=0;
    PID=getpid();
    printf("PID od Running process is : %d\n",PID);
    for(;;)
    {}

    return 0;
}
