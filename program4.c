/*
============================================================================
Name : program4.c
Author : Shatakshi Tiwari
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 17th , Aug 2023
============================================================================
*/






#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(void) {
int fd1 ,  fd5 ;
fd1 = open("file1",O_RDWR|O_CREAT|O_EXCL );
fd5 = open("file5",O_CREAT|O_EXCL|O_RDWR );
printf("fd1=%d",fd1);
printf("fd5=%d",fd5);
}












//o_excl :: if file with thge same name already exists then execlusive flag return -1
