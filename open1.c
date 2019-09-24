#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	char *dsrc = "1.txt",buf[100]={0},*des = "2.txt";
	int flag1= 2,flag2 = 2,fddes,nbytes,z, fdsrc;
	fddes = open(des, flag1, 0644);
	fdsrc = open(dsrc, flag2, 0644);
	if(fddes < 0){
		exit(1);
	}
	nbytes = 1;
	while(nbytes>0){
		nbytes = read(fdsrc, buf, 20);
		z = write(fddes,buf,nbytes);
		if(z<0){
			perror("Write error!\n");
		}
	}
	close(fdsrc);
	close(fddes);
	printf("Copy finished!\n");
	exit(0);
}

