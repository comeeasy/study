hi = paste("Hi", "Jack")

# default: sep=" "
paste("jac", "k", sep="")
paste(hi, "what's up", sep=", ")

# 1학년 1반 부터 10반까지 출력
paste("1", 1:10, sep="-")
a = paste("The value of 'pi is", pi, ", endless!!")

# 따옴표 출력하고 싶지 않아
noquote(a)
print(a, quout=F)

# default dataset
mtcars
# 행,열의 이름만을 출력
rownames(mtcars)
colnames(mtcars)

cars = rownames(mtcars)
nchar(cars)

# 가장 긴 이름을 갖는것을 찾아 그 인덱스를 리턴해줘
which(nchar(cars)==max(nchar((cars))))
