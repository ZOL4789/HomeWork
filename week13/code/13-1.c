#include "my.h"

void sigroutine(int sign){
	switch(sign){
		case 1:
			printf("Get a signal SIGHUP!\n");
			break;
		case 2:
			printf("Get a signal SIGINT!\n");
			break;
		case 3:
			printf("Get a signal SIGQUIT!\n");
			break;
		default:
			break;
	}
}


int main(){
	printf("Pid is %d.\n", getpid());
	signal(SIGHUP,sigroutine);
	signal(SIGINT,sigroutine);
	signal(SIGQUIT,sigroutine);
	while(1);
	return 0;
}
