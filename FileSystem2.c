#include<stdio.h>

int main(int argc, char *argv[])
{
  if(argc==1)
  {
    printf("Please enter your first name as command line arguments");
    return -1;
  }
  else
  {
    printf("Welcome to marvellous : %s\n",argv[1]);
    return 0;
  }
  
}
