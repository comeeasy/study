# 피보나치 수열 출력

###################################################

def fib(num) :
    fib_list = [1, 1]
    for i in range(2, num) :
        fib_list.append(fib_list[i-2] + fib_list[i-1])
        
    return fib_list
    
###################################################

num = int(input())
print(fib(num))

###################################################