import time

name = input()
age  = int(input())

print("{0}(은)는 {1}년에 100세가 될 것입니다.".format(name, 80 + \
        time.localtime().tm_year))