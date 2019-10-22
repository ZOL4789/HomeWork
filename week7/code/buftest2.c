 #include <stdio.h>
     #include <sys/types.h>
     #include <unistd.h>
#include <stdlib.h>
     int global = 4;
     
     int main(){
             pid_t pid;
             int vari = 5;
             printf("before fork\n");
           if((pid = fork()) < 0){
  		   printf("fork error!\n");
                   exit(0);
            }else if(pid == 0){
                    global++;
                    vari--;
                    printf("Child changed \n");
                    printf("child: global = %d, varu = %d\n", global, vari);
            }else {
                    printf("Parent pid not changed!\n");
                    printf("Parent: global = %d, vari = %d\n", global, vari);
          }
           return 0; 
    }

