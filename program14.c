#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(int argc , char **argv)
{
	struct stat *st;
	st = (struct stat *)malloc(sizeof(struct stat));

	stat(argv[1] , st);

	if(S_ISDIR(st->st_mode))
		printf("file type is : Directory\n");
	else if(S_ISCHR(st->st_mode))
                printf("file type is : character device\n");
	else if(S_ISBLK(st->st_mode))
                printf("file type is : block device\n");
	 else if(S_ISREG(st->st_mode))
                printf("file type is : regular file\n");
	 else if(S_ISFIFO(st->st_mode))
                printf("file type is : fifo or pipe\n"); 
       	else if(S_ISLNK(st->st_mode))
                printf("file type is : symbolic link\n");
	 else if(S_ISSOCK(st->st_mode))
                printf("file type is : socket\n");
	 return 0 ;
}
