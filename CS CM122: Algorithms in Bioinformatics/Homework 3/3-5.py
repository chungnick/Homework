def debruijn_from_kmer(kmers):
    '''
    Construct the de Bruijn graph from a set of k-mers.
    Input: A collection of k-mers Patterns.
    Output: The adjacency list of the de Bruijn graph DeBruijn(Patterns).
    '''
    g = []
    # build a prefixing pattern dict
    dprefix = {}
    for e in kmers:
        prefix = e[:-1]
        dprefix.setdefault(prefix, []).append(e[1:])
    # build lexicographically sorted adjacency list
    for k in sorted(dprefix.keys()):
        g.append( (k,sorted(dprefix[k])) )
    print(g)
    outF = open('3-5_output.txt', 'w')
    for line in g:
        temp = line[0] + " ->"
        for k in line[1]:
            if temp[-1] == '>':
                temp += " " + k
            else:
                temp += "," + k
        outF.write(temp)
        outF.write("\n")
    outF.close()
    return g

reads = []      
with open('3-5.txt', 'r') as f:
    for line in f:
        line = line.rstrip("\n")
        reads.append(line)
        

debruijn_from_kmer(reads)

# Sample Input:
# GAGG
# CAGG
# GGGG
# GGGA
# CAGG
# AGGG
# GGAG
# Sample Output:
# AGG -> GGG
# CAG -> AGG,AGG
# GAG -> AGG
# GGA -> GAG
# GGG -> GGA,GGG


