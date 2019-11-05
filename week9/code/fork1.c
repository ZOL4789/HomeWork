#include <stdio.h>
#include <stdlib.h>

int gg = 9;

int main(){
	int i, pid;
	static int f = 19;
	pid = fork();
	if(pid < 0){
		perror("fork failed!\n");
		exit(1);
	}
	else if(pid == 0){
		printf("child: pid = %d, ppid = %d\n",getpid(), getppid());
		i = 100;
		gg = 101;
		f = 238;
		printf("child: i = %d, g = %d, f = %d\n",i,gg,f);
		exit(123);
	}
	sleep(10);
	printf("parent: pid = %d, ppis=%d\n",getpid(), getppid());
	printf("parent: i = %d, g = %d, f = %d\n",i,gg,f);
	return 0;
}
