## Rscript saveplot.r #arg1 arg2

datafile <- "../PPC/matrix.txt"
dat<-read.table(datafile)
vdat <- unlist(dat)

jpeg(file = "matrixhist.jpeg")
op <- par(mfrow = c(1, 2))

colors <- c("red", "yellow", "green", "violet", "orange", "blue", "pink", "cyan")
hist(vdat, breaks = c(0.1 * -10 : 10), col = colors)
hist(vdat, breaks = c(0.05 * -20 : 20), col = colors)
par(op)

dev.off()

q(status = 0)
