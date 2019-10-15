#include "uhead.h"
int urand(int n){
	int i , j;
	srand((int)time(0)); 	//get a random seed
	return rand()%(n+1);	//pruduce a random number and return 
}

int usum(int *a, int n){	//count sum of a array and return
	int i;
	int sum=0;
	for(i=0;i<n;i++){
		sum += a[i];
	}
	return sum;
}
