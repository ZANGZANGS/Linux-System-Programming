#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> //열린 파일의 속성을 가져오거나 설정
#include <unistd.h>
#include <stdlib.h> //표준 라이브리
#include <stdio.h>
#include <errno.h>

extern int errno;

int main(int argc, char *argv[]) {
    int fd_src, fd_dest, len;
    char buf[255];
    mode_t mode;
    ssize_t ret;

    if(argc != 3){
        perror("not enough argument.");
	exit(1);
    }


    fd_src = open(argv[1], O_RDONLY); //read only
    if (fd_src == -1) {
        perror("Open src"); //stdio.h
        exit(1);
    }

    mode = S_IRWXU | S_IRWXG | S_IROTH; //700, 70, 4  //sys/stat.h 
    
    fd_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
    if (fd_src == -1) {
        perror("Open dest"); //stdio.h
        exit(1);
    }

    len = 255;

    while((ret = read (fd_src, buf, len)) != 0){
        if(ret == -1){
	    if (errno == EINTR) continue;
	    perror("read");
	    break;
	}

	write(fd_dest, buf, ret);
    }


}
