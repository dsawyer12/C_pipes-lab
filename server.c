#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define FIFO_FILE  "MYFIFO"  
int main(void){
    FILE *fpoint;
    char readbuffer[80];
    int again = 1; 
    time_t begin, end;
    FILE *output;

    umask(0);
	mknod(FIFO_FILE, S_IFIFO|0666, 0);

    begin = time(NULL);

    while(again){
        output = fopen("output.txt", "a");
        if(output == NULL){
            perror("Error opening file 'output.txt'\n");
            exit(1);
        }
        wait(NULL);
        end = time(NULL);

        fpoint = fopen(FIFO_FILE, "r"); 
        fgets(readbuffer, 80, fpoint);  

        printf("%s", readbuffer);
        fprintf(output, "%s", readbuffer);

        printf("Time for adjustments : %ld\n", (end - begin));
        fprintf(output, "Time for adjustments : %ld\n", (end - begin));

        fclose(fpoint);
        fclose(output);
        begin = end;
        if(strcmp(readbuffer, "stop") == 0) again = 0;
    }

    return(0);
}