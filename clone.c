#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int v,fd;
int func(){
	v = 42;
	printf("child process\n");
	close(fd);
	return 0;
}

int main(){
	void *child_stack;
	char temp;
	v = 9;
	fd = open("/test.txt",O_RDONLY);
	child_stack = (void *)malloc(16384);
	printf("The v was %d\n", v);
	clone(func,child_stack+10000,CLONE_VM|CLONE_FILES,NULL);
	sleep(3);
	printf("The v is now %d\n",v);
	if(read(fd,&temp,1)<1){
		perror("File Read Error");
		exit(1);
	}
	printf("We could read from the file\n");
	return 0;
}
