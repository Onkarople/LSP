#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>



int main(int argc,char *argv[])
{
    int fd=0;
    char buff=" ";

    if(argc != 2)
	{
		printf("Error: Not sufficient arguments\n");
		return -1;
	}

    fd=open(argv[1],O_WRONLY);
    if(fd==-1)
    {
        printf("unable to open file\n");
    }

    
    lseek(fd,1024,SEEK_CUR);

    write(fd,buff,1);

    close(fd);




    return 0;
}