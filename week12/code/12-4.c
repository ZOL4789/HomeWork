#include "my.h"

void sighand(int sign);

int main(){
	int fd[2];
	if(signal(SIGPIPE,sighand) == SIG_ERR){
		fprintf(stderr,"signal error is %s\n", strerror(errno));
		exit(-1);
	}
	if(pipe(fd) == -1){
		fprintf(stderr, "create pipe failed! (%s)\n",strerror(errno));
		exit(-2);
	}
	pid_t pid;
	pid = fork();
	if(pid == -1){
		fprintf(stderr, "fork failed! (%s)\n", strerror(errno));
		exit(-3);
	}else if(pid == 0){
		fprintf(stdout, "[child] will close the last read ebd of pipe. pid = %d, ppid = %d\n", getpid(), getppid());
		sleep(3);
		close(fd[0]);
		exit(0);
	}else {
		sleep(5);
		close(fd[0]);

		int ret;
		printf("parent write\n");
		ret = write(fd[1], "hello", 5);
		if(ret == -1){
			fprintf(stderr, "parent write failed! (%s)\n", strerror(errno));
		}
		return 0;
	}
}




void sighand(int sign){
	printf("[parent] catch a SIGPIPE signal and signo is %d\n", sign);
}
