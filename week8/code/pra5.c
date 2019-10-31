#include <stdio.h>

int sub(int a, int b, int c){
	*(int *)a = 16;
	return 0;
}


int main(){
	int a = 0;
	int b = 1;
	int c = 2;
	sub(a, b, c);
	return 0;
}
