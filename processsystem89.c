#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>


int main()
{
    char Filename1[30],Filename2[30];
    int Ret=0;

    printf("Enter the existing file name:\n");
    scanf("%s",Filename1);

    
    printf("Enter the name of hardlink:\n");
    scanf("%s",Filename2);


    Ret=link(Filename1,Filename2);


    if(Ret==0)
    {
        printf("Hardlink created succesfully...!");
    }


    return 0;
}