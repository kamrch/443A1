#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>
#include "helper.h"



int main(int argc, char *argv[]){
		/*Check if user input correct arguments*/
		if (argc != 3){
    		printf("Usage: write_blocks_seq <input filename> <block size>\n");
    		return -1;
		}
		char *filename = argv[1];
		int block_size = atoi(argv[2]);
		
		int records_per_block = block_size / sizeof(Record));
		
		/*Codes for recording time*/
		struct timeb t_begin, t_end;
		long total_records = 0;
		
		double timeSpent;
		
		/*FILE pointers*/
		FILE *input_file, *output_file;
		
    if (!(output_file = fopen ("records.dat" , "w")) || !(input_file = fopen(file_name, "r"))) {
        printf ("Error when opening file(s).\n");
        return -1;
		}
		
		ftime(&t_begin);
		/*Start clock before or after allocating buffer?*/
		Record buffer[records_per_block];
		Record* data = parseRecord(input_file, MAX_LENGTH);
		
		int counter = 0;
		
		/*Loop for writing to file*/
		while(data != NULL) {
			buffer[counter] = *data;
			free(data);
			counter += 1;
			
			/*Read until buffer is full*/
			if (counter>=records_per_block){
				fwrite(buffer, sizeof(Record), records_per_block, output_file);
				fflush(output_file);
				counter = 0;
			}
				
			data = parseRecord(input_file, MAX_LENGTH);
			total_records += 1;
		}
		
		/*Write remaining data to file, if any*/
		fwrite(buffer, sizeof(Record), counter, output_file);
		
		 ftime(&t_end);
		
}