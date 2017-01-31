#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "helper.h"


/* Parse string into a record */
/**
 * Work in progress*****
 * **/
Record parseRecord(char* str) {

    Record record;

    /* Parsing records using strtok */
    record.uid1 = atoi(strtok(str, ","));
    record.uid2 = atoi(strtok(NULL, ","));

    return record;
}
