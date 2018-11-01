#include <stdio.h>
#include <stdlib.h>

int main()
{
    //put a letter in the buffer, then sleep for a sec, 5 times. Output when meet  '\n'. 
    //It seems like the process wait 5 sec and then print out everything at once 
	printf("H");
	sleep(1);
	printf("e");
	sleep(1);
    printf("l");
    sleep(1);
    printf("l");
    sleep(1);
    printf("o");
    sleep(1);
    printf("\n");
	return 0;
}