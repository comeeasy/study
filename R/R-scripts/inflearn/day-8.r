# data read, crawling
# - read.table(file, choose(), header=TRUE) : 내가 창을 선택할 수 있음
# header는 name, age.. 등의 인덱스를 의미

# header는 한줄만 존재하기 때문에 열에는 이름이 들어가면 곤란하다
# 전차리가 굉장히 중요하다 ㅠㅠ
# .csv 파일은 ',' 로 구분되기 때문에 sep=","을 꼭 넣어줘야한다
lungdata <- read.table(file.choose(), sep=",", header=T)

# 첫 6줄 출력
head(lungdata)
# 뒤 6줄 출력
tail(lungdata)

# lungdata의 데이터 타입
str(lungdata)

min(lungdata$male)
max(lungdata$female)