/*
============================================================================
Name : program16.c
Author : Shatakshi Tiwari
Description : Write a program to perform mandatory locking.
              a. Implement write lock

Date: 25th , Aug 2023
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main(void) 
{
	struct flock lock;
	int fd;
	fd = open("db" , O_RDWR );
	lock.l_type = F_WRLCK ;
	lock.l_whence = SEEK_SET ;
lock.l_start = 0;
lock.l_len= 0;
lock.l_pid= getpid() ;
printf("before entering into critical section \n ");
fcntl(fd , F_SETLKW , &lock );
printf("inside the critical section .. \n");
printf("enter to unlock ...\n");
getchar();
printf("unlocked \n");
lock.l_type = F_UNLCK;
fcntl(fd, F_SETLK , &lock);
printf("excited critical section \n");

}

