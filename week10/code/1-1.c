#include <stdio.h>
#include <stdlib.h>

static void fun1(){
	printf("invoked callbackfun!\n");
}

int main(){
	FILE *fp;
	char buf[] = "HELLO";
	atexit(fun1);
	printf("%s",buf);
	//_exit(0);
	exit(0);
}
