#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(void)
{
	int fd1 , fd2 , fd3 , fd4 , fd5;

	fd1 = open("file1" , O_RDWR );
	fd2 = open("file2" , O_RDWR );
        fd3 = open("file3" , O_RDWR );
        fd4 = open("file4" , O_RDWR );
        fd5 = open("file5" , O_RDWR );

	printf("fd1 = %d " , fd1 );
	printf("fd2 = %d " , fd2 );
        printf("fd3 = %d " , fd3 );
        printf("fd4 = %d " , fd4 );
        printf("fd5 = %d " , fd5 );
	
	}



