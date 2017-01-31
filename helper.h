#define MAX_CHARS_PER_LINE 256

typedef struct record{
    int uid1;
    int uid2;
} Record;


Record parseRecord (char* str);
