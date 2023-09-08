/*
============================================================================
Name : program11.c
Author : Shatakshi Tiwari
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
              a. use dup
              b. use dup2
              c. use fcntl
Date: 25th , Aug 2023
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(void) {
	int fd1 , dupfd , dup2fd , newfd ;
	fd1 = open("file3.txt",O_RDWR | O_CREAT);
	dupfd = dup(fd1);
	dup2fd = dup2(fd1 , 7 );
	newfd = fcntl(fd1 , F_DUPFD , 8 );
	printf("original descriptor: %d\n",fd1);
	 printf("duplicate descriptor using dup : %d\n",dupfd);
 printf("duplicate descriptor dup2: %d\n",dup2fd);
 printf("fcntl descriptor: %d\n",newfd);
 char buf[10] , buf2[10] , buf3[10] , buf4[10] ;
 int n = sprintf(buf , "%d" , fd1 );
 write(fd1 , "original descriptor :" , 20) ;
 write(fd1 , buf , n);

 int n2 = sprintf(buf2 , "%d" , dupfd );
 write(dupfd , "\n duplicate descriptor(dup) :" , 27) ;
 write(dupfd , buf2 , n2);

int n3 = sprintf(buf3 , "%d" , dup2fd );
 write(dup2fd , "\n duplicate descriptor(dup2) :" , 29) ;
 write(dup2fd , buf3 , n3);

 int n4 = sprintf(buf4 , "%d" , newfd );
 write(newfd , "\n fcntl descriptor:" , 18) ;
 write(newfd , buf4 , n);


close(fd1);
close(dupfd);
close(dup2fd);
close(newfd);


return 0 ;
}
