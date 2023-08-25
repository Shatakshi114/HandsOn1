#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
        struct {
int ticket_no ;
	}db; 
	struct flock lock ;
		int fd;

        fd = open("db" ,O_CREAT|O_RDWR );
	read(fd,&db,sizeof(db));
        lock.l_type = F_WRLCK ;
        lock.l_whence = SEEK_SET ;
lock.l_start = 0;
lock.l_len= 0;
lock.l_pid= getpid() ;
printf("before entering into critical section \n ");
fcntl(fd , F_SETLKW , &lock );
printf("current ticket no. :%d \n",db.ticket_no);
db.ticket_no ++;
lseek(fd,0L,SEEK_SET);
printf("inside cs\n");
printf("enter to unlock\n");
getchar();
lock.l_type = F_UNLCK;
printf("unlocked\n");
fcntl(fd, F_SETLK , &lock);
printf("you are done . \n");

}

