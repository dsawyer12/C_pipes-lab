#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIFO_FILE  "MYFIFO" 

int main(int argc, char *argv[]){
    FILE *fpoint;
    int again = 1;
    char strIn[80] = "Use message from command line as first message.";

    if (argc != 2){
        printf("USAGE: NamedPipeClient [string]\n");
        exit(1);
    }
    strcpy(strIn, argv[1]);
        
 while (again != 0){ 
    if((fpoint = fopen(FIFO_FILE, "w")) == NULL){
        perror("fopen");
        exit(1);
    }

    fputs(strIn, fpoint);
    fclose(fpoint);
    printf("Enter message to send: ");
    scanf("%s", strIn);
    again = strcmp(strIn, "Stop");
}
    if((fpoint = fopen(FIFO_FILE, "w")) == NULL){
        perror("fopen");
        exit(1);
    }

    fputs(strIn, fpoint);
    fclose(fpoint);

    return(0);
}













