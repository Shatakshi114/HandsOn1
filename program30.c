/*
============================================================================
Name : program30.c
Author : Shatakshi Tiwari
Description : Write a program to run a script at a specific time using a Daemon process
Date: 25th , Aug 2023
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <time.h>

int main() {
    //Desired execution time
    struct tm desired_time;
    desired_time.tm_hour = 11;  
    desired_time.tm_min = 34;    
    desired_time.tm_sec = 0;  
    desired_time.tm_mday = 8;  
    desired_time.tm_mon = 9;  
    desired_time.tm_year = 2023-1900; 
    
      
    // Calculate the time delay until the desired time
    time_t now;
    struct tm *current_time;
    
    /*localtime() :converts the calendar time timep to broken-
       down time representation, expressed relative to  the  user's  specified timezone.*/
    
    time(&now);
    current_time = localtime(&now);
    
    /*mktime():converts a broken-down time structure(tm defined in <time.h>),  expressed as  local  time, to calendar time         representation
    On success, mktime() returns  the  calendar  time  (seconds  since  the Epoch), expressed as a value of type time_t.
    On error returns -1
*/

   time_t time_delay = mktime(&desired_time) - mktime(current_time);
   
  
 
    
    if (time_delay  <= 0) {
        printf("Invalid time. Please set a future time.\n");
        return 1;
    }

    // Create a daemon process
   
    
   
    
    if (!fork()) {
     
        // Child process becomes the daemon
        setsid();  
        
        /* Create a new session :setsid runs a program in a new session. The command calls fork(2) if
       already a process group leader. Otherwise, it executes a program in the
       current process. This default behavior is possible to override by the
       --fork option.*/



        // Sleep until the desired time
        sleep(mktime(&desired_time) - mktime(current_time));
       
        
         printf("Daemon process ....\n"); 
        
          
        // Execute the script 
        execl("/Desktop/hands_on_list1_ss/daemon.sh", "daemon.sh", NULL);
        perror("execl"); 
        return 1;
    }
    else{
    sleep(10);
      printf( "Parent process exits\n");
    }
    
    return 0;
}
    

