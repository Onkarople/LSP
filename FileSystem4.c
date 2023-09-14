#include<stdio.h>

int main(int argc ,char *argv[])
{
    int iNo1=0,iNo2=0;
    int iAns=0;

    printf("Enter First number");
    scanf("%d",&iNo1);

    printf("Enter second number");
    scanf("%d",&iNo2);

    iAns=iNo1+iNo2;
    printf("Addition is : %d\n",iAns);

    return 0;
}