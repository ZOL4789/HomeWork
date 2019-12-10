#include "my.h"
int i = 0;
void * fun(void *arg){
	printf("tid = %p\n", (unsigned int)pthread_self());
	i = 99;
	printf("&i = %p, i = %d\n", &i, i);
}

int main(){
	pthread_t tid;
	int ret;
	ret = pthread_create(&tid, NULL, fun, NULL);
	if(ret != 0){
		perror("failed!\n");
		return -1;
	}
	pthread_join(tid, NULL);
	printf("rv = %d\n", i);
	return 0;
}
