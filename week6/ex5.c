#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int main()
{
	int pid = fork();
	if (pid < 0) {
		printf("Error while forking\n");
		return -1;
	}
	if (pid==0){
		while (1) {
			sleep(1);
			printf("I'm alive\n");
		}
	}
	sleep(10);
	kill(pid, SIGTERM);
	printf("Not anymore");
}
