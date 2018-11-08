#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int f = open("ex1.txt", O_RDWR);
    if (f == -1) {
        printf("Error");
    } else {
        int length = 20;
        char output[length + 1];
        int r = read(f, output, length);
        if (r != -1) {
            printf("%s", output);

        } else {
            printf("r");

        }
    }
    close(f);
    return 0;
}
