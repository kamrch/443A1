#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "helper.h"



int main(int argc, char *argv[]){
		/*Check if user input correct arguments*/
		if (argc != 3){
    		printf("Usage: write_blocks_seq <input filename> <block size>\n");
    		return -1;
		}
		char *filename = argv[1];
		int *block_size = argv[2];		
		
}