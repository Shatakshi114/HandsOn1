/*
============================================================================
Name : 30.c
Author : Shatakshi Tiwari
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 8th , Sept  2023
============================================================================
*/

#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>

time_t rawtime ;
struct tm * timeinfo ;

int main(){
	int pid=fork();
	if(pid==0){
		printf("child process\n");
		printf("child pid:%d \n",getpid());
		int session_id=setsid();
		printf("session id:%d \n", session_id);
		chdir("/");
		umask(0);
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		while(timeinfo->tm_hour==20 && timeinfo->tm_min<10)
		{
			sleep(10);
			time(&rawtime);
			timeinfo=localtime(&rawtime);
		}
		if(timeinfo->tm_hour == 20 && timeinfo->tm_min==10){
			system("sh $Home/Desktop/hands_on_list1_ss/daemon.sh");
			printf("job completed successfully");
		}
	}
	else
		printf("parent process completed its execution \n ");
}

