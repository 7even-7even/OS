#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

void main(int argc, char * argv[]){

	char * arr[argc];
	char * temp;
	int i,j,n,status;
	
	pid_t pid;
	pid=fork();
	
	for(i=1;i<argc;i++){
		arr[i-1]=argv[i];
	}
	
	n=argc-1;
	
	for(i=1;i<n;i++){
		for(j=0;j<n-i;j++){
			if(atoi(arr[j])>atoi(arr[j+1])){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	arr[argc]=NULL;
	
	if(pid == 0){
		execv(arr[0],arr);
	}
	else{
		wait(&status);
		printf("\nParent Id: %d",getpid());
	}
}
