#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
//#include <wait.h>
#define N 1024

int main(){
	pid_t pid1, pid2;
	FILE *fp;
	char buf[N];
	int i = 0,status;
	for(i = 0; i < 2; i++){
		status = fork();
		if(status == 0 || status == -1){
			break;
		}
	}
	if(status == -1){
		printf("fork failed!\n");
	}else if(status == 0){	
		printf("%d: \n",getpid());
		if((fp = fopen("user.dat","a")) != NULL){
			for(i = 0; i < 10; i++){
				sprintf(buf,"%d%d\n",getpid(),i);
				fwrite(buf,sizeof(char),strlen(buf),fp);
			}
			fclose(fp);
		}
	}else {
		wait(&status);
		if((fp = fopen("user.dat", "r")) != NULL){
			printf("parent: \n");
			fread(buf, sizeof(buf), 1,fp);
			printf("%s\n",buf);
			fclose(fp);
		}
	
	}
	return 0;
}
