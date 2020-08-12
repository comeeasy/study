# -*- coding : utf-8 -*-
# elec-bus.py

'''
A도시는 전기버스를 운행하려고 한다. 전기버스는 한번 충전으로 이동할 
수 있는 정류장 수가 정해져 있어서, 중간에 충전기가 설치된 정류장을 만들기로 했다.
버스는 0번에서 출발해 종점인 N번 정류장까지 이동하고, 한번 충전으로 
최대한 이동할 수 있는 정류장 수 K가 정해져 있다.
충전기가 설치된 M개의 정류장 번호가 주어질 때, 최소한 몇 번의 충전을 
해야 종점에 도착할 수 있는지 출력하는 프로그램을 만드시오.
만약 충전기 설치가 잘못되어 종점에 도착할 수 없는 경우는 0을 출력한다. 
출발지에는 항상 충전기가 설치되어 있지만 충전횟수에는 포함하지 않는다.

[입력]
 
첫 줄에 노선 수 T가 주어진다.  ( 1 ≤ T ≤ 50 )
각 노선별로 K, N, M이 주어지고, 다음줄에 M개의 
정류장 번호가 주어진다. ( 1 ≤ K, N, M ≤ 100 )
 
[출력]

#과 노선번호, 빈칸에 이어 최소 충전횟수 또는 0을 출력한다.
'''

# sample_input2.txt 파일을 읽어들여옴
import sys
sys.stdin = open('sample_input2.txt', 'r')

# count 함수 정의
def count(K, N, M, charger_list) :
    # 처음 location = 0
    cur_loc = 0
    
    # 중간에 충전소가 없더라고 마지막에 
    # 종착점에 도착할 수 있으면 거기서 충전해도 되니까
    # 충전소라고 하자
    charger_list.append(N)
    # 갈 수 있는 모든 충전소를 저장해 가장 큰 수로 이동
    while(cur_loc < N) :
        #print("cur_loc: {0}".format(cur_loc))
        
        next_charger_list = [loc for loc in charger_list if 0 < loc - cur_loc <= K]
        #print("next_charger_list: {0}\ncharger: {1}".format(next_charger_list, charger_list))
        if not next_charger_list :
            return 0
        else :
            cur_loc = max(next_charger_list)
            count.cnt += 1
    
    # 마지막은 항상 종착점에 도착하는데 도착점도 count하므로
    # 이를 하나 빼줘야한다.
    return count.cnt - 1
    

T = int(input())
for line in range(1, T+1) :
    K, N, M = list(map(int, input().split(' ')))
    charger_list = list(map(int, input().split(' ')))
    
    count.cnt = 0
    answer = count(K, N, M, charger_list)
    print("#{0} {1}".format(line, answer))
    