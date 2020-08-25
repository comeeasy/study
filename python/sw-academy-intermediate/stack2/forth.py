# forth.py

'''
Forth라는 컴퓨터 언어는 스택 연산을 기반으로 하고 있어 후위 표기법을 사용한다. 
예를 들어 3+4는 다음과 같이 표기한다.
 
3 4 + .
 
Forth에서는 동작은 다음과 같다.
 
숫자는 스택에 넣는다.
연산자를 만나면 스택의 숫자 두 개를 꺼내 더하고 결과를 다시 스택에 넣는다.
‘.’은 스택에서 숫자를 꺼내 출력한다.

Forth 코드의 연산 결과를 출력하는 프로그램을 만드시오. 
만약 형식이 잘못되어 연산이 불가능한 경우 ‘error’를 출력한다.

다음은 Forth 연산의 예이다.

4 2 / .
2

4 3 - .
1

[입력]
 
첫 줄에 테스트 케이스 개수 T가 주어진다.  1≤T≤50
다음 줄부터 테스트 케이스의 별로 정수와 연산자가 256자 이내의 연산코드가 주어진다. 
피연산자와 연산자는 여백으로 구분되어 있으며, 코드는 ‘.’로 끝난다.
나눗셈의 경우 항상 나누어 떨어진다.

[출력]

#과 1번부터인 테스트케이스 번호, 빈칸에 이어 계산결과를 정수로 출력하거나 또는 ‘error’를 출력한다.
'''

# push, pop 정의
def push(stack, item) :
    stack.append(item)

def pop(stack) :
    # if stack is empty
    if not stack :
        return None
    return stack.pop(-1)

# n1 op n2 의 연산을 시행한다.
# ex) 1 + 2 = operation(1, 2, +)
def operation(n1, n2, op) :
    if op == '+' :
        return n1 + n2
    elif op == '-' :
        return n1 - n2
    elif op == '*' :
        return n1 * n2 
    # 0 으로 나누어지지 않는 것을 보장하므로
    elif op == '/' :
        return int(n1 / n2)
    else :
        print('wrong operator')
        return None

def is_int(str) :
    integers = list('0123456789')
    
    # 만약 str의 모든 원소들이 integers라면 return 1
    # 아니라면 return 0
    
    # 음수인 경우
    # - 를 제외한 나머지가 int이면 됨 이떄 -를 제거 했으므로
    # 양수처럼 여겨짐
    if str[0] == '-' :
        return is_int(str[1:])
    # 양수인 경우
    else :    
        isIntegerList = [True if ch in integers else False for ch in str]
        return all(isIntegerList)
        
import sys
sys.stdin = open('sample_input1.txt', 'r')        
        
T = int(input())
for testCase in range(1, T+1) :
    str = input().strip().split()
    stack = []
    
    for ch in str :
        
        #print('\nch: {0}'.format(ch))
        
        # 정수라면
        if is_int(ch) :
            push(stack, int(ch))
            
            #print('{0} is pushed and\n stack: {1}'.format(int(ch), stack))
            
        # 정수가 아니라면 operator or 출력
        else :
            # 출력 명령이 아니라면 연산
            if ch != '.' :
                # stack에서 두 개의 값들을 pop 받고 
                # 이들이 모두 None값이 아니라면, 즉 2개의 정수가 pop 되었다면
                n2 = pop(stack)
                n1 = pop(stack)
                # 계산하여 다시 stack에 push
                if n1 != None and n2 != None :
                    push(stack, operation(n1, n2, ch))
                    
                    #print('op: {0} and {1} {2} {3} is pushed\nstack: {4}'.format(ch, n1, ch, n2, stack))
                    
                # 연산할 숫자가 없으므로 error
                else :
                    answer = 'error'
                    break
                    
            # 출력 연산이라면 계산이 모두 끝난것이다
            # 이때 stack에 숫자가 남아있으면 error 
            else :
                if len(stack) == 1 :
                    answer = pop(stack)
                else :
                    answer = 'error'
                                    
                
                
    print('#{0} {1}'.format(testCase, answer))
   