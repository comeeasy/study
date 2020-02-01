setwd("~/study/R/R-scripts/")
library(tidyr)

data = read.csv(file="~/study/R/R-scripts/data/inflammation-01.csv", header=F)
head(data)

data[,16:18]

# Defining a Function
fahrenheit_to_celsius = function(tmp_F) {
    tmp_C = (tmp_F-32)*5/9
    return(tmp_C)
}

fahrenheit_to_celsius(212)

celsius_to_kelvin = function(tmp_C) {
    tmp_K = tmp_C + 273.15
    return(tmp_K)
}

celsius_to_kelvin(0)

best_parctice = c("Write", "program", "for", "people", "not", "computers")
asterisk = "***"

highlight = function(content, wrapper) {
    new_vector = c(wrapper, content, wrapper)
    return(new_vector)
}

highlight(best_parctice, asterisk)

dry_principle = c("Don't", "repeat", "yourself", "or", "others")

edges = function(sentence) {
    return(tmp=c(sentence[1], sentence[length(sentence)]))
}
edges(dry_principle)

# write a code to center a dataset around a particular midpoint

# after writing a function there is left one thing
# we have to write a documentation for our function to remind ourselves later
# what the fuck is this
center = function(data, midpoint) {
    
    # return a new vector contating the original data
    # centered around the midpoint
    # Example: center(c(1, 2, 3), 0) -->> c(-1, 0, 1)
    
    new_data = (data-mean(data))+midpoint
    return (new_data)
}

z = c(0, 0, 0, 0)
center(z, 3)

dat = read.csv(file="~/study/R/R-scripts/data/inflammation-01.csv", header=F)
centered = center(dat[,4], 0)
head(centered)
dat[,4]

# Test the function
# get range (=3)
min(dat[,4])
max(dat[,4])
# get standart deviation (=1.067628)
sd(dat[,4])

# origin data's range, sd will be same with a centered dataset
# get range (=3)
min(centered)
max(centered)

# get sd (=1.067628)
sd(centered) 

# sometimes, a very small difference could be not ot detected
# so that, R has a useful function

all.equal(sd(dat[,4]), sd(centered))
# output : TRUE

# Write a function called "analyze" that takes a filename as an argument and display
# the three graphs produced in the privious lesson (average, min, max)
# 'analyze(filename) should produce the graphs already shown, while
# 'analyze(filename2) should produce corresponding graphs for the second data set.
# Be sure to document your function with comments.

analyze = function(file) {
    data = read.csv(file, header=F)
    
    # assigning vectors by apply function
    avg_by_col = apply(data, 2, mean)
    min_by_col = apply(data, 2, min)
    max_by_col = apply(data, 2, max)
    
    # use function 'plot' in library 'tidyr'
    plot(avg_by_col)
    plot(min_by_col)
    plot(max_by_col)
}

analyze("~/study/R/R-scripts/data/inflammation-01.csv")
analyze("~/study/R/R-scripts/data/inflammation-02.csv")

# Write a function 'rescale' that takes a vector as input and returns a
# corresponding scaled to lie in the range 0 to 1.
# vector V should be (v-L)/(H-L) ( L==min, H==max of v)
# test that your rescale function is working properly using, min, max, plot
rescale = function(filename) {
    data = read.csv(file=filename, header=F)
    v_min=min(data); v_max=max(data)
    tmp = (data-v_min)/(v_max-v_min)
    return(tmp)
}

rescaled=rescale("~/study/R/R-scripts/data/inflammation-01.csv")
head(rescaled)
min(rescaled)
max(rescaled)

rescale = function(v, lower=0, upper=1) {
    L = min(v)
    H = max(v)
    result = (v-L)/(H-L)*(upper-lower)+lower
    return(result)
}

head(rescale(data, 10, 100))
