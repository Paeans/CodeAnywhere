def lotsOfParameters1(a,b,c,d,e):
    print a
    print b
    print c
    print d
    print e

lotsOfParameters1()                         # ERROR
lotsOfParameters1(1, 2)                     # ERROR
lotsOfParameters1(1,e=5,d=4,c=3,b=2)        # 1 2 3 4 5
lotsOfParameters1(e=5,a=1,d=4,b=2,c=3)      # 1 2 3 4 5
lotsOfParameters1(a=5,b=1,c=4,d=2,3)        # ERROR

#############################################
def lotsOfParameters2(a=1,b=2,c=3,d=4,e=5):
    print a
    print b
    print c
    print d
    print e
    
lotsOfParameters2()                         # 1 2 3 4 5
lotsOfParameters2(1, 2)                     # 1 2 3 4 5
lotsOfParameters2(1, c=2)                   # 1 2 3 4 5
lotsOfParameters2(1, c=2, 3)                # ERROR
lotsOfParameters2(1, e=20, b=3)             # 1 3 3 4 20
lotsOfParameters2(1, e=20, b=3, a=10)       # ERROR

lotsOfParameters2(5,4,3,2,1)                # 5 4 3 2 1

#############################################
def lotsOfParameters3(a,b,c=3,d=4,e=5):
    print a
    print b
    print c
    print d
    print e
    
lotsOfParameters3()                         # ERROR
lotsOfParameters3(1, 2)                     # 1 2 3 4 5
lotsOfParameters3(1, c=2)                   # ERROR
lotsOfParameters3(1, c=2, 3)                # ERROR
lotsOfParameters3(1, c=2, b=3)              # 1 3 2 4 5

lotsOfParameters3(1,e=5,d=4,c=3,b=2)        # 1 3 2 4 5
lotsOfParameters3(e=5,d=4,c=3,b=2,1)        # ERROR
lotsOfParameters3(e=5,a=1,d=4,b=2,c=3)      # 1 2 3 4 5

