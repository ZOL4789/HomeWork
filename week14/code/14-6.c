#include "my.h"

#define NUM_THREADS 8

void * PrintHello(void *threadid){
	int *id_ptr, taskid;
	sleep(1);
	id_ptr = (int *) threadid;
	taskid = *id_ptr;
	printf("Hello from thread %d\n", taskid);
	pthread_exit(NULL);
}

int main(){
	pthread_t threads[NUM_THREADS];
	int rc, t;
	for(t = 0; t < NUM_THREADS;t++){
		printf("Creating thread %d\n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello, (void *)&t);
		if(rc){
			perror("creat failed!\n");
			return -(t+1);
		}
	}
	pthread_exit(NULL);
	return 0;
}
