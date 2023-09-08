/*
============================================================================
Name : program17_lock.c
Author : Shatakshi Tiwari
Description :  Write a program to simulate online ticket reservation. Implement write lock
               Write a program to open a file, store a ticket number and exit. Write a separate 
	       program, to open the file, implement write lock, read the ticket number, increment the               number and print the new ticket number then close the file
Date: 25th , Aug 2023
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	struct{
		int ticket_no;
	}database;
	int fd;
	struct flock lock;
	fd=open("database", O_RDWR);
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=0;
	lock.l_pid=getpid();
	printf("Before entering into critical section\n");
	fcntl(fd, F_SETLKW, &lock);
	printf("Inside the critical section...\n");
	read(fd, &database, sizeof(database));
	database.ticket_no++;
	lseek(fd,0,SEEK_SET);
	write(fd, &database, sizeof(database));
	printf("Ticket no: %d\n",database.ticket_no);
	printf("Enter to unlock...\n");
	getchar();
	printf("Unlocked\n");
	lock.l_type=F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	printf("Exited Critical Section");
	
	return 0;
}
