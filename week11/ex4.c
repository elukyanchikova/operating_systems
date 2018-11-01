#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {

	int file_from = open("ex1.txt", O_RDWR);
	int file_to = open("ex1.memcpy.txt", O_RDWR);
	
	struct stat status;
	stat(file_from, &status);
	
	int size = status.st_size;
	// choose a segment in the file with permissions
	char *from = mmap(0, size, PROT_READ| PROT_WRITE | PROT_EXEC, MAP_SHARED, file_from, 0);
	//cut the size of file to not to have extra symbolsa or spaces
  ftruncate(file_to, size);
  // choose a segment in the file with permissions

  char *to = mmap(0, size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_SHARED, file_to, 0);
  memcpy(to, from, size);

	close(file_from);
	close(file_to);
	
	return 0;
  }
