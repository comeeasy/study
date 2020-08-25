# maze.py

'''
NxN 크기의 미로에서 출발지에서 목적지에 도착하는 
경로가 존재하는지 확인하는 프로그램을 작성하시오. 
도착할 수 있으면 1, 아니면 0을 출력한다.

주어진 미로 밖으로는 나갈 수 없다.
 
다음은 5x5 미로의 예이다.
 
13101
10101
10101
10101
10021

마지막 줄의 2에서 출발해서 0인 통로를 따라 이동하면 맨 윗줄의 3에 도착할 수 있는지 확인하면 된다.

[입력]
 
첫 줄에 테스트 케이스 개수 T가 주어진다.  1<=T<=50
다음 줄부터 테스트 케이스의 별로 미로의 크기 N과 
N개의 줄에 걸쳐 미로의 통로와 벽에 대한 정보가 주어진다. 0은 통로, 1은 벽, 2는 출발, 3은 도착이다. 
5<=N<=100

[출력]
 
각 줄마다 "#T" (T는 테스트 케이스 번호)를 출력한 뒤, 계산결과를 정수로 출력하거나 또는 ‘error’를 출력한다.
'''

import sys
sys.stdin = open('sample_input2.txt', 'r')

# structure를 아래와 같이 기술할 수 있다
class loc() :
    def __init__(self, x, y) :
        self.x = x
        self.y = y

def push(stack, item) :
    stack.append(item)

def pop(stack) :
    if not stack :
        return None
    return stack.pop(-1)

T = int(input())
for testCase in range(1, T+1) :
    # N * N 미로가 주어짐
    N = int(input())
    # get maze
    maze = []
    for row in range(N) :
        maze.append(list(input()))
    
    # 탈출구 이거나 더 이상 갈 방향이 없다면
    # 즉 stack이 비었다면 탈출
    
    # 갈 수 있는 방향을 모두 push
    # pop하여 해당 위치로 이동하고 출구인지 확인
    # 출구가 아니라면 해당 위치에서 이동할 수 있는 모든 방향을
    # push
    
    # 북서남동의 순서대로 push
    # 가장 왼쪽의 위가 0, 0
    # column 을 x좌표, row를 y좌표라 생각하겠음 
    
    #(x0, y0) (x1, y0) ... (xN, y0)
    #(x0, y1) (x1, y1) ... (xN, y1)
    #.
    #.
    #(x0, yN) .......      (xN, yN)
    
    dx, dy = [0, -1, 0, 1], [-1, 0, 1, 0]
    
    #print('dx',dx)
    #print('dy', dy)
    
    # 출발점, 도착점 설정
    for x in range(N) :
        for y in range(N) :
            if maze[y][x] == '2' :
                start = (x, y)
            if maze[y][x] == '3' :
                destination = (x, y)
    
    
    #print(start, destination)
    
    stack = []
    push(stack, start)
    # 시작점에 . 지나갔다고 표시
    maze[loc(*start).y][loc(*start).x] = '.'
    
    #print(stack)
    
    while(1) :
        curLoc = pop(stack)
        
        # 출발점이면 탈출 성공
        if curLoc == destination :
            answer = 1
            break
        # curLoc에 아무런 값을 받지 못했다면 다음으로 갈
        # 위치가 없으므로 탈출 불가능
        elif curLoc == None :
            answer = 0
            break
        
        # 탈출점이 아니라면 해당 위치에 방문하였음을 check
        # 다음 위치를 push
        else :
            x = loc(*curLoc).x
            y = loc(*curLoc).y
            
            maze[y][x] = '.'
            
            for i in range(4) :
                if 0 <= x + dx[i] < N and 0 <= y + dy[i] < N \
                    and maze[y+dy[i]][x+dx[i]] != '.'\
                    and maze[y+dy[i]][x+dx[i]] != '1':
                    
                    #print('x+dx, y+dy = {0} {1}'.format(x+dx[i], y+dy[i]))
                    #print('block: {0}'.format(maze[y+dy[i]][x+dx[i]]))
                    push(stack, (x+dx[i], y+dy[i]))
        
        #print(stack)            
                    
                    
        
                    
    print('#{0} {1}'.format(testCase, answer))
            