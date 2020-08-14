# -*- coding: utf-8 -*-
# binary-search.py

'''
코딩반 학생들에게 이진 탐색을 설명하던 선생님은 이진탐색을 연습할 수 있는 게임을 시켜 보기로 했다.
짝을 이룬 A, B 두 사람에게 교과서에서 각자 찾을 쪽 번호를 알려주면, 
이진 탐색만으로 지정된 페이지를 먼저 펼치는 사람이 이기는 게임이다.
예를 들어 책이 총 400쪽이면, 검색 구간의 왼쪽 l=1, 오른쪽 r=400이 되고, 
중간 페이지 c= int((l+r)/2)로 계산한다.
찾는 쪽 번호가 c와 같아지면 탐색을 끝낸다.

A는 300, B는 50 쪽을 찾아야 하는 경우, 다음처럼 중간 페이지를 
기준으로 왼쪽 또는 오른 쪽 영역의 중간 페이지를 다시 찾아가면 된다.

책의 전체 쪽수와 두 사람이 찾을 쪽 번호가 주어졌을 때, 
이진 탐색 게임에서 이긴 사람이 누구인지 알아내 출력하시오. 비긴 경우는 0을 출력한다.

[입력]
 
첫 줄에 테스트 케이스 개수 T가 주어진다.  1<=T<=50
테스트 케이스 별로 책의 전체 쪽 수 P, A, B가 찾을 쪽 번호 Pa, Pb가 차례로 주어진다. 1<= P, Pa, Pb <=1000
 
[출력]
 
각 줄마다 "#T" (T는 테스트 케이스 번호)를 출력한 뒤, A, B, 0 중 하나를 출력한다.
'''

import sys
sys.stdin = open('sample_input2.txt', 'r')

# 두 함수 모두 찾는데 얼마나 걸렸는지의 횟수를 return할 것이다

# A 는 오른쪽 먼저 탐색
def A_bin_search(low, high, Pa) :
    if low < high-1 :
        A_bin_search.count += 1
        center = int((low + high) / 2)
        
        #print('low: {0} high:" {1} center: {2} Pa: {3}'.format(low, high, center, Pa))
        
        if Pa == center :
            return 
        else :
            A_bin_search(center, high, Pa)
            A_bin_search(low, center, Pa)
    else :
        return

# B 는 왼쪽 먼저 탐색하는 방법이다
def B_bin_search(low, high, Pb) :    
    if low < high-1 :
        B_bin_search.count += 1
        center = int((low + high) / 2)
        
        #print('low {0}: high: {1} center: {2} Pb: {3}'.format(low, high, center, Pb))
        
        if Pb == center :
            return
        else :
            B_bin_search(low, center, Pb)
            B_bin_search(center, high, Pb)
    else :
        return

T = int(input())
for i in range(1, T+1) :
    P, Pa, Pb = map(int, input().split())
    
    # static value in bin_search function
    A_bin_search.count = 0
    B_bin_search.count = 0    
    
    # 각각의 탐색 실행
    A_bin_search(1, P, Pa)
    B_bin_search(1, P, Pb)
    
    # 실행횟수에 따른 승패 결정
    if   A_bin_search.count > B_bin_search.count : answer = 'B'
    elif B_bin_search.count > A_bin_search.count : answer = 'A'
    else : answer = '0'
    
    print('#{0} {1}'.format(i, answer))
        
    
    