#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int x = 100;

int main(int argc, char *argv[], char *engv[]){
	int y = 0;
	static int w = 33;
	printf("test1:pid=%d, ppid=%d\n",getpid(),getppid());
	for(y=0;y<argc;y++){
		printf("%s\n",engv[y]);
	}
	printf("test1.address x=%ld, y=%ld, w=%ld\n",&x, &y, &w);
	sleep(100);
	return 0;
}
