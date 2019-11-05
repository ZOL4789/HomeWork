#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
static jmp_buf g_stack_env;

static void fun1();
static void fun2();

int main(){
	if(setjmp(g_stack_env) == 0){
		printf("Normal flow!\n");
	}else{
		printf("Long jump flow!\n");
	}
	return 0;
}

static void fun1(){
	printf("Enter func1!\n");
	fun2();
}
static void fun2(){
	printf("Enter func2!\n");
	longjmp(g_stack_env,1);
	printf("Leave func2\n");
}
