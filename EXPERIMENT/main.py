##
# Author:  G. Pan
# Date:    2016 - 01 - 12
# Version: 1.0
#
##
# Licensed to the Apache Software Foundation (ASF) under one or more
# contributor license agreements.  See the NOTICE file distributed with
# this work for additional information regarding copyright ownership.
# The ASF licenses this file to You under the Apache License, Version 2.0
# (the "License"); you may not use this file except in compliance with
# the License.  You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
#
## USAGE
# ./bin/spark-submit \
#  # --master spark://master:7077 \
#  --driver-memory 4096M
#  --executor-memory 4096M
#  path/to/main.py \
#  1000

from pyspark import SparkContext, SparkConf

appName = "motif_Finding"
master_server = "master"
master_port = "7077"
master = "spark://" + master_server + ":" + master_port

hdfs_server = "master"
hdfs_port = "9000"
hdfs = "hdfs://" + hdfs_server + ":" + hdfs_port

motif_filename = "/motifList"
score_filename = "/scoreFile"
score_listname = "/scoreList"

motif_file = "TRANSFAC-FINAL.txt"

data_filename = \
    ["/chr1.fa",    "/chr2.fa",     \
     "/chr3.fa",    "/chr4.fa",     \
     "/chr5.fa",    "/chr6.fa",     \
     "/chr7.fa",    "/chr8.fa",     \
     "/chr9.fa",    "/chr10.fa",    \
     "/chr11.fa",   "/chr12.fa",    \
     "/chr13.fa",   "/chr14.fa",    \
     "/chr15.fa",   "/chr16.fa",    \
     "/chr17.fa",   "/chr18.fa",    \
     "/chr19.fa",   "/chrX.fa",     \
     "/chrY.fa",    "/chrM.fa"]


conf = SparkConf().setAppName(appName)
sc = SparkContext(conf=conf)
    

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

def storeMotifList(motif_list):
    if motif_list == None:
        return
    
    motif_rdd = sc.parallelize(motif_list)
    motif_rdd.saveAsTextFile(hdfs + motif_filename)
    
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
    if len(seq) < len(motif):
        return (seq, 0)
    
    for i in range(len(motif)):
        c = seq[i]
        index = -1
        if c == 'A' or c == 'a':
            index = 0            
            total = 0
            
            for j in range(len(motif[i])):
                total += motif[i][j]
            if total == 0:
                tmp = 0
            else:
                tmp = motif[i][index]
            score += tmp * 1.0 / total
            
        if c == 'C' or c == 'c':
            index = 1
            total = 0
            
            for j in range(len(motif[i])):
                total += motif[i][j]
            if total == 0:
                tmp = 0
            else:
                tmp = motif[i][index]
            score += tmp * 1.0 / total
            
        if c == 'G' or c == 'g':
            index = 2
            total = 0
            
            for j in range(len(motif[i])):
                total += motif[i][j]
            if total == 0:
                tmp = 0
            else:
                tmp = motif[i][index]
            score += tmp * 1.0 / total
            
        if c == 'T' or c == 't':
            index = 3  
            total = 0
            
            for j in range(len(motif[i])):
                total += motif[i][j]
            if total == 0:
                tmp = 0
            else:
                tmp = motif[i][index]
            score += tmp * 1.0 / total
            
    score = score * 0.1
    score = score / len(motif)
    return (seq, score);

def reduceSmpair(pair01, pair02):
    seq1, score01 = pair01
    seq2, score02 = pair02
    if pair01 > pair02 :
        return ((seq1), score01)
    else:
        if pair01 < pair02 :
            return ((seq2), score02)
        else:
            return ((seq1, seq2), score01)

        
def getScore(smpair):
    seq, score = smpair
    return score
    
def getScoreDist(ssPair):
    seq, score = ssPair
    scoreList = []
    for i in range(1, 101):
        scoreList.append((i * 1.0 / 100, 0))
    index = int(score * 100)
    scoreList[index] = (i * 1.0 / 100, 1)
    return scoreList
    
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
        _, t = a[i]
        _, s = b[i]
        result[i] = t + s
    for i in range(listLength):
        tmp.append((i * 1.0 / 100, result[i]))
    return tmp;
        
def sublines(lmpair):
    line, motif = lmpair
    if len(line) < len(motif):
        return (line, motif)
    
    size = len(motif)
    result = []
    index = 0
    while index + size <= len(line):
        result.append((line[index:(index + size)], motif))
        index = index + 1
        
    return sc.parallelize(result)

    
def main_fun(motif, num):
    
    #motif = getmotif()
    
    for filename in data_filename:
        
        lines = sc.textFile(hdfs + filename)
        scoreFile = lines.map(lambda line: (line, motif)).map(calcPWMScore)
        scoreFile.saveAsTextFile(hdfs + score_filename + "_" + filename + "_" + str(num))
        
        maxScore = scoreFile.max(key=getScore)
        minScore = scoreFile.min(key=getScore)
        
        resultList = scoreFile.map(getScoreDist).reduce(sumScoreList)
        sc.parallelize(resultList).saveAsTextFile(hdfs + score_listname + "_" + filename + "_" + str(num))

        
def getmatrix(motifstr):
    if motifstr == None or len(motifstr) < 4:
        return [[]]
    result = []
    
        
#if __name__ == "__main__":
motifs = constructMotif(motif_file)
storeMotifList(motifs)

motifFile = sc.textFile(hdfs + motif_filename);

for motifpair in motifs:
    num, motif = motifpair
    main_fun(motif, num)


    
'''
lines = sc.textFile(hdfs + "/chr1.fa")
scoreFile = lines.map(lambda line: (line, motif)).map(sublines).map(calcPWMScore)
scoreFile.saveAsTextFile(hdfs + score_filename + "_chr1_fa")

maxScore = scoreFile.max(key=getScore)
minScore = scoreFile.min(key=getScore)

resultList = scoreFile.map(getScoreDist).reduce(sumScoreList)
sc.parallelize(resultList).saveAsTextFile(hdfs + score_listname + "_chr1_fa")
'''

sc.stop()

