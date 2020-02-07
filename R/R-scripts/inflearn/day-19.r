setwd("~/study/R/R-scripts/")

x = 1:10
y = x-1
# plot needs parameter which is matrix
plot(y~x)
# dotchart needs vector
dotchart(y)

# given data as default
mtcars

plot(mtcars$mpg)
length(rownames(mtcars))

# mpg column of mtcars
# descrete
dotchart(mtcars$mpg)
# apply row names
dotchart(mtcars$mpg, labels=row.names(mtcars))
# manipulate font size
dotchart(mtcars$mpg, labels=row.names(mtcars), cex=0.7)

# assign mtcars by acending order of mpg category
ascend_by_mpg = mtcars[order(mtcars$mpg),]
# factorize
ascend_by_mpg$cyl = factor(ascend_by_mpg$cyl)

dotchart(ascend_by_mpg$mpg, labels=row.names(ascend_by_mpg), cex=0.7)

ascend_by_mpg$color[ascend_by_mpg$cyl==4] = "blue"
ascend_by_mpg$color[ascend_by_mpg$cyl==6] = "green"
ascend_by_mpg$color[ascend_by_mpg$cyl==8] = "red"

# color 
dotchart(ascend_by_mpg$mpg, labels=row.names(ascend_by_mpg), cex=0.7, color=ascend_by_mpg$color)

# grouping
# only numeric variables can be delivered as parameters
# to groups parameter
dotchart(ascend_by_mpg$mpg, labels=row.names(ascend_by_mpg), cex=0.7, groups=ascend_by_mpg$cyl, color=ascend_by_mpg$color)

# naming
dotchart(ascend_by_mpg$mpg, labels=row.names(ascend_by_mpg), 
         cex=0.7, groups=ascend_by_mpg$cyl, 
         color=ascend_by_mpg$color, main="Milage depending on cylinders")

# xlab argument: name x axis
dotchart(ascend_by_mpg$mpg, labels=row.names(ascend_by_mpg), 
         cex=0.7, groups=ascend_by_mpg$cyl, 
         color=ascend_by_mpg$color, main="Milage depending on cylinders"
         , xlab="Milage Per Gallon")
