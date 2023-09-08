
/*
============================================================================
Name : program24.c
Author : Shatakshi Tiwari
Description : Write a program to create an orphan process.
Date: 25th , Aug 2023
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>


int main()
{
    // Create a child process
    int pid = fork();

    if (pid > 0)
        printf("in parent process");

    else if (pid == 0)
    {
        sleep(10);
        printf("in child process");
    }

    return 0;
}
