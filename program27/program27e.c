/*
============================================================================
Name : program27e.c
Author : Shatakshi Tiwari
Description : Write a program to execute ls -Rl by the following system calls
              e. execvp
Date: 25th , Aug 2023
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	char *command = "ls";
	char *args[] = {"ls", "-Rl", NULL};
	execvp(command,args);
	perror("execvp() : ");
	exit(EXIT_FAILURE);
}
