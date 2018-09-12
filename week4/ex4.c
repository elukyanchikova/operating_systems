//#include <sys/types.h>
//#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {

    char cmd_set[50];

    int i=0;
    while (i==0) {
        printf("> $"); // the beginning of a line in  cmd_prompt ui
        fgets(cmd_set, sizeof(cmd_set), stdin) // reading the input cmd
        system(cmd_set); // passing the string to terminal, getting the res into the console
    }
    return 0;
}

