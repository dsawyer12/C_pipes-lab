#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define FIFO_FILE  "MYFIFO" 

int main(int argc, char *argv[]){
    FILE *fpoint;
    int again = 1;
    char strIn1[] = "Breathing gas levels adjusted\n";
    char strIn2[] = "Lighting and temperature levels have been adjusted\n";

    while (again != 0){ 
        if((fpoint = fopen(FIFO_FILE, "w")) == NULL){
            perror("fopen");
            exit(1);
        }
        fputs(strIn1, fpoint);
        sleep(5);
        fclose(fpoint);

        if((fpoint = fopen(FIFO_FILE, "w")) == NULL){
            perror("fopen");
            exit(1);
        }

        fputs(strIn2, fpoint);
        sleep(4);
        fclose(fpoint);
    }

    if((fpoint = fopen(FIFO_FILE, "w")) == NULL){
        perror("fopen");
        exit(1);
    }
    fputs(strIn1, fpoint);
    fclose(fpoint);

    if((fpoint = fopen(FIFO_FILE, "w")) == NULL){
        perror("fopen");
        exit(1);
    }
    fputs(strIn2, fpoint);
    fclose(fpoint);

    return(0);
}













