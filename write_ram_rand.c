#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>
#include "helper.h"

int main(int argc, char *argv[]){
    /*Check if user inputs correct arguments*/
    if (argc != 3){
        printf("Usage: write_blocks_rand <input filename> <random number>\n");
        return -1;
    }

    char *file_name = argv[1];
    int random_num = atoi(argv[2]);

    FILE *fp_read;

    if (!(fp_read = fopen (file_name, "rb+"))){
        return -1;
    }       

    /* Use fssek to find the file size */
    fseek(fp_read, 0, SEEK_END);
    int file_size = ftell(fp_read);
    /* Seek back to the beginning of input file */
    fseek(fp_read, 0, SEEK_SET);
    int total_records = file_size / sizeof(Record);
    
    /* Variables for recording time */
    struct timeb t_begin, t_end;
    long time_spent_ms;
    int i = 0;

    /* Allocate buffer for the input file */
    Record * buffer = (Record *) calloc (total_records, sizeof(Record));
    int result = fread(buffer, sizeof(Record), total_records, fp_read);

    ftime(&t_begin);
    if (result != total_records){
        return -1;
    }
    else {
        while (i < random_num){
            int rn = rand() % total_records;   
            buffer[rn].uid1 = 1;
            buffer[rn].uid2 = 2;
            i++;
        }
    }
    fclose(fp_read);
    free(buffer);
    ftime(&t_end);

    time_spent_ms = (long) (1000 *(t_end.time - t_begin.time) + (t_end.millitm - t_begin.millitm));

    /* result in MB per second */
    printf ("Data rate: %.3f MBPS\n", ((total_records*sizeof(Record))/(float)time_spent_ms * 1000)/(1024*1024));
 
    return 0;
}
