x = c(1:10)

x1 = as.integer(x)
x2 = as.numeric(x)
x3 = as.factor(x)
x4 = as.character(x)

str(x1)
summary(x1)
str(x2)
summary(x2)
str(x3)
summary(x3)
str(x4)
summary(x4)

# 데이터가 너무 방대한 경우, 필요 없이 긴 연산을 해야될 때가 있습니다.
# 이런 경우에 무작위 추출을 통해 데이터의 특성은 살리면서, 연산속도를 낮추는 경우가 종종
# 필요합니다.

# replace: (=T: 복원 추출), (=F: 비복원 추출)
? sample
sample(x=1:45, size=6, replace=F)

# sample()의 경우 결과값을 고정시켜야할 때가 있다. 이런 경우 
# set.seed(seed, kind=NULL, normal.kind=NULL) 로 결과를 고정한다.
set.seed(1234)
sample(1:45, 6, replace=F)

for(i in 1:5)   {
    print(i)
}

? c
LIST = seq(from=1, to=30, by=2)
SPACE = c()
for(i in LIST) {
    SPACE = c(LIST)
}

SPACE

if(7 %in% SPACE) {
    print("TRUE")
} else {
    print("FALSE")
}


analyze = function(filename) {
    # PLots the average , min, max inflammation over time.
    # Input is string of a csv file.
    
    dat = read.csv(filename)
    avg_day_inflammation = apply(dat, MARGIN=2, mean)
    max_day_inflammation = apply(dat, MARGIN=2, max)
    min_day_inflammation = apply(dat, MARGIN=2, min)
    
    plot(avg_day_inflammation)
    plot(max_day_inflammation)
    plot(min_day_inflammation)
}

analyze("~/study/R/R-scripts/data/inflammation-01.csv")

sentence = c("let", "the", "computer", "do", "the", "work")

print_words = function(sentence) {
    for(word in sentence) {
        print(word)
    }
}

print_words(sentence[-6])

# 여러개의 파일을 찾아 list로 만드는 함수
list.files(path="~/study/R/R-scripts/data", pattern="inflammation", full.names=T)

filenames = list.files(path="~/study/R/R-scripts/data", pattern="inflammation-[0-9]{2}.csv", full.names=T)
for(f in filenames) {
    print(f)
    analyze(f)
}

analyze_all = function(dir_name) {
    list = list.files(dir_name, full.names=T)
    for(f in filenames) {
        print(f)
        analyze(f)
    }
}

analyze_all("~/study/R/R-scripts/data")

# redirects all plots into a pdf file
pdf("inflammation-01.pdf")
analyze("./data/inflammation-01.csv")
# stop R from redirecting plots with the function dev.off()
dev.off()
# check redirecting status
dev.cur()

plot_dist = function(x, threshold, use_boxplot=F) {
    if(use_boxplot == TRUE) {
        if(length(x) > threshold) {
            boxplot(x)
        } else {
            stripchart(x)
        }
    } else {
        hist(x)
    }
}

dat = read.csv("./data/inflammation-01.csv", header=F)
plot_dist(dat[,10], threshold=10)

# find the file contatining the patient with the highest average inflammation score.
# print the file name, the patient number(row number) and the value of the max avg inflammation score

a = c(1, 2, 3)
a.mean = mean(a)
a.mean

filenames = list.files(path="./data", pattern="inflammation-[0-9]{2}.csv", full.names=T)
filename_max = ""
patient_max = 0
avg_inf_max = 0
for(f in filenames) {
    dat = read.csv(file=f, header=F)
    dat.means = apply(dat, 1, mean)
    for(patient_index in 1:length(dat.means)) {
        patient_avg_inf = dat.means[patient_index]
        if(avg_inf_max < patient_avg_inf) {
            avg_inf_max = patient_avg_inf
            filename_max = f
            patient_max = patient_index
        }
    }
}
print(filename_max)
print(patient_max)
print(avg_inf_max)

analyze = function(filename, output=NULL) {
    if(!is.null(output)) {
        pdf(output)
    }
    dat = read.csv(file=filename, header=F)
    avg = apply(dat, 2 ,mean)
    max = apply(dat, 2, max)
    min = apply(dat, 2, min)
    
    plot(avg, type="l"); plot(max, type="l"); plot(min, type="l")
    if(!is.null(output)) {
        dev.off()
    }
}

analyze("./data/inflammation-01.csv", output="./result/inflammtion-01.pdf")

f = "inflammation-01.csv"
# subtitute
sub("csv", "pdf", f)

file.path("./result", sub("csv", "pdf", f))

analyze_all = function(pattern) {
    data_dir = "./data"
    result_dir = "./result"
    filenames = list.files(path=data_dir, pattern=pattern)
    for(f in filenames) {
        pdf_name = file.path(result_dir, sub("csv", "pdf", f))
        analyze(file.path(data_dir, f), output=pdf_name)
    }
}

analyze_all("inflammation.*csv")

install.packages("installr")
library(installr)
