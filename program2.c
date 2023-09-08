/*
============================================================================
Name : program2.c
Author : Shatakshi Tiwari
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
              identify all the process related information in the corresponding proc directory.
Date: 17th , Aug 2023
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main() {

	for(;;);

	return 0;


 }

//how to run 
// ./a.out & -> returns id of the process
// ll /proc/id/fd
// proc provides access 
