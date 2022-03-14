#include <stdlib.h>
#include <stdio.h>

int main() {
    FILE *rfp, *wfp;
    char buf[BUFSIZ];

    if ((rfp = fopen("linux.txt", "r")) == NULL) {
        perror("fopen: linux.txt");
        exit(1);
    }

    if ((wfp = fopen("linux.out", "a")) == NULL) { //기존 내용 끝에 추가해서 쓰기용으로 열기
        perror("fopen: linux.out");
        exit(1);
    }

    while (fgets(buf, BUFSIZ, rfp) != NULL) {
        fputs(buf, wfp);
    }

    fclose(rfp);
    fclose(wfp);
}

