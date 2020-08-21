import sys
sys.stdin = open('sample_input3.txt', 'r')

T = int(input())
for testCase in range(1, T+1) :
    str = list(input())
    
    toRemove = -1    
    while True :
        if toRemove >= 0 :
            str.pop(toRemove)
            str.pop(toRemove) 
        
        toRemove = -1
        for i in range(len(str)-1) :
            if str[i] == str[i+1] :
                toRemove = i
        
        if toRemove == -1 :
            answer = len(str)
            break    
    
    print('#{0} {1}'.format(testCase, answer))