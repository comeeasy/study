# 토너먼트카드게임.py

'''
사다리 게임이 지겨워진 알고리즘 반 학생들이 새로운 게임을 만들었다.
가위바위보가 그려진 카드를 이용해 토너먼트로 한 명을 뽑는 것이다. 게임 룰은 다음과 같다.
 
1번부터 N번까지 N명의 학생이 N장의 카드를 나눠 갖는다. 
전체를 두 개의 그룹으로 나누고, 그룹의 승자끼리 카드를 비교해서 이긴 사람이 최종 승자가 된다.
그룹의 승자는 그룹 내부를 다시 두 그룹으로 나눠 뽑는데, 
i번부터 j번까지 속한 그룹은 파이썬 연산으로 다음처럼 두개로 나눈다.

[입력]
 
첫 줄에 테스트 케이스 개수 T가 주어진다.  1≤T≤50
다음 줄부터 테스트 케이스의 별로 
인원수 N과 다음 줄에 N명이 고른 카드가 번호순으로 주어진다. 4≤N≤100
카드의 숫자는 각각 1은 가위, 2는 바위, 3은 보를 나타낸다.

[출력]
 
각 줄마다 "#T" (T는 테스트 케이스 번호)를 출력한 뒤, 1등의 번호를 출력한다.
'''

# merge sorting 과 같은 원리이다

rock    = 1
scissor = 2
paper   = 3

def play(cards, i, j) :
    if len(cards) == 1 :
        return i
    elif len(cards) == 2 :
        # 작은 번호의 카드가 바위, 가위, 보 인 경우를 나누어 return
        if cards[i] == rock :
            # 동점인 경우 편의상 번호가 작은 카드가 이김
            if cards[j] == rock or cards[j] == scissor :
                return cards[i]
            elif cards[j] == paper :
                return cards[j]
        elif cards[i] == scissor :
            if cards[j] == scissor or cards[j] == paper :
                return cards[i]
            elif cards[j] == rock :
                return cards[j]
        elif cards[i] == paper :
            if cards[j] == paper or cards[j] == rock :
                return cards[i]
            elif cards[j] == scissor :
                return cards[j]
    
def tournament(cards, i, j) :
    if len(cards) < 3 :
        play(cards, i, j)
    else :
        tournament(cards, i, (i+j)//2)
        tournament(cards, (i+j)//2 + 1, j)
    
T = int(input())
for testCase in range(1, T+1) :
    N = int(input())
    cards = list(map(int, input().split()))
    
    
    