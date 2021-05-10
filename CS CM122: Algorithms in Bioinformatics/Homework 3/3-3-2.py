def overlap(reads):

    # overlapReads = []
    # for i in reads:
    #     overlapReads[i] = []

    # for i in overlapReads:
    #     for j in reads:
    #         if i[1:] == j[:-1]:
    #             overlapReads[i].append(j)

    overlapGraphReads,i = [],0
    while i < len(reads):
        curr = reads[i]
        matches = []
        j = 0
        while j < len(reads):
            compare = reads[j]
            if j == i:
                j+=1
                continue
            else:
                if curr[1:] == compare[:-1]:
                    matches.append(compare)
            j+=1
        i+=1
        k = 0
        result = ""
        while k < len(matches):
            if k == 0:
                result += curr + " -> "
                result = result + matches[k]
            elif k > 0:
                result = result + ", " + matches[k]
            k+=1
        if len(result) != 0:
            overlapGraphReads.append(result)

    outF = open('3-3-2_output.txt', 'w')
    for line in overlapGraphReads:
        outF.write(line)
        outF.write("\n")
    outF.close()
    return overlapGraphReads

reads = []
with open('3-3-2.txt', 'r') as fd:
    for line in fd:
        line = line.rstrip("\n")
        reads.append(line)

overlap(reads)
# print(overlap(reads))