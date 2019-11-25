#include "my.h"

int main(){
	pid_t r;
	int r_num;
	int pipefd[2];
	char buf[4096];
	memset(buf,0,sizeof(buf));
	if(pipe(pipefd)<0){
		perror("pipe failed!\n");
		return -1;
	}
	r = fork();
	if(r<0){
		perror("fork failed!\n");
		return -1;
	}else if(r == 0){
		close(pipefd[0]);
		int i;
		for(i =0;i<65537;i++){
			write(pipefd[1],"1",1);
			printf("%d times.\n",i);
		}
		printf("child write ok!\n");
		close(pipefd[1]);
		exit(0);
	}else {
		wait(NULL);
		close(pipefd[1]);
		int i;
		for(i = 0;i<65536;i++){
			read(pipefd[0],buf, 1);
		//	printf("parent read from pipe: %s\n", buf);
		}
		close(pipefd[0]);
		return 0;
	}
	return 0;
}
