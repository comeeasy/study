# sudoku.py

import sys
sys.stdin = open('sample.txt', 'r')

# 위치의 클래스를 정의한다.
class loc() :
    def __init__(self, row, column, number) :
        self.row = row
        self.column = column
        self.number = number
        # 빈 후보의 리스트를 할당한다.
        self.candidate = []
        
    def __repr__(self) :
        return '{0}'.format(self.number)

# 해당 loc이 위치하는 3*3 n square 의 숫자들의 list return
def three_by_three_matrix(sudoku, row, column) :
    startRowIdx    = (row // 3) * 3
    startColumnIdx = (column // 3) * 3
    
    return [sudoku[row][column].number for row in range(startRowIdx, startRowIdx+3)
                           for column in range(startColumnIdx, startColumnIdx+3)]

# 해당 loc의 column, row의 list들을 return
def column_list(sudoku, column) :
    return [sudoku[row][column].number for row in range(N)]

def row_list(sudoku, row) :
    return [sudoku[row][column].number for column in range(N)]

# sudoku에서 빈 loc들의 list를 
def get_empty_loc(sudoku) :
    toRet = []
    for row in range(N) :
        for column in range(N) :
            if sudoku[row][column].number == 0 :
                toRet.append(sudoku[row][column])
    
    return toRet

# 비어있는 loc들을 받아서 각 loc의 3*3, column, row list들을 받아서 후보들을 지정한다
def get_candidate(sudoku) :
    emptyList = get_empty_loc(sudoku)
    
    for loc in emptyList :
        existNumbers = sorted(list(set(three_by_three_matrix(sudoku, loc.row, loc.column) + 
                           column_list(sudoku, loc.column) + 
                           row_list(sudoku, loc.row))))
        existNumbers.remove(0)
        
        loc.candidate = [num for num in range(1, 10) if num not in existNumbers]
        print('({0}, {1}), candidate: {2}'.format(loc.row, loc.column, loc.candidate))
    print()
        
# 비어있는 loc이 없다면 모두 찼으므로 게임 종료
def play_sudoku(sudoku) :
    while(get_empty_loc(sudoku)) :
        # 각 loc들에 들어갈 수 있는 숫자들의 후보들을 받아온다
        get_candidate(sudoku)      
        
        # 현재 알고리즘은 단 하나도 단일 후보가 없은 loc이 생기면 무한 루프가 생겨 풀 수 없음
        # 따라서 그런 경우가 생겼을 때 풀 수 없다고 알리고 함수 종료
        
        # 후보가 가장 작은 loc들을 순서대로 불러와서 그 후보들을 차례대로 넣고 백트래킹으로 풀어봐야할거 같다 ㅠㅠ
        if all([True if len(loc.candidate) > 1 else False for loc in get_empty_loc(sudoku)]) :
            print('problem is not solvable')
            return None
            
        for loc in get_empty_loc(sudoku) :
            # 모든 loc.candidate의 크기가 2 이상이라면 당장은 해결할 수 없는 스도쿠이다
            if len(loc.candidate) == 1 :
                loc.number = loc.candidate.pop(0)

def print_sudoku(sudoku) :
    for row in range(N) :
        print(sudoku[row])

# main #######################################################################################
# 스도쿠의 크기      
N = 9

T = int(input())
for testCase in range(1, T+1) :
    # sudoku 입력
    sudoku = []
    for row in range(N) :
        ithRow = list(map(int, list(input())))
        # 스도쿠에 loc들을 삽입
        sudoku.append([loc(row, column, ithRow[column]) for column in range(N)])

    print('=== testCase {0} ==='.format(testCase))
    print('---------- before -------------')
    print_sudoku(sudoku)

    play_sudoku(sudoku)

    print('\n---------- after -------------')
    print_sudoku(sudoku)

#########################################################################################

