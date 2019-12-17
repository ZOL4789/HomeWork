#include "my.h"
void *worker1(void *);
void *worker2(void *);

int c[6] = {0};
int num=0;
sem_t mutex,full;
int main(){
	int ret;
	pthread_t tid[2];
	sem_init(&mutex,0,1);
	sem_init(&full,0,0);
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
	while(1){
		sem_wait(&mutex);
		if(num%2==0){
			usleep(1000);
			c[num] = (num+1)*1;
			printf("thread 1 shell ticket: %d\n",c[num]);
			num++;
			if(num==6){
				num = 0;		
			}
			sem_post(&full);			//发送信号给post
		}else {
			sem_post(&full);
			break;
		}
	}
	return NULL;
}

void *worker2(void *arg){
	while(1){
		sem_wait(&full);
		if(num%2==1){
			usleep(1000);
			c[num] = (num+1)*1;
			printf("thread 2 shell ticket: %d\n",c[num]);
			num++;
			if(num==6){
				num=0;
			}
			sem_post(&mutex);
		}else {
			sem_post(&mutex);
			break;
		}
	}
	return NULL;
}
