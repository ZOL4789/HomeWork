#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t pid1;
	pid_t pid2;
	pid1 = fork();
	pid2 = fork();
	if(pid1 == -1){
		perror("pid1 failed!");
	}else if(pid1 == 0){
		printf("v\n");
	}else {
		printf("a\n");
	}
	if(pid2 == -1){
		perror("pid2 failed!");
	}else if(pid2 == 0){
		printf("t\n");
	}
	return 0;
}
