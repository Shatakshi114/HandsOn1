#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>

int main(int argc , char *argv[])
{
 struct stat s ;
 if(argc!=2){
	 return 0 ;
 }
 int fd_read = open(argv[1] , O_RDONLY);
 stat( argv[1] , &s);
 printf("a. inode number : %ld\n", s.st_ino);
 printf("b. no. of hard links : %lu\n", s.st_nlink);
 printf("c. UID : %d\n", s.st_uid);
 printf("d. GID : %d\n", s.st_gid);
 printf("e. size : %ld\n", s.st_size);
 printf("f. block size  : %ld\n", s.st_blksize);
 printf("g. no. of blocks : %ld\n", s.st_blocks);
 printf("h. time of last access : %s", ctime(&s.st_atime));
 printf("i. time of last modification  : %s", ctime(&s.st_mtime));
printf("j. time of last change  : %s", ctime(&s.st_ctime));

 


}

