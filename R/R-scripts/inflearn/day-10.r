library(tidyr)
library(dplyr)

member <- data.frame(family=c(1,2,3), namef=c("a", "b", "c"), agef=c(30, 40, 23), namem=c("d", "e", "f"), agem=c(44, 53, 25))
member

# 선택하지 않은 column들은 원래대로 저장하고, 선택된 column들은 
# key - value 로 묶어 하나의 기다란 스트림을 만들어냄
# gather(data.frame data, key="key", value="value", column columns)

# Warning이 뜨는 이유는 말 그래도 주의하라는 의미
a <- gather(member, key, value, namef:agem)

# separate(data-frame data, column column's-name, to-separate-column c("col1", "col2", ...)), 
#    argument()<숫자를 넣으면 각 컬럼의 이름의 앞에서 자를지(양수), 뒤에서 자를지 (음수)를 결정> )

# 밑의 함수는 a data-frame에서 key column을 "variable", "type" 으로 분류할건데 뒤에서 char 1개씩 잘라서 나눌거야
b <- separate(a, key, c("variable", "type"), -1)
b

new <- spread(b, variable, value)

# filter 말그래도 필터함수
filter(new, type=="f")
filter(new, age>30)

# pip line
# member 객체는 local var로 여겨진다
member %>%
    gather(key, value, namef:agem) %>%
    separate(key, c("variable", "type"), -1) %>%
    spread(variable, value)







