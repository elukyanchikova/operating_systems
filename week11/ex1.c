#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{

	int file = open("ex1.txt", O_RDWR);
	char *str = "This is a nice day!)";
	int file_length = strlen(str);
	// choose a segment in the file with permissions(we will put here our new string)
	char *new = mmap(0, file_length, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);
	strcpy(new, str);
	close(file);
	return 0;

    
}