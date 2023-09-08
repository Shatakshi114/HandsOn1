/*
============================================================================
Name : program23.c
Author : Shatakshi Tiwari
Description : Write a program to create a Zombie state of the running program.
Date: 25th , Aug 2023
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

int main (){
    // Fork returns process id
    // in parent process
    
    int pid = fork();
    
  
    // Parent process 
    if(pid > 0){
	    

	        printf("parent goes to sleep \n");
                sleep(10);
                printf("parent wakes up \n");
    // Child process
     }
    else{
	    
	    printf("process is in zombie state\n");
    }
       
  
    return 0;
}
