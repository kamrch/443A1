#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct record {
 int uid1;
 int uid2;
} Record;

int main(int argc, char *argv[]){
		/*Check if user input correct arguments*/
		if (argc != 3){
    		printf("Usage: write_lines <input filename> <block size>\n");
    		return -1;
		}
		char *file_name = argv[1];
		int block_size = atoi(argv[2]);		
		
}