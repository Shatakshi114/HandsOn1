/*
============================================================================
Name : program10.c
Author : Shatakshi Tiwari
Description : Write a program to open a file with read write mode, write 10 bytes, move the file 
              pointer by 10 bytes (use lseek) and write again 10 bytes.
              a. check the return value of lseek
              b. open the file with od and check the empty spaces in between the data.
Date: 25th , Aug 2023
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd ;
	fd=open("file10", O_CREAT | O_RDWR , 0744);
	write(fd , "HELLOHIhey" , 10 );
	lseek(fd , 10L , SEEK_CUR );
	write(fd , "HELLOHELLO" , 10);
	close(fd);
}
