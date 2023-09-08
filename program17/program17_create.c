/*
============================================================================
Name : program17_create.c
Author : Shatakshi Tiwari
Description :  Write a program to simulate online ticket reservation. Implement write lock
               Write a program to open a file, store a ticket number and exit. Write a separate 
	       program, to open the file, implement write lock, read the ticket number, incremented 
	       number and print the new ticket number then close the file
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
	int fd;
	struct{
		int ticket_no;
	} database;

	printf("Enter ticket no. : ");
	scanf("%d", &database.ticket_no);
	fd=open("database", O_CREAT|O_RDWR, 0744);
	write(fd, &database, sizeof(database));
	close(fd);
	fd=open("database", O_RDONLY);
	read(fd, &database, sizeof(database));
	printf("Ticket no: %d\n", database.ticket_no);
	close(fd);
}
