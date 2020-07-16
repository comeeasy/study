# 소수 판별 프로그램
# "소수입니다", "소수가 아닙니다" 출력

#################################################

def is_prime(num) :
    if num < 2 : 
        return False
    
    for i in range(2, num) :
        if num % i == 0 :
            return False
    return True

#################################################

num = int(input())
if is_prime(num) :
    print("소수입니다.")
else :
    print("소수가 아닙니다.")

#################################################