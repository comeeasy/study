'''
def solution(n):
    n = int(n)
    digits = []
    
    while n :
        digit = n % 3

        #print("n: {0}\ndigit: {1}\n".format(n, digit))

        if digit == 1   : 
            digits.append('1')
            n -= 1
        elif digit == 2 : 
            digits.append('2')
            n -= 2
        elif digit == 0 : 
            digits.append('4')
            n -= 3

        n //= 3
        
    
    digits.reverse()
    digits = ''.join(digits)
        
    return digits
'''

'''
def solution(n) :
    num = ['1', '2', '4']
    answer = ''

    while n:
        n -= 1
        answer = num[n % 3] + answer
        n //= 3

    return answer

'''
