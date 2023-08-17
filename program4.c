#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(void) {
int fd1 ,  fd5 ;
fd1 = open("file1",O_RDWR );
fd5 = open("file5",O_EXCL );
printf("fd1=%d",fd1);
printf("fd5=%d",fd5);
}

