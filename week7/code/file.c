#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int menu();
void newFile();
void writeFile();
void readFile();
void updateAuth();
void readAuth();
int main(){
	int choice;
	while(1){
		choice = menu();
		switch(choice){
			case 1:
				newFile();
				break;	
			case 2:
				writeFile();
				break;
			case 3:
				readFile();
				break;
			case 4:
				updateAuth();
				break;
			case 5:
				readAuth();
				break;
			case 0:
				exit(0);
			default:
				printf("no such choice\n");		
		}
	}	
	return 0;
}

int menu(){
	int num;
	printf("1.创建新文件\n");
	printf("2.写文件\n");
	printf("3.读文件\n");
	printf("4.修改文件权限\n");
	printf("5.查看当前文件的权限\n");
	printf("0.退出\n");
	printf("Please input your choice(0-6):");
	scanf("%d", &num);
	printf("%d\n",num);
	sleep(5000);
	while(num>=0 && num <=5){
		return num;
	}
	return -1;
}

//create new file
void newFile(){

}

//write file
void writeFile(){}

//read file
void readFile(){}

//update file's authority
void updateAuth(){}

//read file's authority
void readAuth(){}
