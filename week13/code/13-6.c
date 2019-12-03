#include "my.h"

volatile int global = 0;
void alarmhandler(int signo){
	global =1;
	puts("catch alarm!\n");
}


int main(int argc, char *argv[]){
	clock_t start,stop;
	struct tms buffer;
	signal(SIGALRM,alarmhandler);
	start = time(&buffer);
	alarm(1);
	while(!global);
	stop = time(&buffer);
	printf("%ld clock ticks per second (start = %ld, stop = %ld)\n", stop - start, start,stop);
printf("sysconf(_SC_CLK_TCK) = %ld\n",sysconf(_SC_CLK_TCK));
	return 0;
}
