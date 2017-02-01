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

READ_BLOCKS_SEQ_SRC=helper.c read_blocks_seq.c

READ_RAM_SEQ_SRC=helper.c read_ram_seq.c
 
# Binaries
all: write_blocks_seq write_lines read_blocks_seq read_ram_seq

#sequential writing in blocks
write_blocks_seq: $(WRITE_BLOCKS_SRC)
	$(CC) $(CFLAGS) $^ -o write_blocks_seq
	
write_lines: $(WRITE_LINES_SRC)
	$(CC) $(CFLAGS) $^ -o write_lines

read_blocks_seq: $(READ_BLOCKS_SEQ_SRC)
	$(CC) $(CFLAGS) $^ -o read_blocks_seq

read_ram_seq: $(READ_RAM_SEQ_SRC)
	$(CC) $(CFLAGS) $^ -o read_ram_seq

clean:  
	rm write_blocks_seq write_lines read_blocks_seq read_ram_seq
