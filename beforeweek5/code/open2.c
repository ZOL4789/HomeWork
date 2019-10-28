#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <error.h>

int main(){
	FILE *fp1,*fp2;
	char buf;
	if((fp1 = fopen("1.txt","r")) == NULL){
		perror("Open failed!\n");
		exit(1);	
	}
	if((fp2 = fopen("2.txt","a+")) == NULL){
		perror("Open failed!\n");
		exit(1);
	}
	while((buf = fgetc(fp1)) != EOF){
		fputc(buf,fp2);
	}
	fclose(fp1);
	fclose(fp2);
	printf("Copy finished!\n");
	return 0;
}

