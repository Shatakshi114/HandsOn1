#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main(){
	int flags , accessmode ;
	int fd = open("file1", O_RDONLY );
	flags = fcntl(fd , F_GETFL );
	if(flags == -1)
	{
		exit(0);

	}
	if(flags & O_SYNC)
		printf("writes are synchronized\n");

	accessmode = flags & O_ACCMODE;
	if(accessmode == O_RDONLY )
		printf("file is readonly ");
	else if(accessmode == O_WRONLY || accessmode == O_RDWR )
		printf("file is writable \n");
}
