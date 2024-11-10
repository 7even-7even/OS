#include <stdio.h>
#include <stdlib.h>

#include <sys/ipc.h>
#include <sys/shm.h>

struct data{
	char s[100];
	int flag;
};

void main(){
	key_t key=ftok("memory.txt",'A');
	
	int shmid=shmget(key, 1024, 0777 | IPC_CREAT);
	
	struct data * d = shmat(shmid,NULL,0);// id -- starting pointer --- flag
	
	d->flag=0;
	
	printf("\nEnter the data to be sent: ");
	gets(d->s);
	
	d->flag=1;
	
	while(d->flag!=-1){
		printf("\nWaiting...");
		sleep(2);
	}
	system("ipcs -m");
	shmdt(d);
	shmctl(shmid,IPC_RMID,NULL);
	system("ipcs -m");
}
