#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *stream;

    stream = fopen("test.txt","wb");

    if(stream == NULL){
        perror("fopen");
	exit(1);
    }

    fputc((int)'c', stream);

    fclose(stream);

}
