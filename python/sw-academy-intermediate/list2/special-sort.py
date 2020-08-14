# -*- coding : utf-8 -*-
# special-sort.py

'''
보통의 정렬은 오름차순이나 내림차순으로 이루어지지만, 이번에는 특별한 정렬을 하려고 한다.
N개의 정수가 주어지면 가장 큰 수, 가장 작은 수, 2번째 큰 수, 
2번째 작은 수 식으로 큰 수와 작은 수를 번갈아 정렬하는 방법이다.
예를 들어 1부터 10까지 10개의 숫자가 주어지면 다음과 같이 정렬한다.
 
10 1 9 2 8 3 7 4 6 5

[입력]

첫 줄에 테스트 케이스 개수 T가 주어진다.  1<=T<=50
다음 줄에 정수의 개수 N이 주어지고 다음 줄에 N개의 정수 ai가 주어진다. 10<=N<=100, 1<=ai<=100

[출력]

각 줄마다 "#T" (T는 테스트 케이스 번호)를 출력한 뒤, 특별히 정렬된 숫자를 10개까지 출력한다.
'''

# 정렬해서 앞 뒤로 인덱스를 바꿔가면서 append 하면 돼

import sys
sys.stdin = open('sample_input3.txt', 'r')

T = int(input())
for i in range(1, T+1) :
    N = int(input())
    nums = map(int, input().split())
    
    # list 정렬
    nums = sorted(nums)
    #print(nums)
    
    newList = []
    # 비교하는 가장 앞의 인덱스와 마지막 인덱스가 
    # 올바르게 있다면
    #   (i)   (N-1-i)
    #1 2 3 4 5  6 7 8
    # 앞의 idx 는 2 이면 큰 수를 가리키는 idx는 7이다 
    
    # 5개까지 출력하므로 5번만 반복하여 넣고 출력하면됨
    
    for idx in range(5) :
        newList.append(nums[N-1-idx])
        newList.append(nums[idx])

    print('#{0} {1}'.format(i ,' '.join(map(str ,newList))))