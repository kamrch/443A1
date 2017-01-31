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
		
		long timeSpent;
		
		/*FILE pointers*/
		FILE *fp_read, *fp_write;
		
		Record * buffer = (record *) calloc (records_per_block, sizeof (record)) ;
		/*Record* data = parseRecord(fp_read, MAX_LENGTH);*/
		
		int offset = 0;
		
    if (!(fp_write = fopen ("records.dat" , "wb")) || !(fp_read = fopen(file_name, "rb"))) {
        printf ("Error when opening file(s).\n");
        return -1;
		}
		
		ftime(&t_begin);
		/*Start clock before or after allocating buffer?*/
		
		/*Loop for writing to file*/
		while(fgets (current_line, MAX_CHARS_PER_LINE, fp_read)!=NULL ) {
			current_line [strcspn (current_line, "\r\n")] = '\0'; //remove end-of-line characters
			if (strlen(current_line) > 0){
	    	Record r = parseRecord(current_line);
	    	if (offset >= records_per_block){
					fwrite ( buffer, sizeof(Record), offset, fp_write);
					fflush (fp_write);
					j = 0;
					offset = 0;
	    	}
	    	buffer[j] = r;
	    	j+=1;
	    	offset+=1;
	    	total_records += 1;
			}			
		}
		
		/*Write remaining data to file, if any*/
		if (offset > 0){
			fwrite(buffer, sizeof(Record), offset, fp_write);
		}
		
		fflush(fp_write);
		fclose(fp_write);
		
		 ftime(&t_end);
		 
		 free(buffer);
		 fclose(fp_read);
		 
		time_spent_ms = (long) (1000 *(t_end.time - t_begin.time) + (t_end.millitm - t_begin.millitm));
		
		/*Printing results*/
		printf("block size: %d bytes\n", block_size);
		
		
		/* result in MB per second */
		printf ("Data rate: %.3f MBPS\n", ((total_records*sizeof(Record))/(float)time_spent_ms * 1000)/(1024*1024));
		
}	