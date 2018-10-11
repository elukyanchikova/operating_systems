#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
	int i;
	int mem_10mb = 10 * 1024 * 1024;
	for (i = 0; i < 10; i++) {
		int* mem = malloc(mem_10mb);
		memset(mem, 0, mem_10mb);
		sleep(1);
	}
}
