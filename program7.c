#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc , char  *argv[])
{
       if(argc !=3)
       {
       printf("useful");
       }
     return 0 ;

       int fd_read = open(argv[1] , O_RDONLY);
       int fd_write =  open(argv[2] , O_WRONLY|O_CREAT);
       if(fd_read == -1 || fd_write ==-1 ) 
{
	       printf("use use ful ful ");
}

while(1)
{
	char buf;
	int char_read = read(fd_read , &buf, 1 );
	if(char_read == 0)
		break ; 
	int char_write = write(fd_write ,&buf , 1 );
}

int fd_read_close = close(fd_read);
int fd_write_close = close(fd_write);

if(fd_read_close == -1 || fd_write_close == -1 )

{
	printf("total use ");
}
return 0 ;
}
