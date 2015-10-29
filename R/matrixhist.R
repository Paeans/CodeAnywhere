## Rscript saveplot.r #arg1 arg2

datafile <- "../PPC/matrix.txt"
dat<-read.table(datafile)
vdat <- unlist(dat)

jpeg(file = "matrixhist.jpeg")
par(mfrow = c(1, 2))

hist(vdat, breaks = c(0.1 * -10 : 10), col = "green")
hist(vdat, breaks = c(0.05 * -20 : 20), col = "red")

dev.off()

q(status = 0)
