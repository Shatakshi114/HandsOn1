/*
============================================================================
Name : 1.c
Author : Shatakshi Tiwari
Description : create the following of a file using (i)shell command (ii)system call
               a. soft link(symlink system call)
	       b. hard link(link system call)
	       c. fifo (mkfifo library function or mknod system call)
Date: 17th , Aug  2023
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main() {
	//take these inputs from command
	
 int v =symlink("dest","destSL");
 if(v<0)
        {perror("failed");return 1;}

 //perror-> gives a descriptive error
 

 int f = link("dest","destHL");
 if(f<0)
        {perror("failed");return 1 ;}

 int e =mknod("destFIFO" , S_IFIFO , 0);

 if(e<0)
	 perror("failed");
	
 return 0;
}
