# 정규분포 ~ N(80, 10^2)

# x's range 
# length: 몇 개로 쪼갤거야
x = seq(40, 120, length=300)

# normal disribution
y = dnorm(x, mean=80, sd=10)
# x축이 y의 갯수는 300임
plot(y)
# x축에 x가 들어가 범위가 1~120임
plot(x, y)
# scatter plot이 아니라 선으로 그려줌
plot(x, y, type="l")
# 선을 빨강색으로 칠해줌
plot(x, y, type="l", col="red")

# 기존에 그려진 plot위에 새로운 그래프를 그림
lines(x, dnorm(x, mean=80, sd=20), col="blue")
lines(x, dnorm(x, mean=80, sd=5), col="yellow")

# probability
pnorm
# 쿼터
qnorm
dnorm
# random number 생성
rnorm

pnorm(75, mean=80, sd=10)-pnorm(65, mean=80, sd=10)
pnorm(60, mean=80, sd=10)
# 오른쪽에서부터 계산 T-> 왼쪽부터 계산, default=T
pnorm(60, mean=80, sd=10, lower.tail=F)

# 확률이 0.01일 지점을 왼쪽에서부터 구해서 return
# cut off 지점이라 하네
qnorm(0.01, mean=80, sd=10)
# output: 56.73652

pnorm(80, mean=80, sd=10)-pnorm(56.73652, mean=80, sd=10)
