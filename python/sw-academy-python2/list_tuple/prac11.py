'''
다음의 결과와 같이 사용자로부터 콤마(,)로 구분해 여러 원의 반지름을 입력 받아
이들에 대한 원의 둘레를 계산해 출력하는 프로그램을 작성하십시오.
'''
# for pi
import math as m

# convert strlist to numlist
num = input()
num_list = [ch for ch in num if ch != ' ']
# print(''.join(num_list))
num_list = list(map(int, num.split(',')))
# print(num_list)

# calculate circumference
circumferences = list(map(float, [format(radius * m.pi * 2, '.2f') for radius in num_list]))
cf_str = str(circumferences)
print(cf_str[1:len(cf_str)-1])
