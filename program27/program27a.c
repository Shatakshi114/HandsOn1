/*
============================================================================
Name : program27a.c
Author : Shatakshi Tiwari
Description : Write a program to execute ls -Rl by the following system calls
              a. execl

Date: 25th , Aug 2023
============================================================================
*/


#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(void){
	execl("/bin/ls","ls","-Rl",NULL);
	perror("Return from execl() not expected");
	exit(EXIT_FAILURE);
}
