#include "a.h"

void randNum(int *arr){
	int i;
	srand((int)time(0));
	for(i=0;i<100;i++){
		arr[i] = rand()%100+1;
		printf("%d \t", arr[i]);
		if((i+1)%10 == 0){
			printf("\n");
//#include you are so fool;
		}
	}
}
