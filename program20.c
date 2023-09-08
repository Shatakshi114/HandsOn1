/*
============================================================================
Name : program20.c
Author : Shatakshi Tiwari
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 8th , Sept 2023
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/resource.h>

int main(void){


printf("The priority of the current process is = %d\n" , getpriority(PRIO_PROCESS,getpid()));
nice(-6);
printf("The modified priority (using nice ) is = %d\n" , getpriority(PRIO_PROCESS,getpid()));

}


		
