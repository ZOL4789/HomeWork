#include "my.h"

int main(){
	int pid, s;
	if((pid = fork()) < 0){
		perror("failed to fork()!\n");
		return -1;
	}else if(pid == 0){
		printf("%d: child is running now!\n", getpid());
		printf("%d: child is exiting now!\n", getpid());
		while(1);
		exit(20);
	}else {
		printf("%d: parent is waiting zomble now!\n", getpid());
		while((pid = wait(&s)) != -1){
			printf("%d: parent is exiting now!\n", getpid());
			if(WIFEXITED(s)){
				printf("child %d is exiting normally. exit code is %d\n", pid, WEXITSTATUS(s));
			}else if(WIFSIGNALED(s)){
				printf("child %d exit by signal. signal is %d\n", pid, WTERMSIG(s));
			}else {
				printf("Not know!\n");
			}
		}
	}
}
