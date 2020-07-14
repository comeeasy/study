# -*- coding: utf-8 -*-

# 1 - 100 사이의 숫자 중 3의 배수 총합 출력

total = 0

for i in range(3, 101, 3) :
    total += i
print("1부터 100사이의 숫자 중 3의 배수의 총합: %d" % total )