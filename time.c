#include <sys/time.h>
#include <unistd.h>

int main(){
	struct timeval tv1, tv2;
	struct timezone tz;
	gettimeofday(&tv1,&tz);
	printf("tv_sec: %d\n",tv1.tv_sec);
	printf("tv_usec: %d\n",tv1.tv_usec);
	printf("tz_minuteswest: %d\n",tz.tz_minuteswest);
	printf("tz_dsstime: %d\n",tz.tz_dsttime);
	gettimeofday(&tv2,&tz);
	printf("tv2_usec-tv1_usec: %d\n",tv2.tv_usec-tv1.tv_usec);
	return 0;
	
}
