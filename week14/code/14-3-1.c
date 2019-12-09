#include "my.h"
#define NUM 4
typedef struct D{
	int num;
	int tid;
	int sum;
	double ticks;	
}d;

void * fun(void *arg){
	int i;
	int sum = 0;
	clock_t start, stop;
	d *D = (d*)arg;
	start = clock();
	for(i = 1; i <= D->num;i++){
		sum += i;
	}
	D->sum = sum;
	stop = clock();
	D->ticks = (double)(stop - start)/CLOCKS_PER_SEC;
	return NULL;
}


int main(){
	pthread_t tid[NUM];
	d D[4];
	D[0].num = 100;
	D[1].num = 200;
	D[2].num = 300;
	D[3].num = 400;
	D[0].tid = 0;
	D[1].tid = 1;
	D[2].tid = 2;
	D[3].tid = 3;
	int i, ret[NUM];	//ret存放返回值
	for(i = 0; i < NUM; i++){
		ret[i] = pthread_create(&tid[i], NULL, fun,(void*)&D[i]);
		if(ret[i] != 0){
			printf("thread create failed!\n");
			return -(1+i);
		}
		pthread_join(tid[i], NULL);
	}
	for(i = 0; i < NUM; i++){
		printf("%d thread :ticks = %f, sum = %d\n", i, D[i].ticks, D[i].sum);
	}
	return 0;
}
