#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/timeb.h>
#include "helper.h"

int main(int argc, char *argv[]){
	    /*Check if user input correct arguments*/
    if (argc != 4){
        printf("Usage: read_blocks_rand <input filename> <block_size> <random_number>\n");
        return -1;
    }
    char *file_name = argv[1];
    int block_size = atoi(argv[2]);
		int random_number = atoi(argv[3]);
    
		int records_per_block = block_size / sizeof(Record);	
		
		FILE *fp_read;
		/* allocate buffer for 1 block */
		Record * buffer = (Record *) calloc (records_per_block, sizeof (Record)) ;
		
		if (!(fp_read = fopen ( file_name , "rb" ))){
			printf ("Error when reading file \"%s\" \n", file_name);
			return -1;
		}
		
		int records_counter = 0;
		long time_spent_ms;
		int average = 0;
		struct timeb t_begin, t_end;
		
		/*Use fseek to find the number of records*/
		fseek(fp_read, 0L, SEEK_END);
		int file_size = ftell(fp_read);
		fseek(fp_read, 0L, SEEK_SET);
		long total_records = file_size / sizeof(Record);
		
	
	return 0;
}
