/*
============================================================================
Name : program21.c
Author : Shatakshi Tiwari
Description : Write a program, call fork and print the parent and child process id.
Date: 8th , Sept 2023
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/resource.h>

int main(){
if(!fork()){
	printf("child process id : %d \n" , getpid());
}
else{
	printf("parents process id : %d \n", getpid());
			}
}
