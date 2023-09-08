/*
============================================================================
Name : program18_write.c
Author : Shatakshi Tiwari
Description : Write a program to perform Record locking.
              a. Implement write lock
              b. Implement read lock
              Create three records in a file. Whenever you access a particular record, first lock it               then modify/access to avoid race condition.
Date: 25th , Aug 2023
============================================================================
*/

#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>

int main() {
	struct {
		int train_num;
		int ticket_count;
	}dbs[3];
   int fd, input;
   fd = open("record.txt", O_RDWR);
   printf("Select train number: 1, 2, 3\n");
   scanf("%d", &input);

   struct flock lock;
   lock.l_type = F_WRLCK;
   lock.l_whence = SEEK_SET;
   // Record for train number 1 is stored at the beginning of the file so at offset = 0

   // For train number 2, it is stored at offset = sizeof(dbs)
   // For train number 3, it is stored at offset = 2 * sizeof(dbs)
   // And that is essentially what this next line does

   lock.l_start = (input - 1) * sizeof(dbs);
   // This actually implements record-level locking
   // We start locking from the beginning of selected train's record  upto the end of that record which will be at l_start + sizeof(db)
   lock.l_len = sizeof(dbs);
   lock.l_pid = getpid();
   // Reading value of ticket number
   lseek(fd, (input - 1) * sizeof(dbs), SEEK_SET);
   read(fd, &dbs, sizeof(dbs));
   printf("Before entering critical section\n");
   fcntl(fd, F_SETLKW, &lock);
   printf("Current ticket count: %d\n", dbs->ticket_count);
   dbs->ticket_count++;

   // Currently fd is pointing to end of current record and we have to move it to the start of current record, i.e. SEEK_CUR - sizeof(dbs)
   // Or you can just do SEEK_SET + (input - 1) * sizeof(dbs)
   lseek(fd, -1 * sizeof(dbs), SEEK_CUR);
   write(fd, &dbs, sizeof(dbs));
   printf("To book ticket, press enter\n");
   getchar();
   // First getchar() call will be bypassed by train number input on STDIN, so that's why we add another getchar() call here
   getchar();
   lock.l_type = F_UNLCK;
   fcntl(fd, F_SETLK, &lock);
   printf("Ticket booked with number %d\n", dbs->ticket_count);
}
