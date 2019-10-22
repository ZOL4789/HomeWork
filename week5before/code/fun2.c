#include "uhead.h"

arg operator(int *a,int n){ 	//count sum and avg of array and give them to a struct "k" and  return the struct "k"
	int i,sum=0;
	arg k;
	float avg;
	for(i=0;i<n;i++){
		sum += a[i];	
	}
	k.avg = (float)sum/n;
	k.sum = sum;
	return k;
}
int* bubbleSort(int *a, int n){
	int i, j;
	int temp, *midd;
	midd = a;
	for(i=1;i<n;i++){
		for(j=0;j<n-i;j++){
			if(midd[j]<midd[j+1]){
				temp = midd[j];
				midd[j] = midd[j+1];
				midd[j+1] = temp;
			}
		}
	}
	return midd;
}
