import random

number = 1
counter = 10000000
f = open("data.txt", 'w')
f.write(str(number))
f.write('\n')
for i in range(0, number):
    f.write(str(counter))
    f.write('\n')
    for j in range(0, counter):
        f.write(str(random.randint(0, 10000000)))
        f.write(" ")
    f.write('\n')

f.close()