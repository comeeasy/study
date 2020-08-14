# -*- cofing : utf-8 -*-
# coloring.py

'''
그림과 같이 인덱스가 있는 10x10 격자에 빨간색과 파란색을 칠하려고 한다.
N개의 영역에 대해 왼쪽 위와 오른쪽 아래 모서리 인덱스, 칠할 색상이 주어질 때, 
칠이 끝난 후 색이 겹쳐 보라색이 된 칸 수를 구하는 프로그램을 만드시오.
주어진 정보에서 같은 색인 영역은 겹치지 않는다.
 
예를 들어 2개의 색칠 영역을 갖는 위 그림에 대한 색칠 정보이다.

3
2
2 2 4 4 1  ( [2,2] 부터 [4,4] 까지 color 1 (빨강) 으로 칠한다 )
3 3 6 6 2 ( [3,3] 부터 [6,6] 까지 color 2 (파랑) 으로 칠한다 )

[입력]
 
첫 줄에 테스트 케이스 개수 T가 주어진다.   ( 1 ≤ T ≤ 50 )
다음 줄부터 테스트케이스의 첫 줄에 칠할 영역의 개수 N이 주어진다. ( 2 ≤ N ≤ 30 )
다음 줄에 왼쪽 위 모서리 인덱스 r1, c1, 오른쪽 아래 모서리 r2, c2와 색상 정보 color가 주어진다. ( 0 ≤ r1, c1, r2, c2 ≤ 9 )

color = 1 (빨강), color = 2 (파랑)

[출력]
 
각 줄마다 "#T" (T는 테스트 케이스 번호)를 출력한 뒤, 답을 출력한다.
'''

# 0으로 가득찬 10 * 10 배열을 생성하고
# 빨간색은 1을 더하고,
# 파란색은 2를 더해서 3이 된 부분을 칸의 수를 더한다

# 값을 파일로 입력 받음
import sys
sys.stdin = open('sample_input0.txt', 'r')

# 맵의 크기는 10 * 10
# color define
red    = 1
blue   = 2
purple = 3

T = int(input())
# 색칠할 영역의 갯수 
for i in  range(1, T+1) :
    # 10 * 10 block 초기화
    block = [[0] * 10 for i in range(10)]
    # 아래 코드로 실행하면 안됨.. 내부적인 작동방식이 * 는 shallow copy
    # 위 코드는 새로운 객체를 메모리에 생성하여 할당하는 방식이라 그런듯
    #block = [[0] * 10] * 10
               
    N = int(input())
    for j in range(N) :
        # r: row, c: column
        leftUp_r, leftUp_c, rightDown_r, rightDown_c, color = list(map(int, input().split()))
        
        for r in range(leftUp_r, rightDown_r+1) :
            for c in range(leftUp_c, rightDown_c+1) :
                # 해당 color를 색칠
                # color == red 일 때, 해당 block이 비어있던거 blue라면 색칠
                
                if color == red :
                    if block[r][c] == 0 or block[r][c] == blue :
                        block[r][c] += red
                # color == blue 일 때, 해당 block이 비어있던거 red라면 색칠 
                else :
                    if block[r][c] == 0 or block[r][c] == red :
                        block[r][c] += blue
                    
    #for i in range(10) :
    #    print(block[i])            
                
    answer = 0
    # 각 row에 대하여 3을 count하여 answer에 더함
    for row in range(10) :
        answer += block[row].count(purple)
    
    # 정답 출력
    print('#{0} {1}'.format(i, answer))
        
     
