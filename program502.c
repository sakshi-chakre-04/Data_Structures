#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd = 0;

    fd = creat("LB.txt",0777);//all permissions to all users

    printf("FD is : %d\n",fd);

    return 0;
}