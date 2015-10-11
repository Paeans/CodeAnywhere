# Rscript saveplot.r #arg1 arg2
# R CMD BATCH --no-save "--args arg1 arg2" saveplot.r

#! /path/to/Rscript
#args <- commandArgs(TRUE)

#! /path/to/Rscript

jpeg(file = "myplot.jpeg")

op <- par(mfrow = c(2, 2))
hist(islands)
utils::str(hist(islands, col = "gray", labels = TRUE))

hist(sqrt(islands), breaks = 12, col = "lightblue", border = "pink")
##-- For non-equidistant breaks, counts should NOT be graphed unscaled:
r <- hist(sqrt(islands), breaks = c(4*0:5, 10*3:5, 70, 100, 140),
          col = "blue1")
text(r$mids, r$density, r$counts, adj = c(.5, -.5), col = "blue3")
sapply(r[2:3], sum)
sum(r$density * diff(r$breaks)) # == 1
lines(r, lty = 3, border = "purple") # -> lines.histogram(*)
par(op)

require(utils) # for str
str(hist(islands, breaks = 12, plot =  FALSE)) #-> 10 (~= 12) breaks
str(hist(islands, breaks = c(12,20,36,80,200,1000,17000), plot = FALSE))

dev.off()

q(status=0)

#Format	    Driver	      Notes
#JPG	        jpeg	        Can be used anywhere, but doesn't resize
#PNG	        png	          Can be used anywhere, but doesn't resize
#WMF	        win.metafile	Windows only; best choice with Word; easily resizable
#PDF	        pdf	          Best choice with pdflatex; easily resizable
#Postscript  postscript	  Best choice with latex and Open Office; easily resizable
