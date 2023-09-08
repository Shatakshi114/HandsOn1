/*
============================================================================
Name : program18_read.c
Author : Shatakshi Tiwari
Description : Write a program to perform Record locking.
              a. Implement write lock
              b. Implement read lock
              Create three records in a file. Whenever you access a particular record, first lock it               then modify/access to avoid race condition.
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
	int fd, input;
	struct
	{
		int train_num;
		int ticket_count;
	}t[3];
	fd=open("file18.txt",O_RDWR);
	printf("Select train number (1,2,3) : \n");
	scanf("%d", &input);
	struct flock lock;
	lock.l_type=F_RDLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=(input-1)*sizeof(t);
	lock.l_len=sizeof(t);
	lock.l_pid=getpid();
	lseek(fd, (input-1)*sizeof(t), SEEK_SET);
	read(fd, &t, sizeof(t));
	printf("Before entering critical section\n");
	fcntl(fd, F_SETLKW, &lock);
	printf("Current ticket count : %d", t->ticket_count);
	t->ticket_count;
	lseek(fd, (input-1)*sizeof(t), SEEK_CUR);
	printf("\nPress ENTER to EXIT critical section\n");
	getchar();
	getchar();
	lock.l_type=F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	printf("Unlocked and out of critical section");
	return 0;
}
