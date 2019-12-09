#include "my.h"
#define NUM 4


void * fun(void *arg){
	printf("%d thread : tid %p\n",arg, pthread_self());
	return NULL;
}


int main(){
	pthread_t tid[NUM];
	int i, ret[NUM];	//ret存放返回值
	for(i = 0; i < NUM; i++){
		ret[i] = pthread_create(&tid[i], NULL, fun, (void*)i);
		if(ret[i] != 0){
			printf("thread create failed!\n");
			return -(1+i);
		}
		pthread_join(tid[i], NULL);
	}
	return 0;
}
