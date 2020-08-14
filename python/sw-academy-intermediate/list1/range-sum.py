# input sample 

import sys
sys.stdin = open('sample_input4.txt', 'r')

T = int(input())
for i in range(1, T+1) :
    # N : 정수의 갯수, M : 더할 구간의 크기
    N, M = list(map(int, input().strip().split(' ')))
    num_list = list(map(int, input().strip().split(' ')))

    # 첫 index 0 부터 시작하여 n-(k-1) 까지 반복
    # start부터 M개의 elem들 더하여 sum_list에 넣는다
    sum_list = [sum(num_list[start:start+M]) for start in range(0, len(num_list)-M+1)]
    
    # max - min 을 구함
    max_value = max(sum_list)
    min_value = min(sum_list)

    answer = max_value - min_value
    print("#{0} {1}".format(i, answer))