#include <stdio.h>

int main(int argc, char *argv[], char *env[]){
	int i = 0;
	extern char **environ;
	for(;env[i];i++){
		printf("%s\n",env[i]);
	}
	for(i=0;environ[i];i++){
		printf("%s\n",environ[i]);
	}
	printf("%s\n", getenv("PATH"));
	return 0;
}
