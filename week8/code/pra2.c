#include <stdio.h>
#include <malloc.h>

int a;
static int b = 10;

int main(int argc, char *argv[], char *envp[]){
	int a = 10;	//stack
	char *p=(char *)malloc(sizeof(char));//head
	printf("a=%d p=0x%x\n",a,p);//dynammilib.so
	getchar();	//sleep is the same.
	getchar();
	return 0;
}
