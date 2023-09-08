/*
============================================================================
Name : program18_create.c
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
         int i, fd;
         struct {
         int train_num;
         int ticket_count;
          } dbs[3];

         for (i=0; i<3; i++) {
            dbs[i].train_num = i+1;
            dbs[i].ticket_count = 0;
            }
         // Writing all 3 records to record.txt file
         fd = open("record.txt", O_RDWR);
         write(fd, dbs, sizeof(dbs));
}
