#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main(int argc , char *argv[])
{
	char buffer[200] ;
	int fd =open(argv[1] , O_RDONLY );
	int read_bytes;
	char *newline ;

	if(fd==-1)
	{
		printf("error opening file \n");
	}
	read_bytes = read(fd,buffer, 200 );
	if(read_bytes>0)
	{
		char *start=buffer ;
		 while((newline=strchr(start , '\n' )) != NULL)
		 {
			 *newline = '\0' ;
			 write(STDOUT_FILENO , start , strlen(start));
			 write(STDOUT_FILENO , "\n" , 1);
			 start = newline+1;
		 }}
	close(fd);
	return 0 ;
}

