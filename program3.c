/*
============================================================================
Name : program3.c
Author : Shatakshi Tiwari
Description :  Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 17th , Aug 2023
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(void) {
	int fd = creat("myfile",S_IRUSR | S_IWUSR );
	printf("fd=%d\n",fd);
}



//s_irusr: user has read permission
//s_iwusr: user has write permission
