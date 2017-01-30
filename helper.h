#define MAX_LENGTH 256

typedef struct record{
    int uid1;
    int uid2;
} Record;


Record* parseRecord (FILE *fp, int MAX_CHARS_PER_LINE);
