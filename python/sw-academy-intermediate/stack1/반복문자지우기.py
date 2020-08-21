# 반복문자지우기.py

'''
문자열 s에서 반복된 문자를 지우려고 한다. 지워진 부분은 다시 앞뒤를 연결하는데, 
만약 연결에 의해 또 반복문자가 생기면 이부분을 다시 지운다.
반복문자를 지운 후 남은 문자열의 길이를 출력 하시오. 남은 문자열이 없으면 0을 출력한다.
 
다음은 CAAABBA에서 반복문자를 지우는 경우의 예이다.
 
CAAABBA 연속 문자 AA를 지우고 C와 A를 잇는다.
CABBA 연속 문자 BB를 지우고 A와 A를 잇는다.
CAA 연속 문자 AA를 지운다.
C 1글자가 남았으므로 1을 리턴한다.

[입력]
 
첫 줄에 테스트 케이스 개수 T가 주어진다.  1≤T≤ 50
다음 줄부터 테스트 케이스의 별로 길이가 1000이내인 문자열이 주어진다.

[출력]
 
#과 1번부터인 테스트케이스 번호, 빈칸에 이어 답을 출력한다.
'''

import sys
sys.stdin = open('sample_input3.txt', 'r')

T = int(input())
for testCase in range(1, T+1) :
    str = list(input())
    stack = []
    
    while True :
        # 매 수행마다 stack에 넣어둔 중복되지 않은 문자들을
        # str 앞에다가 넣어줄거임
        while stack :
            str.insert(0, stack.pop(-1))
        
        print(str)
        
        # 모든 문자에 대하여 다음 문자를 비교한다
        for i in range(len(str)-1) :
            # 만약 다음 문자와 다르다면 i번쨰 문자를 stack에 넣어
            # 다음에 시행할 때 앞에 오도록 해둔다
            if str[i] != str[i+1] :
                stack.append(str[i])
            # 그렇지 않으면 해당 두 문자를 제거하고
            # 다시 위로 돌아가 stack에 넣어 두었던 두 문자를
            # str 앞에 붙여서 다시 조사한다.
            else :
                str.pop(i)
                str.pop(i)
                
                print(str)
                print()
                break
        
        # str에 아무것도 남아있지 않으면,
        # 즉 마지막 문자 하나만 남았다면,
        # stack에 넣어둔 요소들은
        # 모두 다음 문자와 중복되지 않으므로 stack의 크기가 답이다
        if len(str) == 1 :
            answer = len(stack)    
    
    print('#{0} {1}'.format(testCase, answer))
    