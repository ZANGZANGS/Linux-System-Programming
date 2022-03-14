#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define TIMEOUT 5
#define BUF_LEN 1024

int main() {
    struct timeval tv;
    fd_set readfds;
    int ret;

    int fd;
    fd = open("test.txt", O_RDONLY| O_NONBLOCK);

    if(fd == -1){
       perror("open");
       return 1;
    }

    /*표준 입력에서 입력을 기다리기 위한 준비*/
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);
    FD_SET(fd, &readfds);

    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    /*입력 대기*/
    printf("select start!!!\n");

    ret = select (fd+1,
		    &readfds,
		    NULL,
		    NULL,
		    &tv);

    printf("ret count : %d\n",ret);

    if(ret == -1){
    	perror ("select");
	return 1;
    }else if(!ret){
    	printf("%d seconds elapsd.\n", TIMEOUT);
	return 0;
    }

    /*
     * 여기까지 오면 select가 0이 아닌 양수를 반환했다는 의미이므로
     * 파일 디스크립터에서 즉시 읽기가 가능하다.
     * */

    if(FD_ISSET(fd, &readfds)){
    	char buf[BUF_LEN+1];
	int len;

	/**/
	len = read (fd, buf, BUF_LEN);
	if(len == -1){
	
		perror("read");
		return 1;
	}

	if(len){
	
		buf[len] = '\0';
		printf ("read: %s", buf);
	}

	return 0;

    }

}
