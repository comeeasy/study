# -*- coding : utf-8 -*-
# num-card.py

'''
0에서 9까지 숫자가 적힌 N장의 카드가 주어진다.
가장 많은 카드에 적힌 숫자와 카드가 몇 장인지 
출력하는 프로그램을 만드시오. 카드 장수가 같을 때는 적힌 숫자가 큰 쪽을 출력한다.

[입력]
 
첫 줄에 테스트 케이스 개수 T가 주어진다.  ( 1 ≤ T ≤ 50 )
다음 줄부터 테스트케이스의 첫 줄에 카드 장수 N이 주어진다. ( 5 ≤ N ≤ 100 )
다음 줄에 N개의 숫자 ai가 여백없이 주어진다. (0으로 시작할 수도 있다.)  ( 0 ≤ ai ≤ 9 ) 

[출력]

각 줄마다 "#T" (T는 테스트 케이스 번호)를 출력한 뒤, 
가장 많은 카드의 숫자와 장 수를 차례로 출력한다.
'''
import sys
sys.stdin = open('sample_input3.txt', 'r')

def count_num(nums) :
    count_list = [0] * 10    
    for digit in nums :
        count_list[int(digit)] += 1

    # 역순으로 구해야하므로 index 함수를 사용하면
    # 가장 앞에 있는 element의 index를 return하기 때문에
    # reverse하여 가장 큰 element의 값을 앞으로 가져올거임
    count_list.reverse()
    return count_list

T = int(input())
for i in range(1, T+1) :
    # 카드의 갯수
    N = int(input())
    nums = input()
    
    # 위에서 reverse한 list를 return하므로
    # index도 뒤집어야한다 이를 만들어줌
    digit_index = list(range(9, -1, -1))
    # reverse된 list를 받아옴
    count_list = count_num(nums)
    
    #print("digit_index :", digit_index)
    #print("count_list  :", count_list)
    
    max_value = max(count_list)
    max_digit = digit_index[count_list.index(max_value)]
    
    print("#{0} {1} {2}".format(i, max_digit, max_value))
    