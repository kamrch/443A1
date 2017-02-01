import os
import subprocess

KB = 1024
MB = 1024 * 1024
sizes = [
 512,
 1 * KB,
 4 * KB,
 8 * KB,
 16 * KB,
 32 * KB,  
 1 * MB,
 2 * MB,
 4 * MB
]

filenames = ["edges.csv", "edges_1.csv",  "edges_2.csv",  "edges_3.csv",  "edges_4.csv",  "edges_5.csv"]

for i in range(0, len(filenames)):
    fBlocks = open("block_result_"+ str(i+1) + ".txt", "w")
    
    
    for size in sizes:
        #Use subprocess to execute commands
        subprocess.run(["write_blocks_seq", filenames[i], str(size)], stdout=fBlocks)
        subprocess.run(["rm", "records.dat"])        

    fLines = open("line_result_"+ str(i+1) + ".txt", "w")
    
    subprocess.run(["write_lines", filename[i]], stdout=fLines)
    subprocess.run(["rm", "records.dat"])
    
    fLines.close()
    fBlocks.close()
    
    print ("*************Iteration number " + str(i+1)+"************")