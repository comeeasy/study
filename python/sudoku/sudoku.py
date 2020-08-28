# sudoku.py

import sys
from copy import *
sys.stdin = open('sample.txt', 'r')

# 스도쿠의 크기
N = 9

# 위치의 클래스를 정의한다.
class sudoku() :
    def __init__(self, matrix) :
        self.matrix = deepcopy(matrix)

    def print(self) :
        for row in range(len(self.matrix)) :
            print(self.matrix[row])  


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
def three_by_three_matrix(sdk, row, column) :
    startRowIdx    = (row // 3) * 3
    startColumnIdx = (column // 3) * 3
    
    return [sdk[row][column].number for row in range(startRowIdx, startRowIdx+3)
                           for column in range(startColumnIdx, startColumnIdx+3)]

# 해당 loc의 column, row의 list들을 return
def column_list(sdk, column) :
    return [sdk[row][column].number for row in range(N)]

def row_list(sdk, row) :
    return [sdk[row][column].number for column in range(N)]

# sdk에서 빈 loc들의 list를 
def get_empty_loc(sdk) :
    toRet = []
    for row in range(N) :
        for column in range(N) :
            if sdk[row][column].number == 0 :
                toRet.append(sdk[row][column])
    
    return sorted(toRet, key=lambda x: len(x.candidate))

# 비어있는 loc들을 받아서 각 loc의 3*3, column, row list들을 받아서 후보들을 지정한다
def get_candidate(sdk) :
    emptyList = get_empty_loc(sdk)
    
    #print()
    for loc in emptyList :
        existNumbers = sorted(list(set(three_by_three_matrix(sdk, loc.row, loc.column) + 
                           column_list(sdk, loc.column) + 
                           row_list(sdk, loc.row))))
        existNumbers.remove(0)
        
        loc.candidate = [num for num in range(1, 10) if num not in existNumbers]
        #print('({0}, {1}), candidate: {2}'.format(loc.row, loc.column, loc.candidate))
    #print()
        
# 비어있는 loc이 없다면 모두 찼으므로 게임 종료
def play_sdk(sdk) :
    get_candidate(sdk.matrix)
    
    sudokuStack = []
    # 후보들의 숫자들의 크기로 오름차순으로 정렬된 빈 loc들의 list
    # 게임이 끝날 떄까지 
    epmtyLocList = get_empty_loc(sdk)
    sudokuStack.append(sudoku(sdk))
    
    
    
    
            
    

