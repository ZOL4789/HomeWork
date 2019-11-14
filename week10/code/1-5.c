#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>

int g = 10;

int main(){
	int s = 20;
	static int k = 30;
	int status;
	pid_t pid;
	pid = fork();
	if(pid < 0){
		perror("fork failed!\n");
		return -1;
	}else if(pid == 0){
		printf("child: pid = %d \n &g = %16p\n &k = %16p\n &s = 16%p\n",getpid(),&g,&k,&s);
		g = 100;
		s = 200;
		k = 300;
		execl("./pro1","pro1",NULL);
		printf("child after g = %d, s = %d, k = %d\n", g, k ,s);
		exit(12);
	}else {
		wait(&status);
		printf("child exit code = %d\n",WEXITSTATUS(status));
		printf("parent pid = %d \n &g = %16p\n &k = %16p\n &s = %16p\n",getpid(), &g, &k, &s);
		printf("parent after g = %d , s = %d, k = %d\n", g, s, k);
		return 0;
	}
}
