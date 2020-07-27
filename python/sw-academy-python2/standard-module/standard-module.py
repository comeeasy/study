'''
    모듈은 c에서 헤더 파일과 같은 역할을 하는듯
    import랑 #include랑 비슷하다고 생각하면 될듯

    import 모듈명
    와 같이 모듈을 선언
'''

# example 1
import math

# 함수들
print("math.radians(90) = {0}".format(math.radians(90)))

print("math.ceil(3.2) = {0}".format(math.ceil(3.2)))        # 4
print("math.floor(3.2) = {0}".format(math.floor(3.2)))      # 3

# 변수
print("math.pi = {0}".format(math.pi))

'''
    import 모듈명 as 별칭
    ex) import math as m
    m.pi, m.ceil(), m.floor()

    from 모듈명 import 문
    ex) from 모듈명 import * (와일드 카드 느낌ㅋㅋ)
        -> math 모듈이 가진 함수들을 직접 호출 
        -> C++ 에서 using namespace std 같은 느낌
'''

# example 2
from math import *                          # math 모듈의 모든 함수를 우선적으로 사용
from math import radians, ceil, floor, pi   # math 에서 다음 함수, 멤버들만 우선적으로 사용

print("radians(90) = {0}".format(radians(90)))

print("ceil(3.2) = {0}".format(ceil(3.2)))  
print("floor(3.2) = {0}".format(floor(3.2)))  

print("pi = {0}".format(pi))
