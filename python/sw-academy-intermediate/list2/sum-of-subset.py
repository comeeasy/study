# 먼저 부분집합을 구하는 bit 조합을 구해야한다
# n: 원소의 갯수
def subset_list(num_list) :
    n = len(num_list)
    to_ret = []

    for numOfSubset in range(0, 1 << n) :
        subset = [num_list[posElemInSubset] for posElemInSubset in range(0, n) 
                                            if numOfSubset & (1 << posElemInSubset)]
        to_ret.append(subset)
        

    return to_ret

import sys
sys.stdin = open('sample_input1.txt', 'r')

T = int(input())
for i in range(1, T+1) :
    A = list(range(1, 13))
    
    # N: 원소의 개수, K: 부분집합의 합
    N, K = map(int, input().strip().split())
    
    # N개의 부분집합을 새로운 list로 저장
    subsets = [subset for subset in subset_list(A) if len(subset) == N]
    # 각 subset의 합을 list에 저장
    sums = [sum(subset) for subset in subsets]
    # 합이 K인 것을 count
    answer = sums.count(K)

    print("#{0} {1}".format(i, answer))