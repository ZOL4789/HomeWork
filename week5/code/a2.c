#include "a.h"

void maxNum(int *arr){
	int temp = arr[0], i;
	for(i=0;i<100;i++){
		if(arr[i]>temp){
			temp = arr[i];
		}
	}
	printf("maxnum is %d\n",temp);
}
