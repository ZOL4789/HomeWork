#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>

char a[10] = {0};
int g = 9999;

int main(){
	int s = 8888;
	static int k = 6666;
	printf("var address in proc1:\n &a = %16p\n&g = %16p\n&s = %16p\n&k = %16p\n",a, &g, &s, &k);
	for(int i = 0; i<10;i++){
		printf("proc1%d:run %d time!\n",getpid(), i);
	}
}
