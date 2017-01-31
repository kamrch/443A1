#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>
#include "helper.h"


int main(int argc, char *argv[]){
    /*Check if user input correct arguments*/
    if (argc != 2){
        printf("Usage: write_line <input filename>\n");
        return -1;
    }
    char *file_name = argv[1];
    char *line;
    char current_line[MAX_CHARS_PER_LINE];

    //int records_per_block = 1;

    /*Codes for recording time*/
    struct timeb t_begin, t_end;
    long total_length = 0;

    long time_spent_ms;

    /*FILE pointers*/
    FILE *fp_read, *fp_write;



    if (!(fp_write = fopen ("records.dat" , "wb")) || !(fp_read = fopen(file_name, "rb"))) {
        printf ("Error when opening file(s).\n");
        return -1;
    }


    ftime(&t_begin);
    /*Start clock before or after allocating buffer?*/

    /*Loop for writing to file*/
    while((line=fgets (current_line, MAX_CHARS_PER_LINE, fp_read))!=NULL ) {
        fputs(line, fp_write);
        total_length += strlen(current_line);
    }

    fflush(fp_write);
    fclose(fp_write);

    ftime(&t_end);

    /* force data to disk */
    fclose(fp_read);

    time_spent_ms = (long) (1000 *(t_end.time - t_begin.time) + (t_end.millitm - t_begin.millitm));


    /* result in MB per second */
    printf ("Data rate: %.3f MBPS\n", (total_length/(float)time_spent_ms * 1000)/(1024*1024));
    
    return 0;

}
