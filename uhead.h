#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int urand(int n);   //pruduce a random number
int usum(int *a, int n);	//return a sum of a array
typedef struct arg{		//a struct used return two number
	int sum;
	float avg;
}arg;
arg operator(int *,int);	//count sum and avg of array and return
int* bubbleSort(int *, int);
