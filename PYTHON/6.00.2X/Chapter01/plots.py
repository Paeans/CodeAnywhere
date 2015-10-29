import matplotlib
matplotlib.use('Agg')
import pylab

pylab.figure(1)
pylab.plot([1,2,3,4], [1,4,9,16])
pylab.figure(2)
pylab.plot([3, 4, 9, 2], [8, 4, 7, 1])
pylab.savefig("fig01")
pylab.figure(1)
pylab.plot([9, 7, 4, 5])
pylab.savefig("fig02")

