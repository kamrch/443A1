#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "helper.h"


/* Parse an individual record and returns 1 record */
/**
 * Work in progress*****
 * **/
Record* parseRecord (FILE *fp, int MAX_CHARS_PER_LINE){

    char current_line[MAX_CHARS_PER_LINE];
    Record* temp = (Record *)malloc(sizeof(Record));

    if(fgets(current_line, MAX_CHARS_PER_LINE, fp) != NULL){
        char* split = strtok(current_line, ",");
        temp->uid1 = atoi(split);
        split = strtok(NULL, ",");
        temp->uid2 = atoi(split);
        return temp;
    }
    else
        free(temp);
    return NULL;
}}