#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>

static void callback1(){
	printf("---------------callback1-----------------");
}
static void callback2(){
	printf("----------------callback2----------------");
}
static void __attribute__ ((constructor)) before_main(){
	printf("constructor\n");
}
static void __attribute__ ((destructor)) after_main(){
	printf("destructor\n");
}

int main(){
	atexit(callback1);
	atexit(callback2);
	FILE *fp;
	char buf[] = {"test date from full buffer!\n"};
	if((fp = fopen("test.dat","w+")) == NULL){
		perror("failed to open!\n");
		return -1;
	}	
	if(fputs(buf,fp) == EOF){
		perror("failed to fputs!\n");
		return -1;
	}
	printf("printf:date from line buffer\n");
	exit(0);
	//_exit(0);
}
