# palindrome.py

'''
ABBA처럼 어느 방향에서 읽어도 같은 문자열을 회문이라 한다.
NxN 크기의 글자판에서 길이가 M인 회문을 찾아 출력하는 프로그램을 만드시오.
회문은 1개가 존재하는데, 가로 뿐만 아니라 세로로 찾아질 수도 있다.
 
[입력]
 
첫 줄에 테스트 케이스 개수 T가 주어진다.  1≤T≤50
다음 줄부터 테스트케이스의 첫 줄에 N과 M이 주어진다. 10≤N≤100, 5≤M≤N
다음 줄부터 N개의 글자를 가진 N개의 줄이 주어진다.

[출력]
 
각 줄마다 "#T" (T는 테스트 케이스 번호)를 출력한 뒤, 답을 출력한다.
'''

import sys
sys.stdin = open('sample_input1.txt', 'r')

# 회문인지 검사하는 함수 정의
def is_palindrome(str) :
    return str == str[::-1]

T = int(input())
for testCase in range(1, T+1) :
    # N*N 크기의 문자 맵에서 M크기의 회문을 찾으면 된다.
    N, M = map(int, input().split())
    # string들을 저장할 matrix 선언
    strMat = []
    # 각 row별로 입력 받아서 list에 저장
    # dimention == 2
    for i in range(0, N) :
        strMat.append(input())
       
    #print(strMat)  
        
    # row 별로 검사
    for rowIndex in range(0, N) :
        
        #print('===========================================')
        #print('rowIndex: {0}'.format(rowIndex))
        #print('===========================================')
        
        for startIndexToCheck_m_sizeString in range(0, N-M+1) :
            # 모든 케이스의 str을 조사
            str = strMat[rowIndex][startIndexToCheck_m_sizeString:startIndexToCheck_m_sizeString+M]
            
            #print('str[{0}:{1}]:'.format(startIndexToCheck_m_sizeString, startIndexToCheck_m_sizeString+M-1), str)
            
            # 회문은 하나만 존재한다고 보장하므로 바로 break
            if is_palindrome(str) :
                #print('!!!!!!!!!!!!! {0} !!!!!!!!!!!!!!!!'.format(str))
                answer = str
                break
            
    # column 별로 검사, row에서 회문을 찾지 못했을 경우만 진행
    # column은 slicing하기 어려워서 for문으로 일일히 str을 복사해주어야한다.
    for columnIndex in range(0, N) :
        #print('===========================================')
        #print('columnIndex: {0}'.format(columnIndex))
        #print('===========================================')            
            
        for startIndexToCheck_m_sizeString in range(0, N-M+1) :
            str = ''.join([strMat[i][columnIndex] for i in range(startIndexToCheck_m_sizeString, \
                            startIndexToCheck_m_sizeString + M)])
            
            #print('str[{0}:{1}]:'.format(startIndexToCheck_m_sizeString, startIndexToCheck_m_sizeString+M-1), str)

            if is_palindrome(str) :
                #print('!!!!!!!!!!!!! {0} !!!!!!!!!!!!!!!!'.format(str))
                answer = str
                break
    
    print('#{0} {1}'.format(testCase, answer))