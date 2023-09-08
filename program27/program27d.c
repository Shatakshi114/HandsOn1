/*
============================================================================
Name : program27d.c
Author : Shatakshi Tiwari
Description : Write a program to execute ls -Rl by the following system calls
              d. execv
Date: 25th , Aug 2023
============================================================================
*/



#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	char *command = "/bin/ls";
	char *args[] = { "ls", "-Rl", NULL };
	execv(command, args);
	perror("execv() not executed: ");
	exit(EXIT_FAILURE);
}
