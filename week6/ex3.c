#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void sigint()
{
	printf("signal received\n");
}

int main()
{
	signal(SIGINT, sigint);
}
