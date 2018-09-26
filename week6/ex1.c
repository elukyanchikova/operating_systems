#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char *s1 = "Hello_world";
	char s2[100] = "";
	printf("s1 after initialization: %s\n", s1);
	printf("s2 we used to have initially: %s (if there was nothing, means the string was empty) \n", s2);

	int fd[2];
	int	state = pipe(fd);
	if (state) {
		printf("Error while making pipe\n");
		return -1;
	}
	write(fd[1], s1, sizeof(s2)+30);
	read(fd[0], s2, sizeof(s1)+30);

	printf("s2 after transferring from s1: %s\n", s2);
	return 0;
}