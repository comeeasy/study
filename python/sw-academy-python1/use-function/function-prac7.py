############################################
'''
    다음과 같이 팩토리얼을 구하는 함수를 정의해 입력된 숫자에 대한
    팩토리얼 값을 구하는 프로그램을 작성하십시오.
'''
############################################

def factorial(num) :
    if num == 1 :
        return 1
    elif num == 0 :
        return 1
    elif num < 0 :
        return 1
    else :
        return num * factorial(num-1)

############################################

num = int(input())
print(factorial(num))

############################################