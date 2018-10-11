#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{
	int i;
	int mem_10mb = 10 * 1024 * 1024;
	for (i = 0; i < 10; i++) {
		int* mem = malloc(mem_10mb);
		memset(mem, 0, mem_10mb);
		
		struct rusage usage;
		
		int error = getrusage(RUSAGE_SELF, &usage);
		printf("Time %d : \n", i);
		if (error) {
			printf("Error");
		} else {
			printf("maxrss   = %ld\n", usage.ru_maxrss);
			printf("ixrss    = %ld\n", usage.ru_ixrss);
			printf("idrss    = %ld\n", usage.ru_idrss);
			printf("isrss    = %ld\n", usage.ru_isrss);
			printf("minflt   = %ld\n", usage.ru_minflt);
			printf("majflt   = %ld\n", usage.ru_majflt);
			printf("nswap    = %ld\n", usage.ru_nswap);
			printf("inblock  = %ld\n", usage.ru_inblock);
			printf("oublock  = %ld\n", usage.ru_oublock);
			printf("msgsnd   = %ld\n", usage.ru_msgsnd);
			printf("msgrcv   = %ld\n", usage.ru_msgrcv);
			printf("nsignals = %ld\n", usage.ru_nsignals);
			printf("nvcsw    = %ld\n", usage.ru_nvcsw);
			printf("nivcsw   = %ld\n", usage.ru_nivcsw);	
		}
		sleep(1);
	}
}
