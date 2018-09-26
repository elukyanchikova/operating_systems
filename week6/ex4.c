#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void siginth()
{
	printf("SIGINT signal received\n");
}

void sigstoph()
{
	printf("SIGSTOP signal received\n");
}

void sigusr1h()
{
	printf("SIGUSR1 signal received\n");
}

int main()
{
	signal(SIGINT, siginth);
	signal(SIGSTOP, sigstoph);
	signal(SIGUSR1, sigusr1h);
}
