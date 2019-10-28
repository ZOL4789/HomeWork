#include "ourhdr.h"

#define BUFFSIZE 8192

int main(){
	int n;
	char buf[BUFFSIZE];
	while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0){
		perror("Write error!\n");
	}

	if(n < 0){
		perror("read error!\n");
	}
	exit(0);
}
