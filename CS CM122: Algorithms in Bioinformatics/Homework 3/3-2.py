def compositionk(text, k):
    composition, i = [], 0
    while i < (len(text) - k+1):
        composition.append(text[i:i+k])
        i+=1
    outF = open('output.txt', 'w')
    for line in composition:
        outF.write(line)
        outF.write("\n")
    outF.close()
        

file = open('3-2.txt')
content = file.readlines()
a = 0
a += int(content[0])
genome = content[1]

# print(a)
# print(genome)

print(compositionk(genome,a))

