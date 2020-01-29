y = character()
y
length(y)
y2 = ""
class(y2)
length(y2)

y = c("3", "awe", "som", "e")

# char[10] y;
# 와 같음
y = character(10)
y[3] = "third"

# 10개를 할당했는데 12 index에 값을 넣었으므로 y[11] = NA 가 되었다.
y[12] = "twelves"
y[11] = "eleventh"
y


n=3
m="3100"

is.character(n)
is.character(m)


class(n)
class(m)

# Casting
as.character(n)
as.numeric(m)

# column은 하나의 데이터타입만을 가질 수 있기때문에 보통 char 로 바뀜
# char > numeric > boolean
t2 = c(1:5, "a")
class(t2)

t3 = c(1:3, T, F)

df1 = data.frame(n=c(0,1,2, "A"), letters=c("a","b","c","d"))
df1
