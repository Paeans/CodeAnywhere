
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

def calcPWMScore(seq, motif):
    score = 0
    for i in range(len(seq)):
        c = seq[i]
        index = -1
        if c == 'A' or c == 'a':
            index = 0
        if c == 'C' or c == 'c':
            index = 1
        if c == 'G' or c == 'g':
            index = 2
        if c == 'T' or c == 't':
            index = 3            
        score += motif_matrix[i][index]
    return score;
    
result = calcPWMScore("ACTTGGAACCTG", motif_matrix)
print result


