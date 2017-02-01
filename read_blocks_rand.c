#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/timeb.h>
#include "helper.h"

/*Helper function to check if previous variables needs to be updated*/
bool check_update(int temp_max_followers, int prev_max_followers, int temp_max_id, int prev_max_id){
	return (temp_max_id != prev_max_id && temp_max_followers > prev_max_followers);
}

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
		int temp_average = 0;
		struct timeb t_begin, t_end;
		
		/*Use fseek to find the file size and to reset pointer*/
		fseek(fp_read, 0L, SEEK_END);
		int file_size = ftell(fp_read);
		fseek(fp_read, 0L, SEEK_SET);
		long total_records = file_size / sizeof(Record);
		
		/*Main loop iterating the user indicated random number of times.*/
		int i = 0;
		ftime(&t_begin);
		while (i < random_number){
			/*generate a random number within 0 to total number of records.*/
			int rn = rand() % total_records;
			/*Set point to the randomized location*/
			fseek(fp_read, rn*sizeof(Record), SEEK_SET);
			
 			records_per_block = block_size/sizeof(Record);
			int result = fread(buffer, sizeof(Record), records_per_block, fp_read);
			if(result != records_per_block){
				/*check if total records is less than a block*/
				records_per_block = result;
			}
			
			int buffer_index = 0;
			int temp_max_id = -1;
			int temp_max_followers = 0;
			int prev_max_id = -1;
			int prev_max_followers = -1;
			int id_counter = 0;
			
			/*loop to examine all records to find max and average*/
			while (records_per_block > buffer_index){
				if (temp_max_id == buffer[pointer].uid1)){
					temp_max_followers += 1;
				} else if (temp_max_id == -1){
					id_counter += 1;
					temp_max_followers = 1;
					temp_max_id = buffer[buffer_index].uid1;
				}	else {
					
					if (check_update(temp_max_followers, prev_max_followers, temp_max_id, prev_max_id)){
						/*update prev here*/
						prev_max_id = temp_max_id;
						prev_max_followers = temp_max_followers;
					}					
					temp_max_id = buffer[buffer_index].uid1;
					temp_max_followers = 1;
					id_counter +=1;
				}
				
				buffer_index += 1;
			}
			
			if (check_update(temp_max_followers, prev_max_followers, temp_max_id, prev_max_id)){
				prev_max_followers = temp_max_followers;
				prev_max_id = temp_max_id;
				id_counter++;									
			}
			
			/*Finding the average*/
			temp_average += records_per_block/id_counter; //***
			
			//WIP
			  			
		}
		
	
	return 0;
}
