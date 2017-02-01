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

    FILE *fp_write;

    if (!(fp_write = fopen (file_name, "rb+"))){
        return -1;
    }
        
    /* Allocate buffer for 1 record */
    Record * buffer = (Record *) calloc (1, sizeof(Record));
    buffer[0].uid1 = 1;
    buffer[0].uid2 = 2;
        
    /* Use fssek to find the file size */
    fseek(fp_write, 0, SEEK_END);
    int file_size = ftell(fp_write);
    /* Seek back to the beginning of input file */
    fseek(fp_write, 0, SEEK_SET);
    int total_records = file_size / sizeof(Record);
    
    /* Variables for recording time */
    struct timeb t_begin, t_end;
    long time_spent_ms;
    int i = 0;

    ftime(&t_begin);
    while (i < random_num){
        int rn = rand() % total_records;
        fseek(fp_write, rn * sizeof(Record), SEEK_SET);
        fwrite(buffer, sizeof(Record), 1, fp_write);
        i++;
    }
    fclose(fp_write);
    free(buffer);
    ftime(&t_end);

    time_spent_ms = (long) (1000 *(t_end.time - t_begin.time) + (t_end.millitm - t_begin.millitm));

    /* result in MB per second */
    printf ("Data rate: %.3f MBPS\n", ((total_records*sizeof(Record))/(float)time_spent_ms * 1000)/(1024*1024));
 
    return 0;
}
