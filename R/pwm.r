# source("https://bioconductor.org/biocLite.R")
# biocLite()
# biocLite(Biostrings)

library(Biostrings)


a <- c(0, 4, 4, 0, 3, 7, 4, 3, 5, 4, 2, 0, 0, 4)
c <- c(3, 0, 4, 8, 0, 0, 0, 3, 0, 0, 0, 0, 2, 4)
g <- c(2, 3, 0, 0, 0, 0, 0, 0, 1, 0, 6, 8, 5, 0)
t <- c(3, 1, 0, 0, 5, 1, 4, 2, 2, 4, 0, 0, 1, 0)

m <- matrix(data=as.integer(c(a,c,g,t)),nrow=4,byrow=T,dimnames=list(c('A','C','G','T')))

r <- PWM(m, type = "log2probratio")

