def foo(i) :
    to_ret = ""
    digits = 0

    while(i != 0) :        
        i *= 2
        
        if i >= 1 :
            to_ret += '1'
            i -= 1
        else :
            to_ret += '0'
            
        digits += 1
        
        if digits > 12 :
            return 'overflow'

    return to_ret
  
    
T = int(input())

for i in range(1, T+1) :
    num = float(input())
    answer = foo(num)

    print("#{0} {1}".format(i, answer))