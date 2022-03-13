#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> //열린 파일의 속성을 가져오거나 설정
#include <unistd.h>
#include <stdlib.h> //표준 라이브리
#include <stdio.h>

int main() {
    int fd;
    mode_t mode;

    mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; //sys/stat.h

    fd = open("test.txt", O_CREAT, mode); //fcntl.h
    if (fd == -1) {
        perror("Creat"); //stdio.h
        exit(1);
    }
    close(fd);
}

