#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
//flag = 1
struct data{
	char s[100];
	int flag;
};

void main(){
	key_t key=ftok("memory.txt",'A');
	int shmid=shmget(key, 1024, 0777 | IPC_CREAT);
	struct data * d = shmat(shmid,NULL,0);
	d->flag=0;

	while(d->flag!=1){
		printf("\nWaiting...");
		sleep(2);
	}
	printf("\nThe data sent is:");
	printf("%s",d->s);
	d->flag=-1;
	system("ipcs -m");
	shmdt(d);
}
