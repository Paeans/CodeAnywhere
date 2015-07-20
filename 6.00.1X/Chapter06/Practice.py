# print object
# print type(object)
from Problem06 import *
class baseclass(object):
    def __init__(self):
        self.x = 1
        pass

class subclass(baseclass):
    def __init__(self):
        baseclass.__init__(self)
        self.y = 2
        pass

a = subclass()
# print a.x, a.y 

def genTest(a, b):
    print a, b
    yield 1
    print b, a 
    yield 2
    print 'End'

gtest = genTest('a', 'b')
print gtest.next()
print 'Mid'
print gtest.next()

for e in genTest('c', 'd'):
    print e 

def genPrimes():
    primeList = []
    tmp = 2
    while True:
        tag = True
        for e in primeList:
            if ( tmp % e ) == 0:
                tag = False
                break
        if tag: 
            primeList.append(tmp)
            yield tmp
        tmp += 1
        
print buildCoder(5)