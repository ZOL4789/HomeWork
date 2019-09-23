#include "uhead.h"
int main(){
	int i;
	int a[3] = {1,2,3},*midd; 	//define a array "a" and give it three members "1,2,3"
	arg k = operator(a, 3);		//pruduce a struct "k" and use the return value of the function "operator" to initialize it
	printf("%d\n", urand(10));	//print the result of function "urand(10)"
	printf("%d\n", usum(a,3));	//print the result of function "usum(a,3)"
	printf("sum:%d, avg:%f\n",k.sum, k.avg);	//print the sum and avg of the struct "k" 
	midd = bubbleSort(a,3);
	for(i=0;i<3;i++){
		printf("%d\n", midd[i]);
	}
	return 0;
}
