# Binomial distribution
# hypergeometric

# dbinom: sampling with replacement
# dhyper: sampling without replacement

# if num of total w, b balls is large enough, 
# dhyper is converge to  dbinom

# given probability is 0.5
# get prob of 3 success case while 10 trials by Bernoui trial
dbinom(3, 10, 0.4)

# population size, sample size are exist
# get prob of there are 3 men while
# 4 men, 6women exist, draw 10 trials

? dhyper
# dhyper(x, m, n, k, ..)
# x: vector of quantiles representing 
#   the number of white balls drawn without replacement 
#   from an urn which contains both black and white balls.
# m: the num of white balls
# n: the num of black balls
# k: the num of balls drawn from the urn(pick up the ball without replacement)
dhyper(3, 4, 6, 10)
dhyper(3, 4, 6, 6)
dhyper(3, 80, 120, 10)

# depending on ascinding num of m+n, dhyper is converge
# to dbinom

dbinom(3, 10, 0.4)
# 0.2149908

a=1000
result = numeric()
for(i in 1:a) {
  result[i] = dhyper(3, 4*i, 6*i, 10)
}

plot(result[2:1000], type="l")
# add a line upon plot 
# h: y value which satisfy y=h
# v: x value which satisfy x=v
abline(h=dbinom(3,10,0.4), col="red")

plot(result[2:1000]-dbinom(3,10,0.4), type="l")
abline(h=0.05, v=20, col=c("green", "red"))

?abline
