#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(void) {
	int fd = creat("myfile",S_IRUSR | S_IWUSR );
	printf("fd=%d\n",fd);
}
	
