#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> //열린 파일의 속성을 가져오거나 설정
#include <unistd.h>
#include <stdlib.h> //표준 라이브리
#include <stdio.h>
#include <errno.h>

extern int errno;

int main(int argc, char *argv[]) {
    FILE *src;
    char buf[BUFSIZ];
    ssize_t ret;

    if(argc != 2){
        perror("not enough argument");
	exit(1);
    }

    src = fopen(argv[1], "r"); //read only
    if (src == NULL) {
        perror("Open src"); //stdio.h
        exit(1);
    }

    int line =1;

    while( (fgets (buf, BUFSIZ , src)) != NULL){    
	    printf("%d %s",line++, buf);
    }
}
