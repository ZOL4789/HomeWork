#include "my.h"
void *worker1(void *);
void *worker2(void *);

int c =100;
pthread_mutex_t mutex;
int main(){
	int ret;
	pthread_t tid[2];
	pthread_mutex_init(&mutex,NULL);
	ret = pthread_create(&tid[0],NULL,worker1,NULL);
	if(ret != 0){
		perror("thread1 failed!\n");
		exit(0);
	}
	ret = pthread_create(&tid[1],NULL,worker2,NULL);
	if(ret != 0){
		perror("thread2 failed!\n");
		exit(1);
	}
	for(int i = 0;i<2;i++){
		pthread_join(tid[i],NULL);
	}
	return 0;
}

void *worker1(void *arg){
	int ret;
	while(1){
		pthread_mutex_lock(&mutex);
		if(c>0){
			usleep(1000);
			printf("thread 1 shell ticket: %d\n",c--);
			pthread_mutex_unlock(&mutex);
		}else {
			pthread_mutex_unlock(&mutex);
			break;
		}
		ret = pthread_yield();
	}
	return NULL;
}

void *worker2(void *arg){
	int ret;
	while(1){
		pthread_mutex_lock(&mutex);
		if(c>0){
			usleep(1000);
			printf("thread 2 shell ticket: %d\n",c--);
			pthread_mutex_unlock(&mutex);
		}else {
			pthread_mutex_unlock(&mutex);
			break;
		}
		ret = pthread_yield();
	}
	return NULL;
}
