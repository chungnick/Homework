def genomePath(reads):
    genome, i = "", 0
    while i < (len(reads)):
        if i == len(reads) - 1:
            genome += reads[i]
            break
        curr = reads[i]
        genome += curr[0]
        i+=1
    print(len(genome))
    return genome

reads = []      
with open('3-3-1.txt', 'r') as f:
    for line in f:
        reads.append(line)

# print(len(reads))
# print(len(reads[0]))
# print(len(reads) - len(reads[0]))

print(genomePath(reads))

