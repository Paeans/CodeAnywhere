######################################################################
#  Problem 04

def myLog(x, b):
    res = 0
    tmp = 1
    while tmp * b <= x:
        res += 1
        tmp *= b
    return res

#  simple test case
print myLog(1, 2)
print myLog(9, 2)

#  End of Problem 04
######################################################################



######################################################################
#  Problem 05

def lessThan4(aList):
    res = []
    for string in aList:
        if len(string) < 4: res.append(string)
    return res

#  simple test case
print lessThan4(["apple", "cat", "dog", "banana"])

#  End of Problem 05
######################################################################



######################################################################
#  Problem 06

def sumDigits(N):
    if N < 10: return N
    return sumDigits(N / 10) + N % 10

#  simple test case
print sumDigits(100)
print sumDigits(1)
print sumDigits(330)

#  End of Problem 06
######################################################################



######################################################################
#  Problem 07

def keysWithValue(aDict, target):
    res = []
    index = 0
    for key in aDict.keys():
        if not (aDict[key] == target): continue
        while 0 <= index < len(res):
            if res[index] < key:
                index += 1
            elif res[index -1] > key:
                index -= 1
            else:
                break
        res.insert(index, key)
    return res

#  simple test case
print keysWithValue({0: 0, 2: 1, 4: 0, 5: 3, 7: 3, 9: 0, 10: 2}, 0)

#  End of Problem 07
######################################################################



######################################################################
#  Problem 08

def satisfiesF(L):
    i = 0
    while i < len(L):
        if f(L[i]): i += 1
        else: L.pop(i)
    return len(L)
run_satisfiesF(L, satisfiesF)

#  simple test case

#  End of Problem 08
######################################################################
