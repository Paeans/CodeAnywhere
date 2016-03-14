def getmotif():
    
    motif_matrix = []
    
    motif_matrix.append([1, 2, 2, 0])
    motif_matrix.append([2, 1, 2, 0])
    motif_matrix.append([3, 0, 1, 1])
    motif_matrix.append([0, 5, 0, 0])
    motif_matrix.append([5, 0, 0, 0])
    motif_matrix.append([0, 0, 4, 1])
    motif_matrix.append([0, 1, 4, 0])
    motif_matrix.append([0, 0, 0, 5])
    motif_matrix.append([0, 0, 5, 0])
    motif_matrix.append([0, 1, 2, 2])
    motif_matrix.append([0, 2, 0, 3])
    motif_matrix.append([1, 0, 3, 1])
    return motif_matrix


def calcPWMScore(smpair):
    seq, motif = smpair
    score = 0
    
    for i in range(len(motif)):
        c = seq[i]
        index = -1
        if c == 'A' or c == 'a':
            index = 0
            score += motif[i][index]
            total = 0
            for j in range(len(motif[i])):
                total += motif[i][j]
            if total == 0:
                score = 0
            else:
                score = score / total
            
        if c == 'C' or c == 'c':
            index = 1
            score += motif[i][index]
            total = 0
            for j in range(len(motif[i])):
                total += motif[i][j]
            if total == 0:
                score = 0
            else:
                score = score / total
                
        if c == 'G' or c == 'g':
            index = 2
            score += motif[i][index]
            total = 0
            for j in range(len(motif[i])):
                total += motif[i][j]
            if total == 0:
                score = 0
            else:
                score = score / total
                
        if c == 'T' or c == 't':
            index = 3   
            score += motif[i][index]
            total = 0
            for j in range(len(motif[i])):
                total += motif[i][j]
            if total == 0:
                score = 0
            else:
                score = score / total
    
    score = score * 0.1
    score = score / len(motif)
    return (seq, score);
    
result = calcPWMScore(("ACTTGGAACCTG", getmotif()))
print result

scoreList = []
for i in range(1, 101):
    scoreList.append(0)
    
score = 0.89387
index = int(score * 100)

scoreList[index] = 1

def getbase(motif_line):
    list = motif_line.split()
    if not len(list) == 6:
        return None
    
    result = []
    for i in range(1, 5):
        result.append(float(list[i]))
    
    return result
    
#f = open('workfile', 'r')
def readmotif(file):
    motif = []
    while True:
        line = file.readline()
        if line.startswith("XX"):
            break;
        
        motif.append(getbase(line))
        
    return motif
    
def constructMotif(filename):
    file = open(filename, 'r')
    counter = 0
    
    motif_list = []
    while True:
        line = file.readline()
        if line == '':
            break
        if line.startswith("PO"):
            motif_list.append((counter, readmotif(file)))
            counter = counter + 1
            pass
        
    return motif_list


'''
file = open('TRANSFAC-FINAL.txt', 'r')
#print constructMotif('TRANSFAC-FINAL.txt')


data_filename = \
    ["/chr1.fa", "/chr2.fa", \
     "/chr3.fa", "/chr4.fa", \
     "/chr5.fa", "/chr6.fa", \
     "/chr7.fa", "/chr8.fa", \
     "/chr9.fa", "/chr10.fa", \
     "/chr11.fa", "/chr12.fa", \
     "/chr13.fa", "/chr14.fa", \
     "/chr15.fa", "/chr16.fa", \
     "/chr17.fa", "/chr18.fa", \
     "/chr19.fa", "/chrX.fa", \
     "/chrY.fa",  "/chrM.fa"]
    
scoreList = []
for i in range(1, 101):
    scoreList.append(0)
    
tmp = "slkjdflskjdfosiejflksdjflskdjflskdjflskdjfsleijfskdfjslkdfj"
result = []
index = 0
size = 5
while index + size <= len(tmp):
    result.append(tmp[index:(index + size)])
    index = index + 1
    
def sumScoreList(a, b):
    listLength = 0
    if len(a) > len(b) :
        listLength = len(b)
    else:
        listLength = len(a)
    result = []
    tmp = []
    for i in range(listLength):
        result.append(0)
    for i in range(listLength):
        result[i] = a[i] + b[i]
    for i in range(listLength):
        tmp.append((i * 1.0 / 100, result[i]))
    return tmp;

print sumScoreList([1, 3, 4], [7, 9, 3])
'''

with open("datafortest.txt", 'r') as f:
    f.seek(100)
    length = 50
    genestr = ""
    while(len(genestr) < length * 2):
        tmpstr = f.readline().rstrip('\n')
        genestr = genestr + tmpstr[0 : min(length * 2 - len(genestr), len(tmpstr))]
    print genestr
    f.seek(25)
    length = 50
    genestr = ""
    while(len(genestr) < length * 2):
        tmpstr = f.readline().rstrip('\n')
        genestr = genestr + tmpstr[0 : min(length * 2 - len(genestr), len(tmpstr))]
    print genestr
    
#print min(1, 3)


