#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	int i=0;
	pid_t pid1;
	pid_t pid2;
	pid1 = fork();
	pid2 = fork();
	if(pid1 == -1){
		perror("pid1 failed!");
	}else if(pid1 == 0){
		for(i=0; i< 3;i++){
			printf("----son-----\n");
		}
	}else {
		for(i = 0; i < 3;i++){
		printf("------parent------\n");
		}
	}
	if(pid2 == -1){
		perror("pid2 failed!");
	}else if(pid2 == 0){
		for(i = 0; i < 3; i++){
		printf("-----daughter-----\n");
		}
	}
	return 0;
}

