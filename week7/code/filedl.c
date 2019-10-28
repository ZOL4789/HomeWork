#include "io.h"

int main(){
	int choice;
	while(1){
		choice = menu();
		system("clear");
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
	while(num>=0 && num <=5){
		return num;
	}
	return -1;
}

//create new file
void newFile(){
	FILE *fp;
	char name[NI];
	printf("Please input file name: ");
	scanf("%s",name);
	if(fopen(name, "r") == NULL){
		if((fp = fopen(name, "w+")) == NULL){	
			printf("create failed!\n");
			return;
		}else {
			printf("create success!\n");
		}
		fclose(fp);
	}else {
		printf("File exits!\n");
	}
}

//write file
void writeFile(){
	FILE *fp;
	int i = 0;
	char name[NI], buf[N];
	printf("Please input name of file to write: ");
	scanf("%s", name);
	if((fp = fopen(name, "r")) == NULL){
		printf("no such file!\n");
		return;
	}else {	
		fclose(fp);
		if((fp = fopen(name,"a+")) == NULL){
			printf("Open failed!\n");
			return;
		}
		getchar();
		printf("Please input something to write: ");	
		while((buf[i] = getchar()) != '\n'){
			i++;
		}
		printf("%s\n",buf);
		fwrite(buf,i, 1,fp);
		fclose(fp);
	}
}

//read file
void readFile(){
	FILE *fp;
	char buf[N]="", name[NI]="", temp;
	int i = 0;
	printf("Please input name of file to read: ");
	scanf("%s", name);
	printf("%s\n", buf);
	printf("%s\n", name);
	if((fp = fopen(name, "r")) == NULL){
		printf("no such file!\n");
		return;
	}else {	
		fclose(fp);
		if((fp = fopen(name,"r")) == NULL){
			printf("Open failed!\n");
			return;
		}
		while((temp = getc(fp)) != EOF){
			buf[i] = temp;
			i++;
		}
		fclose(fp);
	}
	printf("%s\n",buf);
	fflush(stdin);	
}

//update file's authority
void updateAuth(){
	char name[NI];
	int num;
	printf("Please input name of file to update authority: ");
	scanf("%s", name);
	if(access(name,R_OK) < 0){
		printf("no such file\n");
		return;
	}
	printf("1.read_only\n2.write_only\n3.read_write\nPlease input your choice:");
	scanf("%d", &num);
	switch(num){
		case 1:
			if(chmod(name, S_IRUSR) < 0){
				fprintf(stdin, "%s", stderr);
				return;				
			}
			break;
		case 2:
			if(chmod(name, S_IWUSR) < 0){
				fprintf(stdin, "%s",stderr);
				return;				
			}			
			break;
		case 3:
			if(chmod(name, S_IRWXU) < 0){
				fprintf(stdin, "%s", stderr);
				return;				
			}
			break;
		default:
			break;
	}
	
}

//read file's authority
void readAuth(){
	char name[NI];
	struct stat statbuf;
	char str[11];
	mode_t mode;
	printf("Please input name of file to read authority: ");
	scanf("%s", name);
	if(access(name,R_OK) < 0){
		printf("open failed!\n");
		return;
	}
	if(stat(name, &statbuf) < 0){
		fprintf(stdin, "%s", stderr);
		return;
	}
	mode = statbuf.st_mode;
	str[0]='-'; 
	if(S_ISDIR(mode)) str[0]='d';
	else if(S_ISCHR(mode)) str[0]='c';
	else if(S_ISBLK(mode)) str[0]='b';
	if(mode & S_IRUSR) str[1]='r';
	else str[1]='-';
	if(mode & S_IWUSR) str[2]='w';
	else str[2]='-';
	if(mode & S_IXUSR) str[3]='x';
	else str[3]='-';
	if(mode & S_IRGRP) str[4]='r';
	else str[4]='-';
	if(mode & S_IWGRP) str[5]='w';
	else str[5]='-';
	if(mode & S_IXGRP) str[6]='x';
	else str[6]='-';
	if(mode & S_IROTH) str[7]='r';
	else str[7]='-';
	if(mode & S_IWOTH) str[8]='w';
	else str[8]='-';
	if(mode & S_IXOTH) str[9]='x';
	else str[9]='-';
	str[10]='\0';
	printf("Mode:%s\n",str);
}
