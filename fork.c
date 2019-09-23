#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(){
	int i;
	if(fork()==0){//子进程程序
		for(i=1;i<4;i++){
			printf("This is child %d process.\n",i);
		}
	}else {//父进程程序
		for(i=1;i<4;i++){
			printf("This is parent %d process\n",i);
		}
	}
}
