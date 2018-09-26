#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char *s1 = "Hello_world";
	char s2[100] = "";
	printf("s1 after initialization: %s \n", s1);
	printf("s2 we used to have initially: %s (if there was nothing, means the string was empty) \n", s2);

	int fd[2];
	int	state = pipe(fd);
	if (state) {
		printf("Error while making pipe\n");
		return -1;
	}

	int f = fork();
	if (f == -1) {
		close(fd[0]);
		close(fd[1]);
		printf("Error while forking %d\n", f);
		return -1;
	}
	else if (f == 0) {
		close(fd[0]);
		write(fd[1], s1, sizeof(s1)+30);
		return 0;
	} 
		
	close(fd[1]);
	read(fd[0], s2, sizeof(s1)+30);
	
	printf("s2 after transfering from a pipe %s\n", s2);
	return 0;
}
