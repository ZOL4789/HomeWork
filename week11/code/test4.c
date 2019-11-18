#include "my.h"

void pr_exit(int s, pid_t pid){
	int sig;
	if(WIFEXITED(s)){
		printf("process %d normal interminationg, exit status=%d\n", pid, WEXITSTATUS(s));
	}else if(WIFSIGNALED(s)){
		sig = WTERMSIG(s);
		printf("process %d normal termination, signal number=%d\n", pid, sig,
		#ifdef WCOREDUMP
			WCOREDUMP(s) ? "core file generated" : "");
		#else 
			"");
		#endif
			psignal(sig, "");
	}else if(WIFSTOPPED(s)){
		sig = WSTOPSIG(s);
		printf("process %d stopped, signal number = %d\n", pid, sig);
		psignal(sig, "");
	}
}

int zero = 0;

int main(){
	int pid, s;
	if((pid = fork()) == 0){
		exit(0);
		abort();
		s = s/zero;
		exit(0);	
	}
	while((pid = wait(&s)) < 0){
		pr_exit(s, pid);
	}	

	perror("wait over!");
	exit(0);
}
