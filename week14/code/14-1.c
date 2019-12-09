#include "my.h"


void * threadfun(){
	printf("pid = %d :worker thread is running!\n",getpid());
}

int main(){
	pthread_t tid;
	int error;
	error = pthread_create(&tid, NULL, threadfun, NULL);
	if(error!=0){
		printf("thread create failed!\n");
		return -1;
	}
	printf("main thread is ended! pid = %d tid = %ld\n",getpid(),tid);
	pthread_join(tid, NULL);
	printf("main thread after!\n");
	return 0;
}
