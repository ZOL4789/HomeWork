#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>


void foo(){
	fprintf(stderr,"foo says bye!\n");
	
}

void bar(){
	fprintf(stderr, "barbar!\n");
}

int main(int argc, char *argv[]){
	atexit(foo);
	atexit(bar);
	pid_t pid;
	pid = fork();
	if(pid == -1){
		perror("Failed!");
		exit(0);
	}else if(pid == 0){
		printf("_exit\\n\n");
		printf("_exit!");
		_exit(0);
	}else {
		printf("exit\\n\n");
		printf("exit!");
		exit(0);
	}
}
