# <rolling dice>

# day-9
# p = 1/n, dim = 6

# random uniform
# runif()를 100번 시행할건데 0이상 1이하의 값이 나오니까 6을 곱해주고
# 반올림을 하기 위해 ceiling()을 사용함
roll = 1000000
n = 4
dice <- ceiling(runif(roll)*n)

# 1, 2, .. , 6 이 각각 몇번씩 나왔는지 보여주는 함수
my_table = table(dice)

# 막대 그래프 그려주는 함수
barplot(my_table)
