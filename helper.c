#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "helper.h"

/* Helper function to count number of lines */
int lineCount(char *filename){

    FILE* fp = fopen(filename, "r");
    unsigned long newLineCounter = 0;
    int c;

    fseek(fp, 0, SEEK_SET);

    while ( (c=fgetc(fp)) != EOF ) {
        if ( c == '\n' ) {
            newLineCounter++;
        }
    }
    fclose(fp);

    printf("%lu newline characters\n", newLineCounter);
    return newLineCounter;
}

/* Parse an individual record and returns 1 record */
/**
 * Work in progress*****
 * **/
Record* parseRecord (FILE *fp, int MAX_CHARS_PER_LINE){

    char current_line[MAX_CHARS_PER_LINE];
    Record* temp = (Record *)malloc(sizeof(Record));

    if(fgets(current_line, MAX_CHARS_PER_LINE, fp) != NULL){
        char* splitted = strtok(current_line, ",");
        temp->uid1 = atoi(splitted);
        splitted = strtok(NULL, ",");
        temp->uid2 = atoi(splitted);
        return temp;
    }
    else
        free(temp);
    return NULL;
}