#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> //파일 관련
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int fd;

    fd = open("test.txt", O_CREAT | O_EXCL, 0644); //ReadWrite Raed Read
    if (fd == -1) {
        perror("Excl");
        exit(1);
    }

    printf("test.txt: fd = %d\n", fd);
    close(fd);
}

