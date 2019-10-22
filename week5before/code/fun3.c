#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int i;
	printf("---------------1.Before calling-------------\n");
	sleep(3);
	i = system("./main");
	printf("---------------1.After calling-------------\n");
 	printf("1.return value = %d\n", i);
	printf("---------------2.Before calling-------------\n");
	sleep(3);
	i = system("./main");
	printf("---------------2.After calling-------------\n");
	printf("2.return value = %d\n", i);
	return 0;

}
