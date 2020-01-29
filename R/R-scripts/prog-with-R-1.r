# set working directory
setwd("~/study/R/R-scripts/")

# read data as .csv file
data = read.csv(file="~/study/R/R-scripts/data/inflammation-01.csv", header=F)

# print the first six rows
head(data)
# vector of data's nrow, ncolumn
dim(data)
# print type of structure only
class(data)

# assign data's first row to patient1
patient1 = data[1,]
# value of max of patient1
max(patient1)

# Standard Deviation of data's 7th column 
sd(data[, 7])

# summarise data, data-frame
summary(data)

# MARGIN==1; by row
# MARGIN==2; by column
# apply()
avg_patient_inflammation = apply(data, MARGIN=1, mean)
avg_patient_inflammation

animal = c("m","o","n","k","e","y")
animal[1:3]; animal[4:6]

# problem
# data를 이용해서 밑을 풀어보자
# 첫번째 5줄에 매 두번째 환자의 측정에 문제가 있었다 가정하자, 이것은
# 원래 측정값보다 2배 크게 측정됐다. 
# hint ? seq

# columns are days
# rows are patients

# length of rows and columns
leng_rc = dim(data)

# in C/C++, we do it with for or wihle loops
# but in R, do it with vectors

# seq(from, to, by)
which_patients = seq(2, leng_rc[1] , 2)
which_days = seq(1,5)
data2 = data

# to check vector's factor
dim(data2[which_patients, which_days])

# == data2[v] /= 2
data2[which_patients, which_days] <- data2[which_patients, which_days] / 2

# from 1 to 5 day, we wanna get mean of those days
days = 1:5
apply(data[days,], MARGIN=1, mean)
# getting mean of 1 to 10 patients
patients = 1:10
apply(data[,patients], 2, mean)

# Getting mean of eveb days 
apply(data[ ,seq(2,length_rc[2], 2)], MARGIN=2, mean) 
plot(data[ ,seq(2,length_rc[2], 2)])

# vector of means of whole days
avg_day_inflammation = apply(data, 2, mean)

# matrix형태나 data-frame형태가아닌 하나의 벡터형식으로 나타내야해
# we need to give a vector of numbers corresponding to the aveage
plot(avg_day_inflammation)

# max value
max_day_inflammation = apply(data, 2, max)
plot(max_day_inflammation)

# min value
min_day_inflammation = apply(data, 2, min)
plot(min_day_inflammation)

# standard deviation
sd_day_inflammation = apply(data, 2, sd)
plot(sd_day_inflammation)
