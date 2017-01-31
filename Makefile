CC = gcc
CFLAGS = -O3 -Wall 
CFLAGS += -D_LARGEFILE_SOURCE
CFLAGS += -fno-exceptions
CFLAGS += -finline-functions
CFLAGS += -funroll-loops
CFLAGS += -D_FILE_OFFSET_BITS=64
 
# Source files
WRITE_BLOCKS_SRC=helper.c write_blocks_seq.c 

WRITE_LINES_SRC=helper.c write_lines.c
 
# Binaries
all: write_blocks_seq write_lines

#sequential writing in blocks
write_blocks_seq: $(WRITE_BLOCKS_SRC)
	$(CC) $(CFLAGS) $^ -o write_blocks_seq
	
write_lines: $(WRITE_LINES_SRC)
	$(CC) $(CFLAGS) $^ -o write_lines

clean:  
	rm write_blocks_seq write_lines
