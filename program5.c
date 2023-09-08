/*
============================================================================
Name : program5.c
Author : Shatakshi Tiwari
Description : Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.
Date: 17th , Aug 2023
============================================================================
*/



#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(void)
{
	int fd1 , fd2 , fd3 , fd4 , fd5;

	fd1 = open("file1.txt" , O_RDWR|O_CREAT);
	fd2 = open("file2.txt" , O_RDWR|O_CREAT );
        fd3 = open("file3.txt" , O_RDWR|O_CREAT );
        fd4 = open("file4.txt" , O_RDWR|O_CREAT );
        fd5 = open("file5.txt" , O_RDWR|O_CREAT );

	printf("fd1 = %d " , fd1 );
	printf("fd2 = %d " , fd2 );
        printf("fd3 = %d " , fd3 );
        printf("fd4 = %d " , fd4 );
        printf("fd5 = %d " , fd5 );

for(;;) ; 

	}



