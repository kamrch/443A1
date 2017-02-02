import os
import sys

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


#loop for write_lines
for k in range(0,len(filenames)):
        os.system("echo '======Iteration "+str(k+1)+"======' >> line_result.txt"); 
        os.system("./write_lines "+filenames[k]+" >> line_result.txt"); 
        os.system("rm records.dat")


#Loop for write_blocks_seq with different block size
for size in sizes:
    for j in range(0,len(filenames)):
        os.system("echo '======Iteration "+str(j+1)+"======' >> blocks_seq_"+str(size)+".txt"); 
        os.system("./write_blocks_seq "+filenames[j]+" " + str(size) + " >> blocks_seq_"+str(size)+".txt");
        os.system("rm records.dat") 


print("Script completed.")