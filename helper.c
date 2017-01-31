#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "helper.h"


/* Parse string into a record */
/**
 * Work in progress*****
 * **/
Record *parseRecord(char* str) {

    Record r;
    
    r.uid1 = atoi(strtok(str, ","));
    r.uid2 = atoi(strtok(NULL, ","));

    return r; 
}