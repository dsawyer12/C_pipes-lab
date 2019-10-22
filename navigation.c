#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO_FILE  "MYFIFO" 
#define MAXLEN 256

int main(int argc, char *argv[]){
    FILE *fpoint;
    int again = 1;
    char strIn[] = "Navigation system adjusted\n";

    while (again != 0){ 
        if((fpoint = fopen(FIFO_FILE, "a")) == NULL){
            perror("fopen");
            exit(1);
        }
        begin = time(NULL);
        fputs(strIn, fpoint);
        sleep(5);
        end = time(NULL);
        fclose(fpoint);
    }
    if((fpoint = fopen(FIFO_FILE, "a")) == NULL){
        perror("fopen");
        exit(1);
    }
    fputs(strIn, fpoint);
    fclose(fpoint);

    return(0);
}




