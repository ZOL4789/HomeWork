#include "a.h"
#include <stdio.h>
#include <dlfcn.h>

int main(){
	int arr[100];
	void  * handle;
	void (*f1)();
	void (*f2)();
	char *error;
	handle = dlopen("./libaa.so",RTLD_LAZY);
	if(!handle){
		perror("load failed!\n");
		exit(1);
	}
	f1=dlsym(handle, "randNum");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",error);
	}
	f2=dlsym(handle,"maxNum");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",error);
		exit(1);
	}
	f1(arr);
	f2(arr);
	return 0;
}
