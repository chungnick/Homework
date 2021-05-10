def deBruijn(text, k):
    nodeList, i = [], 0
    while i < len(text) - k+1:
        curr = text[i:i+k]
        j = 0
        if len(nodeList) == 0:
            nodeList.append(curr)
        while j < len(nodeList):
            curNode = nodeList[j]
            addMe = True
            if curr == curNode:
                addMe = False
            if curNode[1:] == curr[:k-1]:
                if curr[len(curr)-1] == '>':
                    print("hi")
                    nodeList[j] = curr + " " + curNode
                    addMe = False
                else:
                    print("bye")
                    nodeList[j] = curr + "," + curNode
                    print(nodeList[j])
                    addMe = False
            if addMe == True:
                curr = curr + " ->"
                nodeList.append(curr)
            j+=1
        i+=1
    outF = open('3-4_output.txt', 'w')
    for line in nodeList:
        outF.write(line)
        outF.write("\n")
    outF.close()
    return nodeList

file = open('3-4.txt', 'r')
content = file.readlines()
a = 0
a += int(content[0])
genome = content[1]

# print(a)
# print(genome)

deBruijn(genome, a)