#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>
#include "helper.h"

int main(int argc, char *argv[]){
    /*Check if user input correct arguments*/
    if (argc != 3){
        printf("Usage: read_block_seq <input file name> <block size>\n");
        return -1;
    }

    char *file_name = argv[1];
    int block_size = atoi(argv[2]);

    /* Validate block size*/
    if (block_size % sizeof(Record) != 0){
        printf("Block size must be a multiple of size of a record");
        return -1;
    }

    int records_per_block = block_size / sizeof(Record);
    FILE *fp_read;

        
    /* Allocate buffer for 1 block */
    Record * buffer = (Record *) calloc (records_per_block, sizeof(Record));
    
    if (!(fp_read = fopen (file_name, "rb"))){
        return -1;
    }
    
    fseek(fp_read, 0, SEEK_END);
    int file_size = ftell(fp_read);
    /* Seek back to the beginning of input file */
    fseek(fp_read, 0, SEEK_SET);
    int total_records = file_size / sizeof(Record);
    
    /* Variables for recording time */
    struct timeb t_begin, t_end;
    long time_spent_ms;

    int cur_uid1 = 0;
    int cur_uid1_counter = 0;
    int max_uid1 = 0;
    int num_unique_uid1s = 0;

    ftime(&t_begin);
    /* Read records into buffer */
    while (fread(buffer, sizeof(Record), records_per_block, fp_read) > 0){
        int i = 0
        while (i < records_per_block){
            if (buffer[i].uid1 == cur_uid1){
                cur_uid1_counter += 1;
            }
            else { /* buffer[i].uid1 != cur_uid1 */ 
                if (cur_uid1_counter > max_uid1) {
                    max_uid1 = cur_uid1_counter;
                }
                cur_uid1 = buffer[i].uid1;
                /* Reset counter for new uid1 */
                cur_uid1_counter = 1;
                num_unique_uid1s += 1;              
            }
            i++;
        }
    }

    fclose(fp_read);
    free(buffer);
    ftime(&t_end);

    time_spent_ms = (long) (1000 *(t_end.time - t_begin.time) + (t_end.millitm - t_begin.millitm));

    /* Printing max and average*/
    printf("Max: %d\n Average: %f\n", max_uid1, num_unique_uid1s / (float)total_records);
    /* result in MB per second */
    printf ("Data rate: %.3f MBPS\n", ((total_records*sizeof(Record))/(float)time_spent_ms * 1000)/(1024*1024));
 
    return 0;
}
