#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
	struct timeval tv1,tv2;
	struct timezone tz;
	gettimeofday(&tv1,&tz);
	system("./open1");
	gettimeofday(&tv2,&tz);
	printf("time of open1: %ld\n",tv2.tv_usec-tv1.tv_usec);
	gettimeofday(&tv1,&tz);
	system("./open2");
	gettimeofday(&tv2,&tz);
	printf("time of open2: %ld\n",tv2.tv_usec-tv1.tv_usec);
	return 0;
}
