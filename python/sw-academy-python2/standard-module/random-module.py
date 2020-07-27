from random import random, uniform, randrange, choice, choices, sample, shuffle

# random() : 0.0 <= N <= 1.0 사이의 값 return
print("random() => {0}".format(random()))

# uniform(start, end) : start <= N <= end 사이의 값 return
print("uniform({0}, {1}) => {2}".format(1.0, 10.0, uniform(1.0, 10.0)))

# randrange(start, stop, step) : start <= 정수 < end random 값을 return
# choice(list) : list의 값들 중 임의의 값을 return
data = list(range(100))
print(choice(data))

# choices(list, k=n) : list에서 k=n개의 값들을 임의 return
# !!!!!! 복원 추출 기능을 가짐 !!!!!!!!!!!!
print(sorted(choices(data, k=30)))
# 중복되는 값이 존재함

# sample(list, k=n) : list에서 k=n개의 비복원 추출 기능을 가진 함수
print(sorted(sample(data, k=30)))
# 중복되는 값이 없음

# shuffle(list) : list를 임의로 섞는 함수
shuffle(data)
print(data)